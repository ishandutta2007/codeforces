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
const int N=70000;
int l[N],r[N],fa[N];
int n,m;
LL ans=0;
struct mes{
	LL sumS;int sz;int xu;LL xuS;LL dui;
}a[N],val[N];
inline mes operator +(const mes &a,const mes &b){
	mes c;
	c.sumS=a.sumS+b.sumS;
	c.sz=a.sz+b.sz;
	c.xu=a.xu+b.xu;
	c.xuS=a.xuS+b.xuS;
	return c;
}
inline bool top(int x){return (!fa[x])||(l[fa[x]]!=x&&r[fa[x]]!=x);}
inline void up(int x){
	a[x]=val[x];
	if(l[x])a[x]=a[x]+a[l[x]];
	if(r[x])a[x]=a[x]+a[r[x]];
}
inline void left(int x){
	int y=fa[x];int z=fa[y];
	r[y]=l[x];if(l[x])fa[l[x]]=y;
	fa[x]=z;if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;
	fa[y]=x;l[x]=y;up(y);up(x);
}
inline void right(int x){
	int y=fa[x];int z=fa[y];
	l[y]=r[x];if(r[x])fa[r[x]]=y;
	fa[x]=z;if(l[z]==y)l[z]=x;else if(r[z]==y)r[z]=x;
	fa[y]=x;r[x]=y;up(y);up(x);
}
inline void splay(int x){
	while(!top(x)){
		int y=fa[x];int z=fa[y];
		if(top(y)){
			if(l[y]==x)right(x);else left(x);
		}
		else{
			if(r[z]==y){
				if(r[y]==x)left(y),left(x);
				else right(x),left(x);
			}
			else{
				if(l[y]==x)right(y),right(x);
				else left(x),right(x);
			}
		}
	}
}
int getL(int x){while(l[x])x=l[x];return x;}
inline int access(int x){
	int y=0;
	for(;x;y=x,x=fa[x]){
		splay(x);
		int rx=r[x];
		r[x]=0;
		if(rx){
			rx=getL(rx);
			splay(rx);
			val[x].xu+=a[rx].xu+a[rx].sz;
			val[x].dui+=(a[rx].xu+a[rx].sz)*1ll*(a[rx].xu+a[rx].sz);
			val[x].xuS=val[x].xu*1ll*val[x].sumS;
			up(x);
		}
		if(y){
			splay(y);
			val[x].xu-=a[y].xu+a[y].sz;
			val[x].xuS=val[x].xu*1ll*val[x].sumS;
			val[x].dui-=(a[y].xu+a[y].sz)*1ll*(a[y].xu+a[y].sz);
			r[x]=y;
			up(x);
		}
	}
	return y;
}
int p[N];
vector<int>son[N];
void dfs(int x){
	val[x].sz=1;ans+=val[x].sumS;
	for(vector<int>::iterator it=son[x].begin();it!=son[x].end();it++){
		dfs(*it);
		ans+=val[x].sz*2ll*val[*it].sz*val[x].sumS;
		val[x].xu+=val[*it].sz;
		val[x].sz+=val[*it].sz;
		val[x].dui+=val[*it].sz*1ll*val[*it].sz;
		fa[*it]=x;
	}
	val[x].xuS=val[x].xu*1ll*val[x].sumS;
}
void duan(int x){
	access(p[x]);
	int v=p[x];
	splay(x);fa[x]=0;
	p[x]=0;
	
	int SS=a[x].sz+a[x].xu;
	splay(v);
	
	val[v].dui-=SS*1ll*SS;
	val[v].xu-=SS;
	val[v].xuS=val[v].xu*1ll*val[v].sumS;
	
	up(v);
	ans-=a[v].xuS*2ll*SS;
	ans-=a[v].sumS*2ll*SS;
}
void lian(int x,int v){
	access(x);
	access(v);
	splay(x);splay(v);fa[x]=v;p[x]=v;
	
	int SS=a[x].sz+a[x].xu;
	ans+=a[v].xuS*2ll*SS;
	ans+=a[v].sumS*2ll*SS;
	
	val[v].dui+=1ll*SS*SS;
	val[v].xu+=SS;
	val[v].xuS=val[v].xu*1ll*val[v].sumS;
	up(v);
}
int main(){
	scanf("%d",&n);
	rep(i,2,n){
		scanf("%d",&p[i]);
		son[p[i]].pb(i);
	}
	rep(i,1,n){
		scanf("%I64d",&val[i].sumS);
	}
	dfs(1);
	rep(i,1,n){val[i].sz=1;up(i);}
	
	scanf("%d",&m);
	while(m--){
		printf("%.10lf\n",ans/(1.*n*n));
		char opt[3];scanf("%s",opt+1);
		if(opt[1]=='P'){
			int u,v;scanf("%d%d",&v,&u);
			access(u);
			int lca=access(v);
			if(lca==v){
				duan(u);
				lian(u,v);
			}
			else{
				duan(v);
				lian(v,u);
			}
		}
		else{
			int u,v;scanf("%d%d",&u,&v);
			access(u);splay(u);
			int del=v-val[u].sumS;
			val[u].sumS=v;
			val[u].xuS=val[u].sumS*1ll*val[u].xu;
			up(u);
			
			ans+=1ll*del*((1+val[u].xu)*1ll*(1+val[u].xu)-val[u].dui);
		}
	}
	printf("%.10lf\n",ans/(1.*n*n));
	return 0;
}