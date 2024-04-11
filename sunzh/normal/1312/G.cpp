#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
bool S[1000010];
int st[1000010];
int trie[1000010][30];
int id[1000010];
int cnt;
int dp[1000010];
void dfs(int x,int minn,int fa){
	if(S[x]){
		id[x]=++cnt;
	}
	else id[x]=cnt;
	if(x) dp[x]=dp[fa]+1;
	else dp[x]=0;
	if(S[x]){
		dp[x]=min(dp[x],minn+id[x]);
	}
	minn=min(minn,dp[x]-id[x]+S[x]);
	for(int i=1;i<=26;++i){
		if(trie[x][i]){
			int v=trie[x][i];
			dfs(v,minn,x);
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int p=read();
		char c=getchar();
		while(c<'a'||c>'z') c=getchar();
		trie[p][c-'a'+1]=i;
	}
	m=read();
	for(int i=1;i<=m;++i){
		int x=read();S[x]=1;st[i]=x;
	}
	dfs(0,0x3f3f3f3f,0);
	for(int i=1;i<=m;++i) printf("%d ",dp[st[i]]);
	return 0;
}