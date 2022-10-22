#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>
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
int n,m;
char g[100][100];
int dp[60][60][60][60];
int dfs(int x1,int y1,int x2,int y2){
	if(x1==x2&&y1==y2){
		return g[x1][y1]=='#';
	}
	if(dp[x1][y1][x2][y2]!=-1) return dp[x1][y1][x2][y2];
	dp[x1][y1][x2][y2]=max(y2-y1+1,x2-x1+1);
	for(int k=x1;k<x2;++k) dp[x1][y1][x2][y2]=min(dfs(x1,y1,k,y2)+dfs(k+1,y1,x2,y2),dp[x1][y1][x2][y2]);
	for(int k=y1;k<y2;++k) dp[x1][y1][x2][y2]=min(dfs(x1,y1,x2,k)+dfs(x1,k+1,x2,y2),dp[x1][y1][x2][y2]);
	return dp[x1][y1][x2][y2];
}
int main(){
	memset(dp,-1,sizeof(dp));
	n=read();
	for(int i=1;i<=n;++i){
		scanf("%s",g[i]+1);
	}
	printf("%d\n",dfs(1,1,n,n));
	return 0;
}