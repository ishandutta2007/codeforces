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

struct KK {
	int st, fn, ind;
	bool operator<(const KK &a) const {
		return st < a.st || (st == a.st && fn > a.fn);
	}
};

void solve() {
	int n;
	cin >> n;
	vector<KK> a(n);
	for (int i = 0; i < n; i++) {
		int st, fn;
		cin >> st >> fn;
		a[i] = {st, fn, i + 1};
	}
	sort(a.begin(), a.end());
	KK r = {0, -1, -1};
	for (int i = 0; i < n; i++) {
		if (r.fn >= a[i].fn) {
			cout << a[i].ind << " " << r.ind << "\n";
			return;
		}
		if (a[i].fn > r.fn) r = a[i];
	}
	cout << "-1 -1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
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