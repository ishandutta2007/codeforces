#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 410000
struct E{int u,v,w,de;}e[MAXN];
vector<int> a[MAXN];
int c[MAXN];int q[MAXN];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		e[i].de=-1;
		c[e[i].u]+=e[i].w;
		c[e[i].v]+=e[i].w;
		a[e[i].u].pb(i);
		a[e[i].v].pb(i);
	}
	rep(i,1,n)c[i]/=2;
	q[0]=1;q[1]=1;
	for(int i=1;i<=q[0];i++){
		int x=q[i];
		for(int j=0;j<a[x].size();j++)
		if(e[a[x][j]].de==-1)
		{
			int u=e[a[x][j]].u;
			int v=e[a[x][j]].v;
			int w=e[a[x][j]].w;
			int to=(u^v^x);
			c[to]-=w;
			
			if(u==x)e[a[x][j]].de=0;
			else e[a[x][j]].de=1;
			
			if(c[to]==0&&to!=n)q[++q[0]]=to;
		}
	}
	rep(i,1,m)printf("%d\n",e[i].de);
	return 0;
}