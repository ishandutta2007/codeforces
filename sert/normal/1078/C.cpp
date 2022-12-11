#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = 998244353;
bool D = false;

vector<int> es[N];

ll dp0[N], dp1[N];
ll doo[N];

ll step(ll a, ll st) {
	if (st == 0) return 1;
	if (st % 2 == 1) return a * step(a, st - 1) % MD;
	ll q = step(a, st / 2);
	return q * q % MD;
}

ll bak(ll x) {
	return step(x, MD - 2);
}

void dfs(int v, int pr) {	
	ll kk = 1;
	if ((int)es[v].size() == 1 && pr != -1) {
		dp0[v] = 1;
		dp1[v] = doo[v] = 0;
		return; 
	}

	dp0[v] = 1;
	dp1[v] = 0;	
	doo[v] = 1;
	for (int w: es[v]) {
		if (w == pr) continue;
		dfs(w, v);
		doo[v] = (doo[v] * (2 * dp1[w] + dp0[w])) % MD;
		dp0[v] = (dp0[v] * (dp0[w] + dp1[w])) % MD;
		kk = kk * (dp0[w] + 2 * dp1[w]) % MD;
	}
	doo[v] = (doo[v] - dp0[v] + MD) % MD;

	for (int w: es[v]) {
		if (w == pr) continue;

		ll cur = (dp0[w] + 2 * dp1[w]) % MD;
		ll ad = (dp0[w] + doo[w]) % MD;
		//cout << " " << v << " " << w << " " << ad << " ad\n";
		dp1[v] = (dp1[v] + kk * bak(cur) % MD * ad) % MD;
	}
}

void solve() {
	int n;
	cin >> n;
	//n = 100000;

	if (n == 1) {
		cout << "1\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		es[i].clear();
		dp0[i] = dp1[i] = doo[i] = 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		//v1 = i + 1;
		//v2 = i + 2;
		v1--;
		v2--;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}

	dfs(0, -1);
	cout << (dp0[0] + dp1[0]) % MD << "\n";

	/*for (int i = 0; i < n; i++) {
		cout << dp1[i] << " " << dp0[i] << " " << doo[i] << "\n"; 
	}*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 4;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}