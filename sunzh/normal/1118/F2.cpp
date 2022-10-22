#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<map>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
const int mod=998244353;
int n,m;
int col[300010];
vector<int>st[300010];
vector<int>vec[300010];
int son[300010],siz[300010];
int top[300010],fa[300010];
int dfn[300010],dep[300010];
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
void dfs1(int x,int f){
	dep[x]=dep[f]+1;fa[x]=f;siz[x]=1;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs1(v,x);siz[x]+=siz[v];
		if(siz[v]>siz[son[x]]) son[x]=v;
	}
}
int idx;
void dfs2(int x,int topf){
	dfn[x]=++idx;top[x]=topf;
	if(son[x]) dfs2(son[x],topf);
	else return ;
	for(int v:vec[x]){
		if(v==fa[x]||v==son[x]) continue ;
		dfs2(v,v);
	}
}
bool covd[2000010];
int cov[2000010];
void cover(int p,int l,int r,int L,int R,int k){
//	printf("L:%d,R:%d,k:%d\n",L,R,k);
	if(cov[p]!=0&&cov[p]!=k){
		printf("0\n");exit(0);
	}
	if(cov[p]==k) return ;
	if(l>=L&&r<=R){
		cov[p]=k;covd[p]=1;return ;
	}
	int mid=l+r>>1;
	if(L<=mid) cover(p<<1,l,mid,L,R,k);
	if(R>mid) cover(p<<1|1,mid+1,r,L,R,k); 
}
void cover(int x,int y,int k){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		cover(1,1,n,dfn[top[x]],dfn[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	cover(1,1,n,dfn[x],dfn[y],k);
}
int belong[300010];
int query(int p,int l,int r,int pos,int k){
//	printf("p:%d,l:%d,r:%d,pos:%d,cov:%d,k:%d\n",p,l,r,pos,cov[p],k);
	if(cov[p]){
		if(k==0) k=cov[p];
		else if(k!=cov[p]){
			printf("0\n");exit(0);
		}
	}
	if(l==r) return k;
	int mid=l+r>>1;
	if(pos<=mid) return query(p<<1,l,mid,pos,k);
	else return query(p<<1|1,mid+1,r,pos,k);
}
map<PII,bool>Map;
vector<int>Vec[300010];
int dp[300010][2];
int qpow(int x,int k=mod-2){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;k>>=1;
	}
	return res;
}
void getans(int x,int f){
	vector<int>sn;
	for(int v:Vec[x]){
		if(v==f) continue ;
		getans(v,x);
		if(dp[v][1]>0) sn.pb(v);
	}
	if(sn.empty()){
		if(x<=m) dp[x][1]=1;
		else dp[x][0]=1;return ;
	}
	#define v sn[i]
	if(x<=m){
		dp[x][1]=1;
		for(int i=0;i<sn.size();++i) dp[x][1]=1ll*dp[x][1]*(dp[v][0]+dp[v][1])%mod;
	}
	else{
		dp[x][1]=0,dp[x][0]=1;
		for(int i=0;i<sn.size();++i) dp[x][0]=1ll*dp[x][0]*(dp[v][0]+dp[v][1])%mod;
		for(int i=0;i<sn.size();++i){
			(dp[x][1]+=1ll*dp[x][0]*qpow((dp[v][0]+dp[v][1])%mod)%mod*dp[v][1]%mod)%=mod;
		}
	}
	#undef v
//	printf("x:%d,%d %d\n",x,dp[x][0],dp[x][1]);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) col[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v),vec[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=n;++i) st[col[i]].pb(i);
	for(int i=1;i<=m;++i){
		sort(st[i].begin(),st[i].end(),cmp);
		if(st[i].size()==1){
			cover(1,1,idx,dfn[st[i][0]],dfn[st[i][0]],i);
		} 
		for(int j=0;j<st[i].size()-1;++j){
			cover(st[i][j],st[i][j+1],i);
		}
	}
	int cnt=m;
	for(int i=1;i<=n;++i){
		belong[i]=query(1,1,n,dfn[i],0);
		if(belong[i]==0) belong[i]=++cnt;
//		printf("belong[%d]=%d\n",i,belong[i]);
	}
	for(int i=1;i<=n;++i){
		int bi=belong[i];
		for(int v:vec[i]){
			int bv=belong[v];
			if(bv==bi) continue ;
			if(Map.count(mp(bi,bv))) continue ;
			Map[mp(bi,bv)]=Map[mp(bv,bi)]=1;
			Vec[bv].pb(bi);Vec[bi].pb(bv);
		} 
	}
	getans(1,0);
	printf("%d\n",dp[1][1]);
}