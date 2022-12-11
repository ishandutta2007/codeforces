#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int INF = (int)1e9 + 41;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int bal = n * 2;
	vector<int> k(n * 4, -INF);
	k[n * 2] = n;
	for (int i = n - 1; i >= 0; i--) {
		bal += (s[i] == '0' ? -1 : 1);
		k[bal] = max(k[bal], i);
	}
	int sum = bal;
	bal = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {	
		ans = max(ans, k[sum - bal] - i);
		bal += (s[i] == '0' ? -1 : 1);
	}
	cout << ans << "\n";
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