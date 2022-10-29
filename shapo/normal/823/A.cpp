#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

typedef vector< int > vi;
typedef vector< vi > vvi;

int n, k;
vvi g;

bool check_odd(int d) {
	if (d % 2 == 0) return 0;
	return (1ll * k * (d / 2) + 2) >= n;
}

bool check_even(int d) {
	if (d % 2 == 1) return 0;
	return (1ll * k * (d / 2) + 1) >= n;
}

void add(int u, int v) {
	g[u].pb(v);
	g[v].pb(u);
}

void construct(int d) {
	g.assign(n, vi());
	int cnt = 1;
	if (d % 2 == 1) {
		cnt++;
		add(0, 1);
	}
	vi append;
	for (int t = 0; t < k; ++t) {
		append.pb(t + cnt);
		add(t + cnt, t % cnt);
	}
	for (int i = k + cnt; i < n; ++i) {
		int rel = i - k - cnt;
		int id = rel % k;
		add(append[id], i);
		append[id] = i;
	}
}

int
main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	int ans = 10 * n;
	{
		int l = 0, r = n + 1;
		while (l < r - 1) {
			int mid = (l + r) / 2;
			if (check_odd(mid * 2 + 1)) {
				r = mid;
			} else {
				l = mid;
			}
		}
		ans = min(ans, r * 2 + 1);
	}
	{
		int l = 0, r = n + 1;
		while (l < r - 1) {
			int mid = (l + r) / 2;
			if (check_even(mid * 2)) {
				r = mid;
			} else {
				l = mid;
			}
		}
		ans = min(ans, r * 2);
	}
	cout << ans << '\n';
	construct(ans);
	for (int i = 0; i < n; ++i) {
		for (int to : g[i]) {
			if (i < to) {
				cout << i + 1 << " " << to + 1 << '\n';
			}
		}
	}
	return 0;
}