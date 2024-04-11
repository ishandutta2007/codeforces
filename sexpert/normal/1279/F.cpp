#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int MAXN = 1e6 + 5;
int n, k, l, a[MAXN];

ii solve(int cost) {
	vector<ii> dp(n+1);
	dp[0] = {0,0};
	for(int i = 1; i <= n; i++) {
		auto p = dp[i-1];
		p.first += a[i];
		dp[i] = p;
		int j = max(i - l, 0);
		p = dp[j];
		p.first += i - j - cost;
		p.second++;
		dp[i] = max(p, dp[i]);
	}
	return dp[n];
}

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
	cin >> n >> k >> l;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++)
		a[i] = (s[i - 1] >= 'a' && s[i -1] <= 'z');
ll ans = n + 10;
	for(int rp = 0; rp < 2; rp++) {
		int lo = 0, hi = n + 10;
		while(lo < hi) {
			int mi = (lo + hi + 1)/2;
			auto p = solve(mi);
			if(p.second >= k)
				lo = mi;
			else
				hi = mi - 1;
		}
		auto p = solve(lo);
		ans = min(ans, n - ((ll)p.first + (ll)k * lo));
        for(int i = 1; i <= n; i++){ a[i] = 1 - a[i]; }//cout<<a[i]<<' ';}
	}
	cout << ans << '\n';
}