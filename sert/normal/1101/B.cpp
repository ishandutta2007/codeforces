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
	int p1, p2, p3, p4;
	p1 = p2 = p3 = p4 = -1;
	for (int i = 0; i < n && p1 == -1; i++) if (s[i] == '[') p1 = i;
	for (int i = p1 + 1; i < n && p2 == -1; i++) if (s[i] == ':') p2 = i;
	for (int i = n - 1; i >= 0 && p4 == -1; i--) if (s[i] == ']') p4 = i;
	for (int i = p4 - 1; i >= 0 && p3 == -1; i--) if (s[i] == ':') p3 = i;
	if (min(p3, p2) == -1 || min(p1, p4) == -1 || p2 >= p3) {
		cout << "-1\n";
		return;
	}
	int ans = 4;
	for (int i = p2 + 1; i < p3; i++) {
		if (s[i] == '|') ans++;
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
	tst = 2;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}