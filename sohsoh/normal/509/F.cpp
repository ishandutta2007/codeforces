#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 500 + 10;
const ll MOD = 1e9 + 7;

int n, A[MAXN], dp[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> A[i];

	for (int l = n; l > 0; l--) {
		dp[l][l] = 1;
		for (int r = l + 1; r <= n; r++) {
			dp[l][r] = dp[l + 1][r];
			for (int mid = l + 1; mid < r; mid++) {
				if (A[mid + 1] > A[l + 1]) {
					dp[l][r] = (dp[l][r] + 1ll * dp[l + 1][mid] * dp[mid][r]) % MOD;
				}
			}
		}
	}

	cout << dp[1][n] << endl;
	return 0;
}