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
int T;
int n,e;
int a[200010];
int dp[200010][2];
bool vis[1000010];
int p[1000010],tot;
void pr(int x){
	for(int i=2;i<=x;++i){
		if(!vis[i]) p[++tot]=i;
		for(int j=1;j<=tot&&i*p[j]<=x;++j){
			vis[i*p[j]]=1;
			if(i%p[j]==0) break ;
		}
	}
}
int main(){
	T=read();
	pr(1000000);
	while(T--){
		n=read();e=read();
		for(int i=1;i<=n;++i) a[i]=read(),dp[i][0]=dp[i][1]=-0x7f7f7f7f;
		long long ans=0;
		for(int i=n;i>=1;--i){
			// printf("dp[%d]=%d %d\n",i,dp[i][0],dp[i][1]);
			if(a[i]==1){
				(ans+=max(0,dp[i][1]));
				if(i>e) dp[i-e][0]=max(0,dp[i][0])+1,dp[i-e][1]=dp[i][1];
			}
			else if(!vis[a[i]]){
				(ans+=max(0,dp[i][0]));
				if(i>e) dp[i-e][1]=max(0,dp[i][0])+1;
			}
		}
		printf("%lld\n",ans);
	}
}