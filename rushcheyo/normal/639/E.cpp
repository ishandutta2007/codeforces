#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 150005;
int n, p[N], t[N], id[N];
ll T, l[N], r[N];

bool check(double mid) {
	mid /= T;
	double mx = 0;
	for (int i = 1, j; i <= n; i = j) {
		for (j = i; j <= n && p[id[j]] == p[id[i]]; ++j)
			if (mx > p[id[j]] * (1 - mid * r[id[j]])) return false;
		for (int k = i; k < j; ++k) mx = max(mx, p[id[k]] * (1 - mid * l[id[k]]));
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> p[i];
	for (int i = 1; i <= n; ++i) cin >> t[i], T += t[i], id[i] = i;
	sort(id + 1, id + 1 + n, [](int x, int y) { return 1ll * p[x] * t[y] > 1ll * p[y] * t[x]; });
	ll now = 0;
	for (int i = 1, j; i <= n; i = j) {
		ll sum = t[id[i]];
		for (j = i + 1; j <= n && 1ll * p[id[i]] * t[id[j]] == 1ll * p[id[j]] * t[id[i]]; ++j) sum += t[id[j]];
		for (int k = i; k < j; ++k) l[id[k]] = now + t[id[k]], r[id[k]] = now + sum;
		now += sum;
	}
	sort(id + 1, id + 1 + n, [](int x, int y) { return p[x] < p[y]; });
	double l = 0, r = 1;
	for (int i = 0; i < 40; ++i) {
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	cout << fixed << setprecision(10) << l << endl;
	return 0;
}