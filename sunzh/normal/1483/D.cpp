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
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int dp[1210][1210];
int n,m;
struct edge{
	int u,v,w;
}e[1000010];
const int X=1e15;
signed main(){
	n=read();m=read();
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		e[i]=edge{u,v,w};
		dp[u][v]=dp[u+n][v+n]=dp[v][u]=dp[v+n][u+n]=w;
	}
	int q=read();
	for(int i=1;i<=q;++i){
		int u=read(),v=read(),w=read();
		dp[u][v+n]=dp[v][u+n]=dp[v+n][u]=dp[u+n][v]=X-w;
	}
	for(int i=1;i<=n+n;++i){
		for(int j=1;j<=n+n;++j)if(i!=j){
			for(int k=1;k<=n+n;++k)if(i!=k&&j!=k){
				dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=m;++i){
		if(dp[e[i].u][e[i].v+n]<=-e[i].w+X){
			++ans;
		}
	}
	printf("%d\n",ans);
}