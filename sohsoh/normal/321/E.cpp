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

const ll MAXN = 4e3 + 10;
const ll MAXK = 800 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXK][MAXN], C[MAXN][MAXN];
int M[MAXN][MAXN], n, k;

void O_o(int i, int L, int R, int TL, int TR) {
	if (R < L) return;
	
	int mid = (L + R) >> 1, T = 0;
	for (int k = TL; k <= min(TR, mid - 1); k++) {
		ll tans = dp[i - 1][k] + C[k + 1][mid];
		if (tans <= dp[i][mid]) {
			dp[i][mid] = tans;
			T = k;
		}
	}

	O_o(i, L, mid - 1, TL, T);
	O_o(i, mid + 1, R, T, TR);
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < MAXK; i++)
		for (int j = 0; j < MAXN; j++)
			dp[i][j] = INF;
	char c;
	do c = getchar();
	while (c != '\n');
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			do c = getchar();
			while (c < '0' || c > '9');
			M[i][j] = int(c - '0');
		}
	}

	for (int R = 1; R <= n; R++) {
		ll s = 0;
		for (int L = R - 1; L > 0; L--) {
			s += M[L][R];
			C[L][R] = C[L][R - 1] + s;
		}
	}
	
	dp[0][0] = 0;
	for (int i = 1; i <= k; i++)
		O_o(i, 1, n, 0, n);
	printf("%lld", dp[k][n]);
	return 0;
}