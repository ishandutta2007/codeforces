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
int n;
vector<int>vec[100010];
int deg[100010];
int ans=0;
int dp[100010][2];
void dfs(int x,int fa){
	dp[x][1]=1;
	for(int v:vec[x]){
		if(v==fa) continue ;
		
		dfs(v,x);
		ans=max(ans,dp[x][0]+max(dp[v][0],dp[v][1]));
		ans=max(ans,dp[x][1]+dp[v][0]);
		dp[x][0]=max(dp[x][0],max(dp[v][1],dp[v][0])+deg[x]-2);
		dp[x][1]=max(dp[x][1],dp[v][0]+1);
	}
	ans=max(ans,max(dp[x][0],dp[x][1]));
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
		++deg[u],++deg[v];
	}dfs(1,0);
	printf("%d\n",ans);
	return 0;
}