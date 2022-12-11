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

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int ans = 0;
	for (int i = 0; i < (n + 1) / 2; i++) {
		int x = i;
		int y = n - i - 1;
		if (x == y) {
			if (v[x] == 2) ans += min(a, b);
		} else {
			if (v[x] == 2 && v[y] == 2) ans += min(a, b) * 2;
			else if (v[x] == 1 && v[y] == 2) ans += b;
			else if (v[y] == 1 && v[x] == 2) ans += b;
			else if (v[y] == 0 && v[x] == 2) ans += a;
			else if (v[x] == 0 && v[y] == 2) ans += a;			
			else if (v[x] != v[y]) ans = -INF;

			//printf("%d %d %d %d %d\n", x, v[x], y, v[y], ans);
		}
	}
	cout << max(-1, ans) << "\n";
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