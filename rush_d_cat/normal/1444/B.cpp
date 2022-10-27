#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
const LL MOD = 998244353;
int n, a[N];
LL fac[N],inv[N];
LL mpow(LL a, LL x) {
	if (x == 0) return 1;
	LL t = mpow(a, x>>1);
	if (x % 2 == 0) return t * t % MOD;
	return t * t % MOD * a % MOD;
}
LL c(int x,int y){
	if(y<0) return 0;
	return fac[x]*inv[y]%MOD*inv[x-y]%MOD;
}



int main() {
	for(int i=1;i<N;i++){
		inv[i]=mpow(i,MOD-2);
	}
	fac[0]=1,inv[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=inv[i-1]*inv[i]%MOD;
	}

	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i]); 

	sort(a+1,a+1+2*n);
	LL L = 0, R = 0;
	for(int i=1;i<=n;i++){
		(L+=a[i])%=MOD;
	}
	for(int i=n+1;i<=2*n;i++){
		(R+=a[i])%=MOD;
	}
	LL ans=0;
	//printf("R-L=%lld",R-L);
	for(int k=0;k<=n;k++){

		LL tmp = c(n-1,k-1)*(R - L)%MOD +c(n-1,n-k-1)*(R-L)%MOD;
		tmp=tmp*c(n,k)%MOD;
		ans=((ans+tmp)%MOD+MOD)%MOD;
		//printf("k=%lld,tmp=%lld\n", k,tmp);
	}
	cout<<ans<<endl;
}