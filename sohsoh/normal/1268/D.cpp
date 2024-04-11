#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e3 + 10;

int n, ans = MAXN, cnt, deg[MAXN], deg_cnt[MAXN];
bool M[MAXN][MAXN];

inline bool SCC() {
	ll t = 0, s = 0;
	memset(deg_cnt, 0, sizeof deg_cnt);
	for (int v = 1; v <= n; v++)
		deg_cnt[deg[v]]++;

	for (int i = 0; i <= n; i++) {
		while (t + 1 < n && deg_cnt[i]--) {
			s += i;
			t++;
			if (s == t * (t - 1) / 2)
				return false;
		}
	}

	return true;
}

inline void rev(int v) {
	deg[v] = n - 1 - deg[v];
	for (int u = 1; u <= n; u++) {
		if (u != v)
			deg[u] += (M[v][u] ? 1 : -1);
		M[v][u] = !M[v][u];
		M[u][v] = !M[u][v];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			M[i][j] = (c == '1');
			if (M[i][j]) deg[i]++;
		}
	}

	if (SCC()) return cout << 0 << sep << 1 << endl, 0;
	
	if (n <= 6) {
		for (int mask = 0; mask < (1 << n); mask++) {
			for (int v = 0; v < n; v++)
				if (mask & (1 << v))
					rev(v + 1);
		
			if (SCC()) {
				int c = __builtin_popcount(mask);
				if (c < ans) ans = c, cnt = 1;
				else if (c == ans) cnt++;
			}

			for (int v = 0; v < n; v++)
				if (mask & (1 << v))
					rev(v + 1);

		}

		if (ans == MAXN) cout << -1 << endl;
		else {
			for (int i = 1; i <= ans; i++)
				cnt = cnt * i;
			cout << ans << sep << cnt << endl;
		}
		return 0;
	}

	for (int v = 1; v <= n; v++) {
		rev(v);
		cnt += SCC();
		rev(v);
	}

	cout << 1 << sep << cnt << endl;
	return 0;
}