#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 700 + 3;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, A[MAXN];
bool dp[MAXN][MAXN][2], GCD[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			GCD[i][j] = (__gcd(A[i], A[j]) > 1);

	for (int i = 1; i <= n; i++) GCD[0][i] = GCD[i][0] = GCD[i][n + 1] = GCD[n + 1][i] = true;
	for (int sz = 1; sz <= n; sz++) {
		for (int L = 1; L + sz - 1 <= n; L++) {
			int R = L + sz - 1;
			if (sz == 1) {
				dp[L][R][0] = GCD[L][L - 1];
				dp[L][R][1] = GCD[L][L + 1];
				continue;
			}

			for (int mid = L; mid <= R; mid++) {
				bool can = true;
				if (mid > L) can &= dp[L][mid - 1][1];
				if (mid < R) can &= dp[mid + 1][R][0];
				dp[L][R][0] |= (can & GCD[mid][L - 1]);
				dp[L][R][1] |= (can & GCD[mid][R + 1]);
			}

		}
	}

	if (dp[1][n][0]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}