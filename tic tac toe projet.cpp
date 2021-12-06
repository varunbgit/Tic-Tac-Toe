#include<bits/stdc++.h>

using namespace std;

//tic tac toe

char** createboard(int n=3)
{
	char** board=new char*[n];
	
	for(int i=0;i<n;i++)
	{
		char* board= new char[n];
	}
	 for(int i=0;i<n;i++)
	 {
	 	for(int j=0;j<n;j++)
	    {
	        board[i][j]='0'; 	
	    }
	 
	 }
	 return board;
}

void getsize(int *p)
{
	cout<<"enter the size of board";
	cin>>*p;	
}

void getplayer(char playerid[])
{
	cout<<"enter the name of playter 1";
	cin>>playerid[0];
	cout<<"enter the name of playter 2";
    cin>>playerid[1];
}

void choiceofplayer(int &x,int &y,int n)
{
	int c;
	cin>>c;
	x=c/n;
	y=c%n;
}

int checkwin(char** board,int n,int turn)
{
	for(int i=0;i<n;i++)
	{
		char rowval=board[i][0];
		int rowmatch=1;
		
		char colval=board[0][i];
		int colmatch=1;
		
		for(int j=0;j<n;j++)
	{
		if(board[i][j]==rowval)
		rowmatch++;
		
		if(board[i][j]==colval)
		colmatch++;
		
	}
	
	     if(rowmatch==n||colmatch==n)
	     return turn;
	}
	
	char leftd=board[0][0];
		int ldmatch=1;
		
		char rightd=board[n-1][0];
		int rdmatch=1;
		
		for(int i=0;i<n;i++)
		{
			if(board[i][i]==leftd)
			ldmatch++;
			
			if(board[n-i-1][i]==rightd)
			rdmatch++;
		}
		
		if(rdmatch==n||ldmatch==n)
	     return turn;
        return -1;
        
}

void rungame(char** board,int n,char* playername[2])
{
	char weapon[2]={'x','o'};
	int playerturn=0;
	int round=0;
	
	while(round<9)
	{
		
	playerturn=playerturn?0:1;
	
	int x,y;
	
	cout<<playername[playerturn]<<"ur turn  ";
	 
	 
	 choiceofplayer(&x,&y,n);
	  
	  
	    board[x][y]=weapon[playerturn];
		
		int winner=checkwin(board,n,playerturn)	;
	     
	     if(winner!=-1)
	     cout<<"winner is "<<playername[winner];
	     exit(0);  
	     
	     round++;
	}
	cout<<"issa draw !";
}




int main()

{
	int n; 
	getsize(&n);

	char playername[2];
	
	getplayer(&playername[2]);
	
    char** board=createboard(n);
	 	
	rungame(&board,&n,&playername[2]);
}


