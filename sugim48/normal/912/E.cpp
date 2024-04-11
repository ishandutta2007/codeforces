#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
struct edge { int v, w; };
const ll INF = INT_MAX / 2;
const int MOD = 1e9 + 7;
const ll e18 = 1e18;

void f(vector<int>& ps, int i, ll x, vector<ll>& qs) {
	if (i == ps.size()) {
		qs.pb(x);
		return;
	}
	int p = ps[i];
	for (;;) {
		f(ps, i + 1, x, qs);
		if (x > e18 / p) break;
		x *= p;
	}
}

ll solve(vector<int> ps, ll k) {
	int N = ps.size();
	int N1 = min(4, N), N2 = N - N1;
	vector<int> ps1(N1), ps2(N2);
	rep(i, N1) ps1[i] = ps[i];
	rep(i, N2) ps2[i] = ps[N1 + i];
	vector<ll> qs1, qs2;
	f(ps1, 0, 1, qs1), f(ps2, 0, 1, qs2);
	sort(qs1.begin(), qs1.end()), sort(qs2.begin(), qs2.end());
	ll lb = 0, ub = e18;
	while (ub - lb > 1) {
		ll mid = (lb + ub) / 2, sum = 0;
		for (ll x: qs1)
			sum += upper_bound(qs2.begin(), qs2.end(), mid / x) - qs2.begin();
		if (sum >= k) ub = mid;
		else lb = mid;
	}
	return ub;
}

int main() {
	/*
	vector<bool> p(101, true);
	p[0] = p[1] = false;
	for (int x = 2; x <= 100; x++)
		if (p[x])
			for (int y = x * 2; y <= 100; y += x)
				p[y] = false;
	vector<int> ps;
	rep(x, 101) if (p[x]) ps.pb(x);
	for (; ps.size() > 16; ps.pop_back());
	for (;;) {
		ll k; cin >> k;
		cout << solve(ps, k) << endl;
	}
	*/
	int N; cin >> N;
	vector<int> ps(N);
	rep(i, N) cin >> ps[i];
	ll k; cin >> k;
	cout << solve(ps, k) << endl;
}