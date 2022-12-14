#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005;
const ll INF = 1ll << 62;
const char dir[2][2] = {{'L', 'D'}, {'U', 'R'}};
int n, l;
ll t[N], x[N], y[N];

ll floor(ll, ll);
ll ceil(ll a, ll b) {
	if (a > 0) return (a - 1) / b + 1;
	return -floor(-a, b);
}
ll floor(ll a, ll b) {
	if (a >= 0) return a / b;
	return -ceil(-a, b);
}

pair<bool, string> solve(ll *x) {
	vector<pair<int, pair<ll, ll>>> v;
	v.emplace_back(0, make_pair(0, 0));
	v.emplace_back(l, make_pair(1, 0));
	for (int i = 1; i <= n; ++i)
		v.emplace_back(t[i] % l, make_pair(-(t[i] / l), x[i]));
	sort(v.begin(), v.end());
	ll maxl = -INF, minr = INF;
	for (int i = 1; i < (int)v.size(); ++i) {
		ll A = v[i].second.first - v[i - 1].second.first, B = v[i].second.second - v[i - 1].second.second, T = v[i].first - v[i - 1].first;
		if (!A) {
			if (abs(B) > T) return {false, ""};
			continue;
		}
		if (A < 0) A = -A, B = -B;
		maxl = max(maxl, ceil(-T - B, A)), minr = min(minr, floor(T - B, A));
	}
	if (maxl > minr) return {false, ""};
	if (maxl + l & 1) ++maxl;
	if (maxl > minr) return {false, ""};
	vector<pair<int, int>> d = {{0, 0}, {l, maxl}};
	for (int i = 1; i <= n; ++i)
		d.emplace_back(t[i] % l, -(t[i] / l) * maxl + x[i]);
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());
	string ans;
	ans.resize(l);
	for (int i = 1; i < (int)d.size(); ++i)
		fill(ans.begin() + d[i - 1].first, ans.begin() + d[i - 1].first + (d[i].first - d[i - 1].first + d[i].second - d[i - 1].second) / 2, 1);
	return {true, ans};
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> l;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> x[i] >> y[i];
		if (x[i] + y[i] + t[i] & 1) return cout << "NO\n", 0;
		x[i] += y[i];
		y[i] = x[i] - 2 * y[i];
	}
	auto t1 = solve(x);
	if (!t1.first) return cout << "NO\n", 0;
	auto t2 = solve(y);
	if (!t2.first) return cout << "NO\n", 0;
	string ans;
	ans.resize(l);
	for (int i = 0; i < l; ++i) ans[i] = dir[t1.second[i]][t2.second[i]];
	cout << ans << '\n';
	return 0;
}