#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)998244353;
bool D = false;

ll step(ll a, ll st) {
	if (st == 0) return 1;
	if (st % 2) return a * step(a, st - 1) % MD;
	ll q = step(a, st / 2);
	return q * q % MD;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> lst;
	for (int i = 0; i < n; i++) {
		cin >> a[i];		
		lst[a[i]] = i;
	}

	int cur = -1;
	int deg = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && cur < i) deg++;
		cur = max(cur, lst[a[i]]);
	}

	cout << step(2, deg) << "\n";
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}