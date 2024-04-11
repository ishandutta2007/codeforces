//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll n, ans = 1;
ll qpow(ll x, ll y) {
	ll res = 1;
	for(;y;y>>=1,x=x*x%mod) if(y&1) res = res * x % mod;
	return res;
}

int main() {
	scanf("%lld", &n);
	for(ll i=1;i<=n;i++) ans = ans * i % mod;
	ans -= qpow(2, n-1);
	printf("%lld\n", (ans+mod)%mod);
	return 0;
}