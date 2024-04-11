#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=1010000;
int head[N],np[N],p[N],tot;
int dep[N],fa[N],dfn[N],ed[N],dftot;
int bel[N],size[N],bg[N],ltot,top[N];
int n;
int rt;
void dfsdfn(int x){
	dfn[x]=++dftot;
	if(bg[x])dfsdfn(bg[x]);
	for(int u=head[x];u;u=np[u])if(p[u]^fa[x])if(p[u]^bg[x])dfsdfn(p[u]);
}
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	size[x]=1;
	for(int u=head[x];u;u=np[u])if(p[u]^fa[x]){
		fa[p[u]]=x;dfs(p[u]);
		size[x]+=size[p[u]];
		if(size[p[u]]>size[bg[x]])bg[x]=p[u];
	}
	if(size[x]==1){
		bel[x]=++ltot;
	}
	else{
		bel[x]=bel[bg[x]];
		for(int u=head[x];u;u=np[u])if(p[u]^fa[x])if(p[u]^bg[x])top[bel[p[u]]]=p[u];
	}
}
int id[N];
LL ans[N];
inline bool cmp(const int &x,const int &y){
	return dep[x]<dep[y];
}
LL pr[N];
int sf[N];
int sfall=0;
void cntadd(int x,int v){
	LL d=x*1ll*v;
	sfall+=v;
	for(;x<=n;x+=(x&(-x))){
		//printf("_%d\n",x);
		sf[x]+=v;
		pr[x]+=d;
	}
}
LL cntask(int x){
	LL ans=0;
	int d=sfall;
	int xx=x;
	for(;x;x-=(x&(-x))){
		//printf("%d\n",x);
		ans+=pr[x];
		d-=sf[x];
	}
	return ans+d*1ll*xx;
}
void cadd(int l,int r){
	if(l-1)cntadd(l-1,-1);
	cntadd(r,1);
}
LL cask(int l,int r){
	return cntask(r)-cntask(l-1);
}
void addit(int x){
	while(x){
		//printf("%d\n",x);
		cadd(dfn[top[bel[x]]],dfn[x]);
		x=fa[top[bel[x]]];
	}
}
LL askit(int x){
	LL ans=0;
	while(x){
		//printf("_%d\n",x);
		ans+=cask(dfn[top[bel[x]]],dfn[x]);
		x=fa[top[bel[x]]];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		int x;scanf("%d",&x);
		if(!x){
			rt=i;
			continue;
		}
		++tot;p[tot]=i;np[tot]=head[x];head[x]=tot;
	}
	dfs(rt);top[bel[rt]]=rt;

	dfsdfn(rt);

	rep(i,1,n)id[i]=i;
	sort(id+1,id+1+n,cmp);
	rep(l,1,n){
		int r=l;
		while(r<n&&dep[id[r+1]]==dep[id[l]])++r;
		rep(k,l,r){
			if(fa[id[k]])addit(fa[id[k]]);
		}
		rep(k,l,r){
			ans[id[k]]=askit(id[k]);
		}
		l=r;
	}

	rep(i,1,n)printf("%I64d%c",ans[i],i==n?'\n':' ');
	return 0;
}