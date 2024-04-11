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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 300 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, A[MAXN], dp[MAXN][MAXN][MAXN], ps[MAXN]; // ind, bad, components
map<int, int> mp;

inline bool is_prime(int n) {
	if (n == 1) return false;
	int sq = sqrt(n);
	for (int i = 2; i <= sq; i++) if (n % i == 0) return false;
	return true;
}

inline int Cnt(int n, int p) {
	int ans = 1;
	while (n % p == 0) {
		n /= p;
		if (ans == 1) ans = p;
		else ans = 1;
	}

	return ans;
}

inline void Add(int n) {
	int sq = sqrt(n), ans = 1;
	for (int i = 1; i <= sq; i++) {
		if (n % i) continue;
		if (is_prime(i)) ans *= Cnt(n, i);
		if (i * i != n && is_prime(n / i)) ans *= Cnt(n, n / i);
	}

	mp[ans]++;
}

inline void mkey(int& a) {
	if (a >= MOD) a -= MOD;
}

inline void Push(int i, int j, int b, int k) {
	int n = ps[i - 1] + j;
	if (j < A[i]) {
		int B = j + k, M = b - (j - k), N = n + 1 - B - M;
		if (M < 0 || B < 0 || N < 0) return;
		mkey(dp[n + 1][b + 1][k] += 1ll * dp[n][b][k] * B % MOD);
		mkey(dp[n + 1][b][k + 1] += 1ll * dp[n][b][k] * N % MOD);
		if (b) mkey(dp[n + 1][b - 1][k + 1] += 1ll * dp[n][b][k] * M % MOD);
	} else {
		int M = b, N = n + 1 - M;
		if (M < 0 || N < 0) return;
		mkey(dp[n + 1][b][1] += 1ll * dp[n][b][k] * N % MOD);
		if (b) mkey(dp[n + 1][b - 1][1] += 1ll * dp[n][b][k] * M % MOD);
	} 
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		Add(x);
	}

	int m = n;
	n = mp.size();
	int ind = 1;
	for (pll e : mp) {
		ps[ind] = e.Y + ps[ind - 1];
		A[ind++] = e.Y;
	}

	dp[1][0][1] = 1;
	int t = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= A[i]; j++) {
			for (int b = 0; b < t; b++) {
				for (int k = 1; k <= j; k++) {
					Push(i, j, b, k);	
				}
			}

			t++;
		}
	}

	int ans = 0;
	for (int i = 1; i <= A[n]; i++) mkey(ans += dp[m][0][i]);
	cout << ans << endl;
	return 0;
}