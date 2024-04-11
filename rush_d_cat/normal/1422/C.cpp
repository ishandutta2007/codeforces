#include <bits/stdc++.h>
using namespace std;
const int N=100000 + 10;
typedef long long LL;
char s[N]; int n;
const LL MOD=1e9+7;
LL pw[N],sum[N];
int main() {
	pw[0]=1;
	for(int i=1;i<N;i++) pw[i]=pw[i-1]*10%MOD;
	sum[0]=pw[0];
	for(int i=1;i<N;i++){
		sum[i]=sum[i-1]+pw[i]*(i+1)%MOD;
		sum[i]%=MOD;
	}
	scanf("%s",s+1); n=strlen(s+1);
	LL ans=0;
	for(int i=1;i<=n;i++){
		int lef=i-1;
		ans += (1LL*lef*(lef+1)/2)%MOD * pw[n-i] * (s[i]-'0') % MOD; ans %= MOD;
		int rig=n-i;
		if (rig) ans += sum[rig-1] * (s[i]-'0') % MOD; ans %= MOD;
		//printf("ans = %lld\n", ans);
		/*
		pw[0]*1 + pw[1]*2 + .... + pw[rig-1]*rig
		*/
	}
	cout << ans << endl;
}