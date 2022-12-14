#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1022;
const int M = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = 998244353;

ll step(ll a, ll st) {
	if (st == 0) return 1;
	if (st % 2) return a * step(a, st - 1) % MD;
	ll q = step(a, st / 2);
	return q * q % MD;
}

ll bak(ll x) {
	return step(x, MD - 2);
}

struct F {
	ll c, z;
	F(ll C = 0, ll Z = 1) {
		ll g = __gcd(C, Z);
		c = (C / g) % MD;
		z = (Z / g) % MD;
	}

	F operator / (const ll &x) {
		return F(c, z * x);
	}

	F operator + (const F &x) {
		return F(c * x.z + z * x.c, z * x.z);
	}
	F operator + (const ll &x) {
		return F(c + z * x, z);
	}
};

int a[N][N];
F dp[N][N];
vector<pair<int, int>> data[M];

void solve() {
	int n, m;
	set<int> s;
	unordered_map<int, int> mp;
	scanf("%d%d", &n, &m);	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			s.insert(a[i][j]);
		}
	}
	int val = 0;
	for (auto it = s.begin(); it != s.end(); it++) {
		mp[*it] = val++;
	}

	for (int i = 0; i < M; i++) data[i].clear();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = mp[a[i][j]];
			data[a[i][j]].push_back(make_pair(i, j));
		}
	}

	int R, C;
	scanf("%d%d", &R, &C);
	R--;
	C--;

	F sumD(0, 1);

	ll sumx = 0, sumx2 = 0, sumy = 0, sumy2 = 0, num = 0;

	for (int val = 0; val < M; val++) {
		for (auto q: data[val]) {			
			ll y = q.first;
			ll x = q.second;

			if (val == 0) {
				dp[y][x] = F(0, 1);
			} else {
				F res = (x * x + y * y) * num + sumx2 + sumy2 - 2 * x * sumx - 2 * y * sumy;
				dp[y][x] = (sumD + res) / num;
			}
		}

		for (auto q: data[val]) {
			int x = q.second;
			int y = q.first;
			sumx += x;
			sumy += y;
			sumx2 += x * x;
			sumy2 += y * y;
			num++;
			sumD = sumD + dp[q.first][q.second];
		}
	}

	cout << dp[R][C].c * bak(dp[R][C].z) % MD << "\n";
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	tst = 2;
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}