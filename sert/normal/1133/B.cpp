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

int getT() {
	int h, m;
	scanf("%d:%d", &h, &m);
	return h * 60 + m;
}

void solve() {	
	int n, k;
	cin >> n >> k;
	vector<int> a(k, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x % k]++;
	}
	int ans = a[0] / 2;
	if (k % 2 == 0) ans += a[k / 2] / 2;
	for (int i = 1; i < k - i; i++) {
		ans += min(a[i], a[k - i]);
	}
	cout << ans * 2 << "\n";
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