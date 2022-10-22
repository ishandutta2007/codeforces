#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
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
int n;
std::vector<int>vec[1000010];
std::vector<int>dp[1000010];
std::vector<int>mxdep(1000010),son(1000010);
void dfs1(int x,int fa){
	mxdep[x]=mxdep[fa]+1;
	for(int v:vec[x]){
		if(v==fa) continue ;
		dfs1(v,x);
		if(mxdep[v]>mxdep[son[x]]) son[x]=v;
	}
	for(int v:vec[x]){
		if(v==fa) continue ;mxdep[x]=std::max(mxdep[v],mxdep[x]);
	}
}
int ans[1000010];
void dfs2(int x,int fa){
	int mxn=0,pos=0;
	if(son[x]){
		dfs2(son[x],x);
		dp[x]=std::move(dp[son[x]]);
		pos=ans[son[x]]+1;mxn=dp[x][dp[x].size()-ans[son[x]]-1];
	}
	else{
		dp[x].pb(1);ans[x]=0;
		return ;
	}
	for(int v:vec[x]){
		if(v==fa||v==son[x]) continue ;
		dfs2(v,x);
		for(int j=1;j<=dp[v].size();++j){
			dp[x][dp[x].size()-j]+=dp[v][dp[v].size()-j];
			if(mxn<dp[x][dp[x].size()-j]||(mxn==dp[x][dp[x].size()-j]&&pos>j)) mxn=dp[x][dp[x].size()-j],pos=j;
		}
		std::vector<int>e; std::swap(e,dp[v]);
//		printf("%d\n",dp[v].size());
	}
	dp[x].pb(1);
//	printf("x:%d,mxn:%d\n",x,mxn);
	if(mxn<=1) pos=0;
	ans[x]=pos;
}
int main(){
//	freopen("Data.in","r",stdin);
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v);vec[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i) printf("%d\n",ans[i]);
}