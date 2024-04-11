#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int f[205][205];
struct edge{
	int a,b,v;
}w[205*205];
pii node[205];
int n,m;
int main(){
	memset(f,63,sizeof f);
	scanf("%d%d",&n,&m);
	rep(i,1,n)f[i][i]=0;
	rep(i,1,m){
		scanf("%d%d%d",&w[i].a,&w[i].b,&w[i].v);
		f[w[i].a][w[i].b]=w[i].v;
		f[w[i].b][w[i].a]=w[i].v;
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int Res=f[0][0];
	rep(i,1,m){
		rep(j,1,n)node[j]=(pii){f[j][w[i].a],f[j][w[i].b]};
		sort(node+1,node+1+n);
		int Max=node[n].se;int ans=node[n].fi*2;
		per(j,n-1,1){
			if(node[j].se>Max)ans=min(ans,Max+node[j].fi+w[i].v);
			Max=max(Max,node[j].se);
		}
		ans=min(ans,Max*2);
		Res=min(Res,ans);
	}
	if(Res&1)printf("%d.5",Res/2);
	else printf("%d\n",Res/2);
	return 0;
}