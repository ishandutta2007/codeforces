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
	map<char, int> mp;
	for (int ch = 'a'; ch <= 'z'; ch++) {
		mp[ch] = cnt(s, ch);
	}
	int n1 = min(min(mp['o'], mp['n']), mp['e']);
	int n0 = min(min(mp['o'], mp['e']) - n1, min(mp['z'], mp['r']));
	for (int i = 0; i < n1; i++) cout << "1 ";
	for (int i = 0; i < n0; i++) cout << "0 ";
	cout << "\n";
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