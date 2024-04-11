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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> num(30, 0);
	for (char ch: s) {
		num[ch - 'A']++;
	}
	int mn = n;
	for (int i = 0; i < k; i++) {
		mn = min(mn, num[i]);
	}
	cout << mn * k << "\n";
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}