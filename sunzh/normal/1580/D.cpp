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
int n,m;
int a[4010];
int ls[4010],rs[4010];
int stk[4010],top;
void build(){
	for(int i=1;i<=n;++i){
		while(top&&a[stk[top]]>a[i]){
			rs[stk[top]]=ls[i],ls[i]=stk[top];--top;
		}
		if(top) rs[stk[top]]=i;
		stk[++top]=i;
	}
}
int sz[4010],dp[4010][4010],tmp[4010];
void dfs(int x){
	sz[x]=1;dp[x][1]=(m-1)*a[x];
	if(ls[x]){
		dfs(ls[x]);
		for(int i=0;i<=sz[x]+sz[ls[x]];++i) tmp[i]=0;
		for(int i=0;i<=sz[x];++i){
			for(int j=0;j<=sz[ls[x]];++j){
				tmp[i+j]=max(tmp[i+j],dp[x][i]+dp[ls[x]][j]-2*i*j*a[x]);
			}
		}
		sz[x]+=sz[ls[x]];
		for(int i=0;i<=sz[x];++i) dp[x][i]=tmp[i];
	}
	if(rs[x]){
		dfs(rs[x]);
		for(int i=0;i<=sz[x]+sz[rs[x]];++i) tmp[i]=0;
		for(int i=0;i<=sz[x];++i){
			for(int j=0;j<=sz[rs[x]];++j){
				tmp[i+j]=max(tmp[i+j],dp[x][i]+dp[rs[x]][j]-2*i*j*a[x]);
			}
		}
		sz[x]+=sz[rs[x]];
		for(int i=0;i<=sz[x];++i) dp[x][i]=tmp[i];
	}
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) a[i]=read();
	build();
	dfs(stk[1]);
	printf("%lld\n",dp[stk[1]][m]);
}