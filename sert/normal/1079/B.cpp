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
	string s;
	cin >> s;
	int n = s.length();
	if (n <= 20) {
		cout << 1 << " " << n << "\n";
		cout << s << "\n";
		return;
	}
	
	int h = (n + 19) / 20;
	int w = (n + h - 1) / h;

	cout << h << " " << w << "\n";	

	int cur = 0;
	for (int i = 0; i < h; i++) {
		if (i >= n % h && n % h > 0) {
			cout << "*" + s.substr(cur, w - 1);
			cur += w - 1;
		} else {
			cout << s.substr(cur, w);
			cur += w;
		}
		cout << "\n";
	}
}

int main() {
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