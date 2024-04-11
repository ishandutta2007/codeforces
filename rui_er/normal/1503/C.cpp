#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5+5, inf = 0x3f3f3f3f3f3f3f3fll;

ll n, now, ans;
struct Node {
	ll a, c, id;
	Node(ll x=0, ll y=0, ll z=0) : a(x), c(y), id(z) {}
	friend bool operator < (const Node &a, const Node &b) {return a.a < b.a;}
}a[N];

int main() {
	scanf("%lld", &n);
	for(ll i=1;i<=n;i++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		a[i] = Node(x, y, i);
		ans += y;
	}
	sort(a+1, a+1+n);
	for(ll i=2;i<=n;i++) {
		now = max(now, a[i-1].a+a[i-1].c);
		ans += max(a[i].a-now, 0LL);
	}
	printf("%lld\n", ans);
	return 0;
}