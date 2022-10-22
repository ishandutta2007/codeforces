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

const ll MAXN = 200 + 5;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll MAXK = 1000 + 5;

int A[MAXN], n, tk;
ll dp[MAXN][MAXK], tdp[MAXN][MAXK];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> tk;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A + 1, A + n + 1);
	tdp[0][0] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= tk; k++) {
				ll t = j * (A[i] - A[i - 1]), t2 = t + A[i] - A[i - 1], t3 = t - A[i] + A[i - 1];
				dp[j][k] = 0;
				if (k >= t) dp[j][k] += j * tdp[j][k - t];	
				if (k >= t2) dp[j][k] += (j + 1) * tdp[j + 1][k - t2];	
				if (j && k >= t3) dp[j][k] += tdp[j - 1][k - t3];
				if (k >= t) dp[j][k] += tdp[j][k - t];
				dp[j][k] %= MOD;
			}
		}

		for (int j = 0; j <= n; j++)
			for (int k = 0; k <= tk; k++)
				tdp[j][k] = dp[j][k];
	}

	ll ans = 0;
	for (int i = 0; i <= tk; i++) ans += dp[0][i];
	cout << ans % MOD << endl;
	return 0;
}