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
	int n, k, mx;
	cin >> n >> k >> mx;
	vector<int> a(n * k);
	for (auto &x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());	
	ll sum = a[0];
	int lft = n - 1;
	int bal = k - 1;
	for (int i = 1; i < n * k; i++) {
		if (lft == 0) {
			cout << sum << "\n";
			return;
		}
		if (a[i] - a[0] > mx) {
			cout << "0\n";
			return;
		}
		if (a[i + lft] - a[0] <= mx && bal > 0) {
			bal--;
			continue;
		}
		bal += k - 1;
		lft--;
		sum += a[i];
	}
	cout << sum << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
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