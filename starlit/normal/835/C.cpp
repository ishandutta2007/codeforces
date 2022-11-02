#include<cstdio>
#include<iostream>
#include<cstring>
#define X 101
#define ll long long
using namespace std;
ll n,q,c,x,y,x_,y_,s,ans;
ll sum[X][X],ssum[X][X],msum[X][X][11];
int main()
{
	scanf("%lld%lld%lld",&n,&q,&c);c++;
	while(n--)
	{
		scanf("%lld%lld%lld",&x,&y,&s);
		ssum[x][y]+=s,sum[x][y]++;
		for(int i=1;i<c;i++)
		if(s+i>=c)msum[x][y][i]++;
	}
	for(int i=1;i<X;i++)
	for(int j=1;j<X;j++)
	{
		ssum[i][j]+=ssum[i][j-1]+ssum[i-1][j]-ssum[i-1][j-1];
		sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
		for(int k=1;k<c;k++)
		msum[i][j][k]+=msum[i][j-1][k]+msum[i-1][j][k]-msum[i-1][j-1][k];
	}
	while(q--)
	{
		scanf("%lld%lld%lld%lld%lld",&s,&x,&y,&x_,&y_);x--,y--;
		s%=c;
		ans=ssum[x_][y_]-ssum[x_][y]-ssum[x][y_]+ssum[x][y];
		ans-=c*(msum[x_][y_][s]-msum[x_][y][s]-msum[x][y_][s]+msum[x][y][s]);
		ans+=s*(sum[x_][y_]-sum[x_][y]-sum[x][y_]+sum[x][y]);
		printf("%lld\n",ans);
	}
}
/*
1 1 3
1 1 1
2 1 1 2 2
*/