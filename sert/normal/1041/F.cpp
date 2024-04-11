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

int a[N], b[N];
int na[N], nb[N];
void solve() {
	int n, y1, m, y2;
	scanf("%d%d", &n, &y1);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	scanf("%d%d", &m, &y2);
	for (int i = 0; i < m; i++) scanf("%d", b + i);

	int ans = 1;

	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (cur < m && b[cur] < a[i]) cur++;
		if (b[cur] == a[i]) ans = 2;
	}

	for (int len = 2; len < INF; len *= 2) {
		int half = len / 2;
		unordered_map<int, int> ma, mb;
		for (int i = 0; i < n; i++) ma[a[i] % len]++;
		for (int i = 0; i < m; i++) mb[b[i] % len]++;
		for (auto it: ma) {
			int num = it.second;
			int o2 = (it.first + half) % len;
			if (mb.find(o2) != mb.end()) num += mb[o2];
			ans = max(ans, num);
		}
		for (auto it: mb) {
			ans = max(ans, it.second);
		}
	}

	printf("%d\n", ans);
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