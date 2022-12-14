//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 1e5 + 5;

int read() { int x; cin >> x; return x; }

int x[N], y[N];

ll dis(ll ax, ll ay, ll bx, ll by) {
	return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), sx = read(), sy = read(), tx = read(), ty = read();
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	ll ans = 1e18;
	for (int i = 0; i < n + 1; ++i) {
		ll d = dis(x[i], y[i], sx, sy);
		if (i == n)
			d = 0;
		ll mx = 0;
		for (int j = 0; j < n; ++j) if (dis(x[j], y[j], sx, sy) > d)
			smax(mx, dis(x[j], y[j], tx, ty));
		smin(ans, mx + d); 
	}
	cout << ans << endl;
}