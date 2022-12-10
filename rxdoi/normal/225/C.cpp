#include<cstdio>
#include<cctype>
#include<cstring>
#include<iostream>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=1000+19;
int f[N][N][2],A[N][2],n,m,x,y,Ans=(1<<30)-1;
char s[N][N];

void U(int &a,int b) {a=a<b?a:b;}

int main()
{
	n=IN(),m=IN(),x=IN(),y=IN();
	For(i,1,n+1) scanf("%s",s[i]+1);
	For(i,1,n+1) For(j,1,m+1) if (s[i][j]=='#') A[j][0]++;
	For(i,1,m+1) A[i][1]=n-A[i][0];
	memset(f,60,sizeof(f));
	f[1][1][0]=A[1][0],f[1][1][1]=A[1][1];
	For(i,1,m) For(j,1,i+1) For(k,0,2)
	{
		if (j+1<=y) U(f[i+1][j+1][k],f[i][j][k]+A[i+1][k]);
		if (x<=j&&j<=y) U(f[i+1][1][k^1],f[i][j][k]+A[i+1][k^1]);
	}
	For(i,x,y+1) For(j,0,2) Ans=min(Ans,f[m][i][j]);
	printf("%d\n",Ans);
}