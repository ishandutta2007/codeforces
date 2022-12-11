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

vector<int> es[N];
int ans, k;

int go(int v, int pr = -1) {
	if ((int)es[v].size() == 1) return 1;

	vector<int> sz;
	for (int w: es[v]) {
		if (w == pr) continue;
		sz.push_back(go(w, v));
	}

	sort(sz.begin(), sz.end());
	int x = sz.size();

	int p = 0;
	while (p + 1 < x && sz[p] + sz[p + 1] <= k) p++;

	ans += x - p - 1;
	return sz[p] + 1;
}

void solve() {
	int n;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		es[i].clear();
	}
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		v1--;
		v2--;
		es[v1].push_back(v2);
		es[v2].push_back(v1);
	}

	int root = -1;
	for (int i = 0; i < n; i++) {
		if ((int)es[i].size() > 1) {
			root = i;
		}
	}

	ans = 0;
	go(root);
	cout << ans + 1 << "\n";
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;
	tst = 3;	
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}