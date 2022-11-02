#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()
 
#define int ll
 
int mod;
 
int add(int a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
	return a;
}
 
int sub(int a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
	return a;
} 
 
int mul(int a, int b) {
	return (ll) a * b % mod;
}
 
using matrix = vector<vector<int>>;
 
matrix mul(const matrix & a, const matrix & b) {
	matrix c(a.size(), vector<int> (b[0].size(), 0));
	assert(a[0].size() == b.size());
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = 0; j < (int)b[0].size(); j++) {
			for (int k = 0; k < (int)a[0].size(); k++) {
				c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
			}
		}
	}
	return c;
} 
 
matrix binpow(matrix a, ll n) {
	assert(a.size() == a[0].size());
	matrix ans(a.size(), vector<int> (a.size(), 0));
	for (int i = 0; i < (int)a.size(); i++) {
		ans[i][i] = 1;
	}
	while (n) {
		if (n & 1) {
			ans = mul(ans, a);
		}
		a = mul(a, a);
		n >>= 1;
	}
	return ans;
}
 
signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
	int x, y, dx, dy, t;
	cin >> mod >> x >> y >> dx >> dy >> t;
	x--;
	y--;
	dx = ((dx % mod) + mod) % mod;
	dy = ((dy % mod) + mod) % mod;
	matrix fpow(6, vector<int> (6, 0));
	// 0 - x, 1 - y, 2 - dx, 3 - dy, 4 - t, 5 - 1
	{
		// x = x + dx + x + y + t
		fpow[0][0] = 2;
		fpow[0][1] = 1;
		fpow[0][2] = 1;
		fpow[0][4] = 1;
		fpow[0][5] = 2;
	}
	{
		// y = y + dy + x + y + t
		fpow[1][0] = 1;
		fpow[1][1] = 2;
		fpow[1][3] = 1;
		fpow[1][4] = 1;
		fpow[1][5] = 2;
	}
	{
		// dx = dx + x + y + t
		fpow[2][0] = 1;
		fpow[2][1] = 1;
		fpow[2][2] = 1;
		fpow[2][4] = 1;
		fpow[2][5] = 2;
	}
	{
		// dy = dy + x + y + t
		fpow[3][0] = 1;
		fpow[3][1] = 1;
		fpow[3][3] = 1;
		fpow[3][4] = 1;
		fpow[3][5] = 2;
	}
	{
		// t = t + 1
		fpow[4][4] = 1;
		fpow[4][5] = 1;
	}
	{
		// 1 = 1
		fpow[5][5] = 1;
	}
	fpow = binpow(fpow, t);
	vector<vector<int>> fans(6, vector<int> (1, 0));
	fans[0][0] = x;
	fans[1][0] = y;
	fans[2][0] = dx;
	fans[3][0] = dy;
	fans[4][0] = 0;
	fans[5][0] = 1;
	fans = mul(fpow, fans);
	cout << fans[0][0] + 1 << " " << fans[1][0] + 1 << endl;
	return 0;
}