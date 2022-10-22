// orz ?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define int			ll
#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;
#define mp			make_pair

const ll MAXN = 1e6 + 10;
const ll MOD = 998244353;

int row_cnt[MAXN], col_cnt[MAXN], r, c, n, m, k, R[2][MAXN], C[2][MAXN],
    bad_row_cnt, bad_col_cnt, C1, C2, poww[MAXN];
map<pll, int> G;

inline int f(int i, int j, int col) {
	return (i + j) % 2 == col - 1;
}

inline void remove(int i, int j) {
	int col = G[mp(i, j)];
	if (col < 1) return;

	G[mp(i, j)] = 0;
	
	row_cnt[i]--;
	col_cnt[j]--;

	if (row_cnt[i] == 0) r--;
	if (col_cnt[j] == 0) c--;
	
	R[f(i, j, col)][i]--, bad_row_cnt -= (R[f(i, j, col)][i] == 0 && R[1 - f(i, j, col)][i]);
	C[f(i, j, col)][j]--, bad_col_cnt -= (C[f(i, j, col)][j] == 0 && C[1 - f(i, j, col)][j]);

	if (col == (i + j) % 2 + 1) C1--;
	else C2--;
}

int z;

inline void add(int i, int j, int col) {
	G[mp(i, j)] = col;

	row_cnt[i]++;
	col_cnt[j]++;

	if (row_cnt[i] == 1) r++;
	if (col_cnt[j] == 1) c++;

	R[f(i, j, col)][i]++, bad_row_cnt += (R[f(i, j, col)][i] == 1 && R[1 - f(i, j, col)][i]);
	C[f(i, j, col)][j]++, bad_col_cnt += (C[f(i, j, col)][j] == 1 && C[1 - f(i, j, col)][j]);

	if (col == (i + j) % 2 + 1) C1++;
	else C2++;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	poww[0] = 1;
	for (int i = 1; i < MAXN; i++)
		poww[i] = poww[i - 1] * 2 % MOD;

	cin >> n >> m >> k;
	for (z = 1; z <= k; z++) {
		int i, j, col;
		cin >> i >> j >> col;	
		remove(i, j);

		col++;
		if (col) add(i, j, col);
	
		if (bad_col_cnt && bad_row_cnt) cout << 0 << endl;
		else if (bad_col_cnt) cout << poww[n - r] << endl;
		else if (bad_row_cnt) cout << poww[m - c] << endl;
		else cout << ((poww[n - r] + poww[m - c]) % MOD - 2 + min(C1, 1ll) + min(C2, 1ll) + MOD) % MOD << endl;
	}
	return 0;
}