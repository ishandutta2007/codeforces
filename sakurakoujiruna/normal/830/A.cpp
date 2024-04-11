#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2011;
ll dp[N][N];

ll a[N], b[N];
ll f(ll x, ll y, ll p) {
	return abs(x - y) + abs(y - p);
}

struct seg {
	ll l, r;
	bool operator <(seg s) const {
		return r < s.r;
	}
};

bool check(int n, int k, ll p, ll lim) {
	vector <seg> v;
	for(int i = 1; i <= n; i ++) {
		if(abs(a[i] - p) > lim) return 0;
		ll l = min(a[i], p) * 2, r = max(a[i], p) * 2;
		ll sp = lim - abs(a[i] - p);
		v.push_back({l - sp, r + sp});
	}
	sort(v.begin(), v.end());

	int i = 1;
	multiset <ll> st;
	for(seg s : v) {
		while(i <= k && b[i] * 2 <= s.r)
			st.insert(b[i ++] * 2);
		auto it = st.lower_bound(s.l);
		if(it == st.end()) return 0;
		st.erase(it);
	}
	return 1;
}

int main() {
	ios :: sync_with_stdio(0);
	int n, k; ll p;
	cin >> n >> k >> p;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	for(int i = 1; i <= k; i ++)
		cin >> b[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + k + 1);
	
	ll l = 0, r = 2e9L + 1;
	while(l + 1 < r) {
		ll m = (l + r) / 2;
		if(check(n, k, p, m - 1))
			r = m;
		else
			l = m;
	}
	cout << l << '\n';
}