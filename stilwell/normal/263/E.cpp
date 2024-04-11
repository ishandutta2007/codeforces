#include <stdio.h>
#include <stdlib.h>
#define x i+j-1
#define y i-j+m
using namespace std;

int N,n,m,K,i,j,k,ansx,ansy;
long long sum[2005][2005],now,ans;

char ch;
void read(int &X)
{
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for(X=0;ch>='0'&&ch<='9';ch=getchar())X=X*10+ch-'0';
}

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	read(k),sum[i+j-1][i-j+m]+=k;
	N=n+m-1;
	for(i=1;i<=N;++i)
	{
		for(j=1;j<=N;++j)sum[i][j]+=sum[i][j-1];
		for(j=1;j<=N;++j)sum[i][j]+=sum[i-1][j];
	}
	for(i=K;i<=n-K+1;++i)
	for(j=K;j<=m-K+1;++j)
	{
		now=0;
		for(k=0;k<K;++k)
		now+=sum[x+k][y+k]-sum[x-k-1][y+k]-sum[x+k][y-k-1]+sum[x-k-1][y-k-1];
		if(now>=ans)ans=now,ansx=i,ansy=j;
	}
	printf("%d %d\n",ansx,ansy);
}