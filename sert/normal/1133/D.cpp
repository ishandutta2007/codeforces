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

void solve() {	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	map<pair<int, int>, int> mp;
	int ans = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) {
		if (a[i] == 0 && b[i] == 0) ans++;
		if (a[i] == 0) continue;
		// d = -b / a
		int g = __gcd(abs(a[i]), abs(b[i]));
		if (a[i] < 0) {
			b[i] = -b[i];
			a[i] = -a[i];
		}		
		mp[make_pair(b[i] / g, a[i] / g)]++;
	}
	int mx = 0;
	for (auto x: mp) mx = max(mx, x.second);
	cout << mx + ans << "\n";
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
	tst = 4;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}