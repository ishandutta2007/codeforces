#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MX 505

char s[MX];
int changes[MX][MX];
int n;

int ansMn[MX][MX];
int ansMnI[MX][MX];

void pre()
{
	n = strlen(s);
	
	//puts(s);
	
	for(int i=0;i<n;i++)
	{
		changes[i][i] = 0;
		for(int x=i-1,y=i+1;x>=0 && y<n;x--,y++)
			changes[x][y] = changes[x+1][y-1] + (s[x]!=s[y]);
			
		changes[i][i+1] = s[i]!=s[i+1];
		for(int x=i-1,y=i+2;x>=0 && y<n;x--,y++)
			changes[x][y] = changes[x+1][y-1] + (s[x]!=s[y]);
	}
	
	/*
	for(int i=0;i<n;i++,puts(""))
	{
		for(int j=0;j<n;j++)
			printf("%2d ",changes[i][j]);
	}
	puts("--------------------");
	*/
}

int getMin(int x,int k)
{
	if(x>=n) return 0;
	if(k<=0) return n+1;
	if(ansMn[x][k]>=0) return ansMn[x][k];
	int mn = n+1, mni = -1;
	for(int i=x;i<n;i++)
	{
		int cv = changes[x][i] + getMin(i+1,k-1);
		//if(x==0) printf("%d, %d : %d --> %d\n",x,k,i,cv);
		if(cv<mn){ mn=cv; mni=i; }
	}
	ansMnI[x][k] = mni;
	//printf("%d, %d --> %d\n",x,k,ansMn[x][k]);
	return ansMn[x][k] = mn;
}

int main()
{
	int k;
	scanf("%s %d",s,&k);
	pre();
	memset(ansMn,-1,sizeof ansMn);
	printf("%d\n",getMin(0,k));
	//return 0;
	int ci = 0;
	while(ci<n)
	{
		for(int i=ci;i<=ansMnI[ci][k];i++) putchar(min(s[i],s[ansMnI[ci][k]-(i-ci)]));
		ci = ansMnI[ci][k--] + 1;
		if(ci<n) putchar('+');
	}
	puts("");
	return 0;
}