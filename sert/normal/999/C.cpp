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
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<bool> u(n, false);
	for (int ch = 'a'; ch <= 'z'; ch++) {
		for (int i = 0; i < n; i++) {
			if (s[i] == ch && k > 0) {
				k--;
				u[i] = true;
			}
		}
	}
	string t;
	for (int i = 0; i < n; i++) {
		if (!u[i]) {
		 	t.push_back(s[i]);
		}
	}
	cout << t << "\n";
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