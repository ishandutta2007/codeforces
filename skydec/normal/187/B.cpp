#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(i=(j);i<=(k);i++)
#define per(i,j,k) for(i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int f[65][65][65];
int g[65][65][65];
int n,m,q,i,j,k,T;
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	rep(k,1,m){
		rep(i,1,n)rep(j,1,n)scanf("%d",&g[k][i][j]);
		rep(T,1,n)rep(i,1,n)rep(j,1,n)g[k][i][j]=min(g[k][i][T]+g[k][T][j],g[k][i][j]);
	}
	memset(f,63,sizeof f);
	rep(i,1,n)
	rep(j,1,n)
	{
		f[0][i][j]=g[1][i][j];
		rep(T,2,m)f[0][i][j]=min(f[0][i][j],g[T][i][j]);
	}
	rep(T,1,n)
	rep(k,1,n)
	rep(i,1,n)
	rep(j,1,n)
	f[T][i][j]=min(f[T][i][j],f[T-1][i][k]+f[0][k][j]);
	while(q--){
		int s,t,c;scanf("%d%d%d",&s,&t,&c);c=min(c,n);
		printf("%d\n",f[c][s][t]);
	}
	return 0;
}