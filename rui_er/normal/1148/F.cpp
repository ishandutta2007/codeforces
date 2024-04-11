//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e5+5, bit = 62;

ll n, ans;
struct Node {ll val, mask, bits;}a[N];

int main() {
	scanf("%llu", &n);
	for(ll i=1;i<=n;i++) {
		scanf("%lld%lld", &a[i].val, &a[i].mask);
		ans += a[i].val;
		for(ll _=bit;_+1;_--) if((a[i].mask >> _) & 1) {a[i].bits = _; break;}
	}
	if(ans < 0) for(ll i=1;i<=n;i++) a[i].val = -a[i].val;
	ans = 0;
	for(ll _=0;_<=bit;_++) {
		ll s = 0;
		for(ll i=1;i<=n;i++) s += (a[i].bits == _) * a[i].val;
		if(s <= 0) continue;
		ans |= (1LL << _);
		for(ll i=1;i<=n;i++) a[i].val *= ((a[i].mask >> _) & 1) ? -1 : 1;
	}
	printf("%lld\n", ans);
//	puts("----------\nDEBUG: "); for(ll i=1;i<=n;i++) printf("%lld\n", a[i].val);
	return 0;
}