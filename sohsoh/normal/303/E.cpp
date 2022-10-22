#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef double ld;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 80 + 2;

ld dp[MAXN][MAXN][MAXN], ans[MAXN][MAXN][MAXN], fans[3 * MAXN][3 * MAXN], f_p[MAXN], f_i[MAXN];
int c_ind = 0, n, L[MAXN], R[MAXN];
vector<int> vec;

inline void clear() {
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			dp[c_ind][i][j] = 0;
	
	c_ind--;
}


inline void add(int ind) {
	c_ind++;

	for (int i = 0; i <= c_ind; i++) {
		for (int j = 0; j <= c_ind - i; j++) {
			dp[c_ind][i][j] = dp[c_ind - 1][i][j] * (1 - f_p[ind] - f_i[ind]);
			if (i) dp[c_ind][i][j] += dp[c_ind - 1][i - 1][j] * f_p[ind];
			if (j) dp[c_ind][i][j] += dp[c_ind - 1][i][j - 1] * f_i[ind];
		}
	}
}

inline void rec(int l, int r) {
	if (l == r) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n - i; j++) {
				ans[l][i + 1][j] += dp[c_ind][i][j] * f_i[l];
			}
		}

		return;
	}

	int mid = (l + r) >> 1;

	for (int i = l; i <= mid; i++) add(i);
	rec(mid + 1, r);
	for (int i = l; i <= mid; i++) clear();

	for (int i = mid + 1; i <= r; i++) add(i);
	rec(l, mid);
	for (int i = mid + 1; i <= r; i++) clear();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> L[i] >> R[i];
		vec.push_back(L[i]);
		vec.push_back(R[i]);
	} 

	dp[0][0][0] = 1;
	sort(all(vec));
	for (int i = 0; i < (int) vec.size() - 1; i++) {
		int l = vec[i], r = vec[i + 1];
		if (l == r) continue;

		for (int j = 1; j <= n; j++) {
			f_p[j] = f_i[j] = 0;
			if (R[j] <= l) f_p[j] = 1;
			else if (L[j] <= l) {
				f_i[j] = ld(r - l) / ld(R[j] - L[j]);
				f_p[j] = ld(l - L[j]) / ld(R[j] - L[j]);
			}
		}

		rec(1, n);
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 0; k <= n; k++)
				for (int x = j; x <= j + k; x++)
					fans[i][x] += (ans[i][j][k] / (k + 1));

	cout << setprecision(10) << fixed << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << fans[i][j] << sep;
		cout << endl;
	}
	return 0;
}