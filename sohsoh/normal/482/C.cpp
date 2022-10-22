#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXM = 20;
const ll MAXN = 50 + 10;

int n;
string S[MAXN];
ll dp[1 << MAXM], fact[MAXN + 3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> S[i];
	fact[0] = 1;
	for (int i = 1; i <= MAXN; i++)
		fact[i] = fact[i - 1] * i;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;

			int tmask = 0;
			for (int k = 0; k < int(S[i].size()); k++)
				if (S[i][k] == S[j][k])
					tmask ^= (1 << k);
			dp[tmask] |= (1ll << i);
		}
	}

	for (int mask = (1 << MAXM) - 1; mask >= 0; mask--)
		for (int j = 0; j < MAXM; j++)
			dp[mask] |= dp[mask | (1 << j)];

	int m = S[1].size();
	ld ans = 0;
	for (int mask = 0; mask < (1 <<m); mask++) {
		int c = __builtin_popcount(mask), cd = __builtin_popcountll(dp[mask]);
		ans += ld(fact[m - c]) * fact[c] / fact[m] * cd / n;
	}

	cout << setprecision(10) << fixed << ans << endl;
	return 0; 
}