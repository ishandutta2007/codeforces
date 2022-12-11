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
	int bal = 0;
	for (int i = 0; i < n; i++) {
		bal += (s[i] == '(' ? 1 : -1);		
	}
	if (abs(bal) != 2) {
		cout << "0\n";
		return;
	}

	if (bal == 2) {
		reverse(s.begin(), s.end());
		for (int i = 0; i < n; i++) {
			s[i] = (s[i] == '(' ? ')' : '(');
		}
	}

	int min_bal = 0;
	bal = 0;
	for (int i = 0; i < n; i++) {
		bal += (s[i] == '(' ? 1 : -1);	
		min_bal = min(min_bal, bal);
	}

	if (min_bal < -2) {
		cout << "0\n";
		return;
	}
	
	int ans = 0;
	int b = 0;
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == ')') b--;
		else b++;
		if (s[i] == ')' && ok) ans++;
		if (b < 0) ok = false;
	}
	cout << ans << "\n";
	
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
	tst = 5;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}