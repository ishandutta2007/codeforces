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

bool check(string t, vector<string> a) {
	string ans(a.size(), '!');
	int n = t.length();

	vector<vector<bool>> u(2, vector<bool>(n, false));
	for (int i = 0; i < (int)a.size(); i++) {
		string s = a[i];
		int len = s.length();

		if (t.substr(0, len) == s && !u[0][len]) {
			u[0][len] = true;
			ans[i] = 'P';
		} else if (t.substr(n - len, len) == s && !u[1][len]) {
			u[1][len] = true;
			ans[i] = 'S';
		} else {
			return false;
		}
	}
	cout << ans << "\n";	
	return true;
}

void solve() {
	int n;
	cin >> n;
	vector<string> s(n * 2 - 2);
	for (auto &ss : s) cin >> ss;	
	string s1 = "#", s2 = "#";
	for (auto &ss : s) {
		if ((int)ss.length() + 1 == n) {
			if (s1 == "#") s1 = ss;
			else s2 = ss;
		}
	}

	if (s1.substr(0, n - 2) == s2.substr(1, n - 2)) {
		string t = s2;
		t.push_back(s1.back());
		if (check(t, s)) return;
	} 

	if (s2.substr(0, n - 2) == s1.substr(1, n - 2)) {
		string t = s1;
		t.push_back(s2.back());
		if (check(t, s)) return;
	}

	exit(11);
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