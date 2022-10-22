// \_()_/
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

const ll MAXN = 50 + 10;
const ll INF = 8e18;
ll MOD = 0; // 998244353; // 1e9 + 9;

int n;
ll P_inv[MAXN][MAXN * MAXN], Delta[MAXN][MAXN * MAXN], P_ans[MAXN], ans[MAXN];

inline void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> MOD;
	P_inv[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < MAXN * MAXN / 2; k++) {
			for (int j = 0; j < min(k + 1, i); j++)
				mkey(P_inv[i][k] += P_inv[i - 1][k - j]);
		}
		
		for (int k = MAXN * MAXN / 2 - 1; k >= 0; k--) {
			Delta[i][k] = Delta[i][k + 1];
			for (int j = k; j < MAXN * MAXN / 2; j++) mkey(Delta[i][k] += P_inv[i][j - k] * P_inv[i][j] % MOD);
		}	
	}
	
	for (int i = 4; i <= n; i++) {
		for (int s1 = 0; s1 < i; s1++)
			for (int s2 = s1 + 1; s2 < i; s2++) 
				mkey(P_ans[i] += Delta[i - 1][s2 - s1 + 1]);
	}

	for (int i = 4; i <= n; i++) mkey(ans[i] = P_ans[i] + ans[i - 1] * i % MOD);
	cout << ans[n] << endl;
	return 0;
}