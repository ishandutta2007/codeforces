#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n;
int head[100010],nxt[200010],to[200010];
int tot;
// vector<int>vec[100010];
int ans[100010];
int N;
int cnt;
int dp[100010];
int idx;
int dfn[100010],pos[100010];
void dfs(int x,int fa){
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue ;
		dfs(v,x);
	}
	dfn[x]=++idx,pos[idx]=x;
}
int solve(int x){
	if(ans[x]!=-1) return ans[x];
	N=x;cnt=0;
	for(int i=1;i<=idx;++i){
		dp[pos[i]]=0;
		// printf("pos[%d]=%d\n",i,pos[i]);
		int mx1=0,mx2=0;
		for(int j=head[pos[i]];j;j=nxt[j]){
			int v=to[j];
			if(dfn[v]<i){
				if(dp[v]>mx1) mx2=mx1,mx1=dp[v];
				else if(dp[v]>mx2) mx2=dp[v];
			}
		}
		if(mx1+mx2+1>=x) ++cnt;else dp[pos[i]]=mx1+1;
	}
	return ans[x]=cnt;
}
int main(){
	memset(ans,-1,sizeof(ans));
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		nxt[++tot]=head[u],head[u]=tot,to[tot]=v;
		nxt[++tot]=head[v],head[v]=tot,to[tot]=u;
	}
	dfs(1,0);
	int B=sqrt(n*log(n)/log(2))/2;ans[1]=n;
	for(int i=2;i<=B;++i){
		ans[i]=solve(i);
	}
	for(int i=B+1;i<=n;++i){
		int l=i,r=n,res=i;
		ans[i]=solve(i);
		while(l<=r){
			int mid=l+r>>1;
			if(solve(mid)==ans[i]) res=mid,l=mid+1;else r=mid-1;
		}
		for(int j=i+1;j<=res;++j) ans[j]=ans[i];
		i=res;
	}
	for(int i=1;i<=n;++i) printf("%d\n",ans[i]);
}