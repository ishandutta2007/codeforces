#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;

const int MOD = 1e9 + 7;
const ll INF = 1e12;

int main() {
	int N; ll ub; cin >> N >> ub;
	vector<ll> a(N);
	rep(i, N) cin >> a[i];
	vector<i_i> di;
	rep(i, N)
		for (int t = 1; t <= 32000; t++) {
			di.pb(i_i(t, i));
			di.pb(i_i((a[i] - 1) / t + 1, i));
		}
	sort(di.begin(), di.end());
	rep(i, N) ub += a[i];
	// Y
	ll T = 0;
	vector<ll> t(N);
	rep(i, N) T += a[i], t[i] = a[i];
	ll ans = 1;
	for (int k = 0; k < di.size(); k++) {
		ll d = di[k].first;
		int i = di[k].second;
		ll _t = (a[i] + d - 1) / d;
		ll _r = _t * d - a[i];
		T += _t - t[i], t[i] = _t;
		ll nd = INF;
		if (k + 1 < di.size()) nd = di[k + 1].first;
		ll x = ub / T;
		x = min(x, nd - 1);
		if (x >= d) ans = max(ans, x);
	}
	cout << ans << endl;
}