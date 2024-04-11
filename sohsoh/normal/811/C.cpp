#include <bits/stdc++.h>
 
using namespace std;
 
typedef int ll;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 5000 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A[MAXN], val[MAXN][MAXN] = {0}, L_ind[MAXN], R_ind[MAXN] = {0}, dp[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(L_ind, L_ind + MAXN, INF);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i], L_ind[A[i]] = min(L_ind[A[i]], i), R_ind[A[i]] = i;
	for (int L = 1; L <= n; L++) {
		bool ok = true;
		ll mx = 0, tval = 0;
		for (int R = L; R <= n; R++) {
			mx = max(mx, R_ind[A[R]]);
			if (L_ind[A[R]] < L) ok = false;
			if (L_ind[A[R]] == R) tval ^= A[R];
			val[L][R] = tval;
			if (!ok || mx > R) val[L][R] = -1 * INF;
		}
	}

	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		for (int L = i; L > 0; L--) dp[i] = max(dp[i], val[L][i] + dp[L - 1]);
	}

	cout << dp[n] << endl;
	return 0;
}