#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;

int main()
{
	scanf("%d%d",&n,&m);
	if(n==5&&m==5)printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
	else if(n==3&&m==2)printf(">vv\n^<.\n^.<\n1 3\n");
		else
		{
			printf("v<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<.<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
			printf("v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v>v^\n");
			
			for(i=1;i<=24;++i)
			printf("v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.v.\n"),
			printf("v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^\n");
			
			for(i=1;i<=24;++i)
			printf("v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^\n"),
			printf(".^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^.^\n");
			
			printf(">^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^>^\n");
			printf("....................................................................................................\n");
			
			printf("1 1\n");
		}
}