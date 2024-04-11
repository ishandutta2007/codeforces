#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,q;
vector<int>vec[100010];
int a[100010],c[100010];
vector<int>vecx[100010];
int depth[500010];
int tin[100010],idx;
int minn[200010][20],pos[200010][20];
int ans;
const int mod=1e9+7;
bool vis[100010]; 
int stk[100010];
int top;
int anc[100010];
int cnt;
int dfn[100010];
int dp[100010][310];
void dfs1(int x,int f){
	tin[x]=++idx;depth[x]=depth[f]+1;
	minn[idx][0]=depth[x],pos[idx][0]=x;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs1(v,x);
		minn[++idx][0]=depth[x],pos[idx][0]=x;
	}
}
int query(int l,int r){
	if(l>r) swap(l,r);
	int k=log2(r-l+1);
	if(minn[l][k]<=minn[r-(1<<k)+1][k]) return pos[l][k];
	else return pos[r-(1<<k)+1][k];
}
int LCA(int x,int y){
	return query(tin[x],tin[y]);
}
bool cmp(int x,int y){
	return tin[x]<tin[y];
}
bool cmp2(int x,int y){
	return dfn[x]<dfn[y];
}
void ins(int x){
	vecx[x].clear();
	if(!top){
		stk[++top]=x;return ;
	}
	int p=LCA(x,stk[top]);
	if(p==stk[top]){
		stk[++top]=x;return ;
	}
	while(top>1&&tin[stk[top-1]]>=tin[p]){
		vecx[stk[top-1]].pb(stk[top]);
		vecx[stk[top]].pb(stk[top-1]);
		--top;
	}
	if(p!=stk[top]){
		vecx[p].clear();
		vecx[p].pb(stk[top]);
		vecx[stk[top]].pb(p);
		stk[top]=p;
	}
	stk[++top]=x;
}
void dfs2(int x,int f,int k){
	anc[x]=k;dfn[x]=++cnt;
	for(int v:vecx[x]){
		if(v==f) continue ;
		dfs2(v,x,k+vis[x]);
	}
}
int main(){
	n=read(),q=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
	}
	dfs1(1,0);
	for(int j=1;j<=18;++j){
		for(int i=1;i+(1<<j)-1<=idx;++i){
			if(minn[i][j-1]>minn[i+(1<<j-1)][j-1]){
				minn[i][j]=minn[i+(1<<j-1)][j-1];
				pos[i][j]=pos[i+(1<<j-1)][j-1];
			}
			else{
				minn[i][j]=minn[i][j-1];
				pos[i][j]=pos[i][j-1];
			}
		}
	}
	while(q--){
		int k=read(),m=read(),rt=read();
		for(int i=1;i<=k;++i) a[i]=read(),vis[a[i]]=1,c[i]=a[i];
		c[k+1]=rt;
		sort(c+1,c+k+2,cmp);
		int d=unique(c+1,c+k+2)-c-1;
		ans=0;
		top=0;cnt=0;
		for(int i=1;i<=d;++i) ins(c[i]);
		while(top>1){
			vecx[stk[top-1]].pb(stk[top]),vecx[stk[top]].pb(stk[top-1]);--top;
		}
		dfs2(rt,0,0);
		sort(a+1,a+k+1,cmp2);
		dp[a[0]][0]=1;
		for(int i=1;i<=k;++i){
			for(int j=1;j<=m;++j){
				dp[a[i]][j]=(1ll*dp[a[i-1]][j]*max(0,j-anc[a[i]])%mod+dp[a[i-1]][j-1])%mod;
				if(i==k) (ans+=dp[a[i]][j])%=mod;
			}
		}
		for(int i=1;i<=k;++i) vis[a[i]]=0;
		printf("%d\n",ans);
	}
}