#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=1510000;
int head[N],p[N],np[N],id[N];int tot=1;
int n,m;int a[N];int l[N],r[N];bool vis[N];int top;int stack[N];int du[N];int ans[N];
inline void link(int u,int v,int co){
	tot++;p[tot]=v;np[tot]=head[u];head[u]=tot;id[tot]=co;
	tot++;p[tot]=u;np[tot]=head[v];head[v]=tot;id[tot]=co;
	du[u]++;du[v]++;
}
void dfs(int x){
 	for(int u=head[x];u;u=np[u])if(!vis[u]){
 		vis[u]=vis[u^1]=1;
 		dfs(p[u]);
 		stack[++top]=u;
 	}
 }
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&l[i],&r[i]);
		l[i]--;
		a[++m]=l[i];a[++m]=r[i];
	}
	a[++m]=2000000000;
	sort(a+1,a+1+m);
	rep(i,1,n){
		l[i]=lower_bound(a+1,a+1+m,l[i])-a;
		r[i]=lower_bound(a+1,a+1+m,r[i])-a;
		link(l[i]+1,r[i]+1,i);
	}
	int now=1;int en=m;
	rep(i,1,m)if(du[i]&1){
		if(now<i+1)now=i+1;
		for(;now<=m&&du[now]%2==0;now++);
		en++;link(i,en,0);link(en,now,0);
	}
	rep(i,1,m){
		top=0;
		dfs(i);
		rep(j,1,top)ans[id[stack[j]]]=stack[j]&1;
	}
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}