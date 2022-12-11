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
	map<int, ll> mp;
	while (n--) {
		string s;
		cin >> s;
		int bal = 0;
		int minbal = 0;
		for (char ch : s) {
			bal += (ch == '(' ? 1 : -1);
			minbal = min(bal, minbal);
		}
		if (minbal >= min(bal, 0)) mp[bal]++;
	}	
	ll ans = 0;
	for (auto it : mp) {
		if (it.first >= 0)
			ans += it.second * mp[-it.first];
	}
	cout << ans << "\n";
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