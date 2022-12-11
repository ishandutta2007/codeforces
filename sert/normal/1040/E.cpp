#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false, E = false;

ll step(ll a, ll st) {
	if (st == 0) return 1;
	if (st % 2) return a * step(a, st - 1) % MD;
	ll q = step(a, st / 2);
	return q * q % MD;
}

int p[N];
int fnd(int v) {
	return (p[v] == v ? v : p[v] = fnd(p[v]));
}

void solve() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
#ifdef MADE_BY_SERT
		scanf("%lld", &a[i]);
#else
		scanf("%I64d", &a[i]);
#endif
	}

	map<ll, vector<pair<int, int>>> es;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		v1--;
		v2--;
		ll val = (a[v1] ^ a[v2]);
		es[val].push_back(make_pair(v1, v2));
	}

	ll ans = step(2, n + k);
	vector<int> mark(n, 0);
	int mkek = 0;
	for (auto it: es) {
		ans = (ans - step(2, n) + MD) % MD;
		mkek++;
		int kmp = n;
		auto v = it.second;
		for (int i = 0; i < (int)v.size(); i++) {
			int v1 = v[i].first;
			int v2 = v[i].second;
			if (mark[v1] != mkek) {
				mark[v1] = mkek;
				p[v1] = v1;
			}
			if (mark[v2] != mkek) {
				mark[v2] = mkek;
				p[v2] = v2;
			}

			v1 = fnd(v1);
			v2 = fnd(v2);
			if (v1 != v2) {
				kmp--;
				p[v1] = v2;
			}
		}
		ans = (ans + step(2, kmp)) % MD;
		//cerr << it.first << ": " << kmp << "\n";	
	}
	cout << ans << "\n";
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 2;
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}