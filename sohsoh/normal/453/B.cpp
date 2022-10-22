#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

using namespace std;
 
typedef int ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
const int MAXN = 101;
const int P = 16;
const int MAXP = 65536;
const int INF = 1e7;

int primes[P] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}, n;
pll dp[MAXN + 1][MAXP];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < MAXP; i++) dp[0][i] = {0, 0};
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < MAXP; j++) dp[i][j] = {INF, INF};
		ll x;
		cin >> x;
		for (int lst = 1; lst < 59; lst++) {
			ll factor_msk = 0;
			for (int j = 0; j < P; j++) if (lst % primes[j] == 0) factor_msk ^= (1 << j);
			for (int prev_msk = 0; prev_msk < MAXP; prev_msk++) {
				if (prev_msk & factor_msk) continue;
				dp[i][(prev_msk ^ factor_msk)] = min(dp[i][prev_msk ^ factor_msk], {dp[i - 1][prev_msk].X + abs(x - lst), lst});
			}
		}	
	}

	ll msk = min_element(dp[n], dp[n] + MAXP) - dp[n];
	ll ind = n;
	stack<ll> ans;
	while (ind > 0) {
		ans.push(dp[ind][msk].Y);
		for (int j = 0; j < P; j++) if (ans.top() % primes[j] == 0) msk ^= (1 << j);
		ind--;
	}

	while (!ans.empty()) cout << ans.top() << sep, ans.pop();
	cout << endl;
	return 0;
}