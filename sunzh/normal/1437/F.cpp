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
int n;
int a[5010];
int pr[5010];
int dp[5010];
int inv[5010];
int sum[5010];
const int mod=998244353;
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+n+1);
	int pos=0;
	for(int i=1;i<=n;++i){
		while(a[pos]*2<=a[i]) ++pos;
		pr[i]=pos-1;
//		printf("pos:%d\n",pos);
	}
	if(pr[n]!=n-1){
		printf("0\n");return 0;
	}
	for(int i=1;i<=n;++i) inv[i]=qpow(i,mod-2);
	for(int i=1;i<=n;++i) dp[i]=inv[n];
	sum[1]=1ll*dp[1]*inv[n-pr[1]-1]%mod;
	for(int i=2;i<=n;++i){
		(dp[i]+=sum[pr[i]])%=mod;
		sum[i]=(sum[i-1]+1ll*dp[i]*inv[n-pr[i]-1]%mod)%mod;
	}
	for(int i=1;i<=n;++i) dp[n]=1ll*dp[n]*i%mod;
	printf("%d\n",dp[n]);
}