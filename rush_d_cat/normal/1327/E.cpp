#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
int n;
LL mpow(LL a,LL x){
	if(x==0)return 1;
	LL t=mpow(a,x>>1);
	if(x%2==0)return t*t%MOD;
	return t*t%MOD*a%MOD;
}
int main() {
	cin>>n;
	for(int i=1;i<=n-2;i++){
		LL ans=0;
		ans=1LL*(n-i-1)*10%MOD*9*9%MOD*mpow(10,n-i-2)%MOD;
		ans=ans+1LL*10*9*mpow(10,n-i-1)%MOD*2%MOD;
		ans=ans%MOD;
		printf("%lld ", ans);
	}
	if(n>=2){
		printf("%lld ", (LL)2*10*9);
	}
	if(n>=1){
		printf("%lld\n", (LL)10);
	}
}