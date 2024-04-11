#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int cnt(const string &s, char ch) {
	return accumulate(all(s), 0, [&] (int sum, char x) { return sum + (int)(x == ch); });
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	cout << (s[0] == 'S' && s.back() == 'F' ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 2;
	for (int i = 1; i < T; i++) solve();	
#endif
}