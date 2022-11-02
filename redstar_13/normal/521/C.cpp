#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int power(int a, int b, int m, int ans=1) {
    for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
    return ans;
}
typedef long long INT;
#define NN 100010
int dp[NN];
int cnt[NN];
char s[NN];
int f[NN],g[NN];
void pre(){
	f[0]=1;
	for(int i=1;i<NN;i++) f[i]=(INT)f[i-1]*i%mod;
	g[NN-1]=power(f[NN-1],mod-2,mod);
	for(int i=NN-2;i>=0;i--) g[i]=(INT)g[i+1]*(i+1)%mod;
}
int C(int n,int k){
	if(n<0||k<0) return 0;
	if(k>n) return 0;
	int ans=(INT)g[k]*g[n-k]%mod;
	ans=(INT)ans*f[n]%mod;
	return ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	pre();
	int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	int st=1;
	for(int i=1;i<=n;i++){
		cnt[i]=(cnt[i-1]+(INT)st*C(n-i-2,k-2))%mod;
		st=10LL*st%mod;
	}
	dp[n]=C(n-1,k);
	st=1;
	for(int i=n-1;i>=1;i--){
		dp[i]=C(n-2,k-1);
		dp[i]=(dp[i]+10LL*(dp[i+1]-cnt[n-i-1]-(INT)st*C(i-1,k-1)%mod))%mod;
		if(dp[i]<0) dp[i]+=mod;
		st=10LL*st%mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=s[i]-'0';
		ans=(ans+(INT)x*dp[i])%mod;
	}
	printf("%d\n",ans);
    return 0;
}