#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		sort(all(s));
		bool ok = true;
		for (int i = 1; i < (int)s.length(); i++) {
			ok &= (s[i] - s[i - 1]) == 1;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 1;
	for (int i = 1; i < T; i++) solve();	
#endif
}