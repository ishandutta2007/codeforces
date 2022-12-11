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
	string s;
	cin >> n >> s;
	bitset<10> b;
	for (int i = 0; i < n; i++) {
		if ('0' <= s[i] && s[i] <= '9') b['9' - s[i]] = 0;
		else if (s[i] == 'R') {
			int pos = 0;
			while (b[pos] == 1) pos++;
			b[pos] = 1;
		} else {
			int pos = 9;
			while (b[pos] == 1) pos--;
			b[pos] = 1;
		}
	}
	cout << b << endl;
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
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}