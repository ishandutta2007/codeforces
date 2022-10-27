#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <cstring>
using namespace std;
const int N = 1000000 + 10;
/*
int f[N], g[N];
pair<int,int> F(int x) {
	if (x == 0) {
		f[x]=g[x]=0; return {0,0};
	}
	if (f[x] != -1 && g[x] != -1) return {f[x],g[x]};

	set<int> s1, s2;
	for(int p=0;p<x;p++){
		int q = x-1-p;
		s1.insert(F(p).second ^ F(q).second);
		if (p>0&&q>0)
			s1.insert(F(p).first ^ F(q).first);
	}
	for(int i=0;;i++) {
		if(s1.count(i)==0) {
			f[x] = i; break;
		}
	}

	for(int p=0;p<x;p++){
		int q = x-1-p;
		if(p>0) s2.insert(F(p).first ^ F(q).second);
	}
	for(int i=0;;i++) {
		if(s2.count(i)==0) {
			g[x] = i; break;
		}
	}
	return {f[x],g[x]};
}
*/
int n;
typedef long long ll;
const ll mod = 1e9 + 7;

ll fac[N], inv[N];
ll mpow(ll a, ll x) {
	if (x==0) return 1;
	ll t = mpow(a,x>>1);
	if(x%2==0) return t*t%mod;
	return t*t%mod*a%mod;
}
ll c(int x,int y){
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}

int main() {
	fac[0]=1,inv[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=fac[i-1]*i%mod;
		inv[i]=inv[i-1]*mpow(i,mod-2)%mod;
	}	
	int t;  t=1;
	while (t --) {
		int n; cin >> n;		
		ll ans = (n%2==0?fac[n-1]:0);
		for(int k=1;k<=n;k++){
			if(k%2!=n%2) continue;
			int tot = (n-1) - (k-1);
			if(tot<k) break;
			ll ways = c(tot,k) * fac[n-1-k] % mod;
			ans = (ans + ways) % mod;
		}
		cout << ans * n % mod * 2 % mod << endl;
	}
}