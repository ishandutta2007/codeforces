#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void solve() {
	string s;
	cin >> s;
	if (s == "0") {
		cout << "0\n";
		return;
	}
	int sum = accumulate(all(s), 0, [&] (int sum, char x) { return sum + x - '0'; });
	int len = s.length() - (sum == 1 ? 1 : 0);
	cout << (len + 1) / 2 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 3;
	for (int i = 1; i < T; i++) solve();	
#endif
}