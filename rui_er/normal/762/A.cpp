//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;

ll n, k;
vector<ll> a; 
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &k);
	for(ll i=1;i*i<=n;i++) {
		if(!(n % i)) {
			a.push_back(i);
			if(i * i < n) a.push_back(n/i);
		}
	}
	sort(a.begin(), a.end());
	ll sz = a.size();
	if(k > sz) puts("-1");
	else printf("%lld\n", a[k-1]);
	return 0;
}