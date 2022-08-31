#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int P=998244353;
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
const int N=160000;
vector<int> go[N];
int n,Q;
int fa[N],sz[N],bg[N],top[N],q[N];
int dfn[N],ed[N],dftot,idx[N];
void dfs(int x){
	dfn[x]=++dftot;idx[dftot]=x;
	for(int y:go[x])if(fa[y]==x){
		dfs(y);
	}
	ed[x]=dftot;
}
int invn;
int dd[N];
int cnt[N];
void add(int x,int v){
	for(;x<=n;x+=(x&(-x)))cnt[x]=(cnt[x]+v)%P;
}
int ask(int x){
	int ans=0;
	for(;x;x-=(x&(-x)))ans=(ans+cnt[x])%P;
	return ans;
}
void quadd(int l,int r,int d){
	add(l,d);
	add(r+1,(P-d)%P);
}
void gkd(int x,int d){
	int w=(d*1ll*sz[x]%P)*1ll*invn%P;
	quadd(1,n,w);
	quadd(dfn[x],ed[x],(P-w)%P);
	dd[x]=(dd[x]+d)%P;

	if(bg[x]){
		int y=bg[x];
		w=(d*1ll*(n-sz[y])%P)*1ll*invn%P;
		quadd(dfn[y],ed[y],w);
	}
}
int query(int x){
	int ans=(ask(dfn[x])+dd[x])%P;
	for(x=top[x];x;x=top[fa[x]]){
		if(!fa[x])break;
		int res=(n-sz[x])*1ll*invn%P;
		res=res*1ll*dd[fa[x]]%P;
		ans=(ans+res)%P;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&Q);
	invn=Pow(n,P-2);
	rep(i,1,n-1){
		int a,b;scanf("%d%d",&a,&b);
		go[a].pb(b);
		go[b].pb(a);
	}
	q[q[0]=1]=1;
	rep(i,1,q[0]){
		int x=q[i];
		for(int y:go[x])if(y^fa[x]){
			fa[y]=x;q[++q[0]]=y;
		}
	}
	per(i,q[0],1){
		int x=q[i];
		sz[x]=1;
		for(int y:go[x])if(fa[y]==x){
			sz[x]+=sz[y];
			if(sz[y]>sz[bg[x]])bg[x]=y;
		}
	}
	rep(i,1,q[0]){
		int x=q[i];
		if(!fa[x])top[x]=x;
		else{
			if(bg[fa[x]]!=x)top[x]=x;
			else top[x]=top[fa[x]];
		}
	}
	//rep(i,1,n)printf("__%d %d\n",i,top[i]);
	dfs(1);
	while(Q--){
		int ty;scanf("%d",&ty);
		if(ty==1){
			int x,d;scanf("%d%d",&x,&d);
			gkd(x,d);
		}
		if(ty==2){
			int x;scanf("%d",&x);
			printf("%d\n",query(x));
		}
	}
	return 0;
}