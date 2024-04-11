#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

int x[N], y[N];

void solve() {
	int n, ans3 = -1;
	cin >> n;
	int minx = INF, miny = INF, maxx = -INF, maxy = -INF;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		minx = min(minx, x[i]);
		miny = min(miny, y[i]);
		maxx = max(maxx, x[i]);
		maxy = max(maxy, y[i]);
	}

	int ans4 = (maxx - minx + maxy - miny) * 2;

	for (int i = 0; i < n; i++) {
		int xx = x[i];
		int yy = y[i];
		ans3 = max(ans3, (maxx - xx) + (maxy - yy));
		ans3 = max(ans3, (maxx - xx) + (yy - miny));
		ans3 = max(ans3, (xx - minx) + (maxy - yy));
		ans3 = max(ans3, (xx - minx) + (yy - miny));
	}

	cout << ans3 * 2;
	for (int i = 4; i <= n; i++) {
		cout << " " << ans4;
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 2;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}