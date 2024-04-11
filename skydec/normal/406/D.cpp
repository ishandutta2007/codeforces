#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
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
const int MAXN=210000;
db x[MAXN],y[MAXN];int n;int root;
int fa[22][MAXN];vector<int>p[MAXN];int dep[MAXN];
int q[MAXN];int top;
void dfs(int a){
	dep[a]=dep[fa[0][a]]+1;
	rep(i,0,S(p[a])-1)dfs(p[a][i]);
}
int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	per(i,20,0)if((1<<i)&(dep[a]-dep[b]))a=fa[i][a];
	if(a==b)return a;
	per(i,20,0)if(fa[i][a]!=fa[i][b]){
		a=fa[i][a];b=fa[i][b];
	}
	return fa[0][a];
}
db cha(db x0,db y0,db x1,db y1,db x2,db y2){
	x1-=x0;y1-=y0;x2-=x0;y2-=y0;
	return x1*y2-x2*y1;
}
int main(){
	scanf("%d",&n);root=n;
	rep(i,1,n){
		LL x1,y1;scanf("%I64d%I64d",&x1,&y1);
		x[i]=1.*x1;y[i]=1.*y1;
	}
	q[top=1]=n;
	per(i,n-1,1){
		while(top>1&&cha(x[i],y[i],x[q[top]],y[q[top]],x[q[top-1]],y[q[top-1]])>0)top--;
		fa[0][i]=q[top];p[q[top]].pb(i);q[++top]=i;
	}
	dfs(root);
	rep(j,1,20)rep(i,1,n)fa[j][i]=fa[j-1][fa[j-1][i]];
	int q;scanf("%d",&q);
	while(q--){
		int a,b;scanf("%d%d",&a,&b);
		printf("%d ",lca(a,b));
	}
	return 0;
}