#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
using namespace std;

const int N=5005,mod=1e9+7;
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}
	return ans;
}

int n,dp[N],sum[N],fac[N],ifac[N],pre[N],now[26];
char s[N];
int c(int x,int y){
	return (ll)fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	fac[0]=1;for(int i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=0;i<=n;i++) ifac[i]=exp(fac[i],mod-2);
	for(int i=1;i<=n;i++){
		pre[i]=now[s[i]-'a'];
		now[s[i]-'a']=i;
	}
	for(int i=0;i<=n;i++) sum[i]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=n;j++)
			dp[j]=(sum[j-1]-(pre[j]?sum[pre[j]]:0)+mod)%mod;
		sum[0]=dp[0];
		for(int j=1;j<=n;j++)
			sum[j]=(sum[j-1]+dp[j])%mod;
		ch(ans,(ll)c(n-1,i-1)*sum[n]%mod);
	}
	printf("%d\n",ans);
	return 0;
}