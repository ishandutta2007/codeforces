#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
using LL = long long;
int main() {
	int n; cin >> n;
	vector<int> a(n + 1, -1e9);
	FOR(i, 1, n) {
		cin >> a[i]; 
		a[i] -= i;
	}
	auto b = a;
	sort(b.begin(), b.end());
	vector<LL> dp(n + 1);
	FOR(i, 1, n) {
		vector<LL> nxt(n + 1, 1e18);
		FOR(j, 1, n) nxt[j] = min(nxt[j - 1], dp[j] + abs(a[i] - b[j]));
		dp = nxt;
	}
	LL ans = 1e18;
	FOR(j, 1, n) ans = min(ans, dp[j]);
	cout << ans << "\n";
}