#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s[9][9];
int x,y;
int xx,yy;

int main()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
				scanf("%s",s[i*3+j]+k*3);
	scanf("%d%d",&x,&y);
	x--;y--;
	xx=x%3;
	yy=y%3;
	bool isempty=0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(s[xx*3+i][yy*3+j]=='.')isempty=1;
	if(!isempty)
	{
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
				if(s[i][j]=='.')
					s[i][j]='!';
	}
	else
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				if(s[xx*3+i][yy*3+j]=='.')s[xx*3+i][yy*3+j]='!';
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				for(int l=0;l<3;l++)printf("%c",s[i*3+j][k*3+l]);
				printf(" ");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}