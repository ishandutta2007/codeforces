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

struct seg {
	int a, b, n;
	seg(int aa = 0, int bb = 0, int nn = 0): a(aa), b(bb), n(nn) {}
	bool operator < (const seg &s) const {
		return a < s.a || (a == s.a && b < s.b);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<seg> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].a >> a[i].b;
		a[i].n = i;
	}
	sort(a.begin(), a.end());
	int x = -1;

	int mx = a[0].b;
	for (int i = 1; i < n && x == -1; i++) {
		if (mx < a[i].a) {
			x = mx;
		}
		mx = max(mx, a[i].b);
	}

	if (x == -1) {
		cout << "-1\n";
		return;
	}

	vector<int> ans(n, 2);
	for (int i = 0; i < n; i++) {
		if (a[i].b <= x) ans[a[i].n] = 1;
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	//tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}