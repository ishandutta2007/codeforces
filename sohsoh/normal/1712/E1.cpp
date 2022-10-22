#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define int			ll
#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e5 + 10;

int q;
vector<int> D[MAXN];
vector<pll> vec[MAXN], Q[MAXN];
ll fen[MAXN], tot, ans[MAXN];

inline void update(int ind, ll val) {
	tot += val;
	for (++ind; ind < MAXN; ind += ind & -ind)
		fen[ind] += val;
}

inline ll query(int ind) {
	ll ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind)
		ans += fen[ind];
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 1; i < MAXN; i++)
		for (int j = 2 * i; j < MAXN; j += i)
			D[j].push_back(i);

	for (int i = 1; i < MAXN; i++) { // 3 2 3
		if (i * 6 < MAXN) vec[i * 6].push_back({i * 3, 1});
		if (i % 2 == 0) {
			int x = 2 * i + i / 2;
			if (x * 3 < MAXN) vec[x * 3].push_back({i * 3, 1});
		}
	}

	cin >> q;
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		Q[r].push_back({l, i});
		ans[i] = 1ll * (r - l + 1) * (r - l) * (r - l - 1) / 6;
	}

	for (int i = 1; i < MAXN; i++) {
		reverse(all(D[i]));
		for (int j = 0; j < int(D[i].size()); j++)
			vec[i].push_back({D[i][j], j});

		sort(all(vec[i]), greater<pll>());
		sort(all(Q[i]), greater<pll>());

		int pq = 0, pv = 0, sq = Q[i].size(), sv = vec[i].size();
		while (pq < sq || pv < sv) {
			if (pq == sq || (pv < sv && vec[i][pv].X >= Q[i][pq].X)) {
				update(vec[i][pv].X, vec[i][pv].Y);
				pv++;
			} else {
				ans[Q[i][pq].Y] -= tot - query(Q[i][pq].X - 1);
				pq++;
			}
		}
	}

	for (int i = 1; i <= q; i++)
		cout << ans[i] << endl;
	return 0;
}