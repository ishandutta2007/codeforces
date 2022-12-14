
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;

const int N = (int) 2005, mod = (int) 998244353;
int m = 64;
vector<pair<int, int>> queries[N];
struct matrix {
	int a[64][64];
	matrix() { memset(a, 0, sizeof a); }
};
struct row {
	int a[64];
	row() { memset(a, 0, sizeof a); }
};
matrix mul(matrix a, matrix b) {
	matrix res;
	for (int i = 0; i < m; ++i)
		for (int k = 0; k < m; ++k) if (a.a[i][k])
			for (int j = 0; j < m; ++j) if (b.a[k][j])
				res.a[i][j] = (res.a[i][j] + (LL) a.a[i][k] * b.a[k][j]) % mod;
	return res;
}
row mul(row a, matrix b) {
	row res;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			res.a[j] = (res.a[j] + a.a[i] * (LL) b.a[i][j]) % mod;
	return res;
}
matrix add(matrix a, matrix b) {
	matrix res;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j)
			res.a[i][j] = (a.a[i][j] + b.a[i][j]) % mod;
	return res;
}
matrix c[3];
matrix p[30];
row pw(row cur, int x) {
	for (int j = 0; j < 30; ++j)
		if (x >> j & 1)
			cur = mul(cur, p[j]);
	return cur;
}
int dp[4], odp[4], f[3][3], a[N];
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> a[j];
	}
	int q;
	cin >> q;
	for (int j = 0; j < q; ++j) {
		int x, y, c;
		cin >> x >> y >> c;
		--x, --c;
		queries[x].push_back(mp(y, c));
	}
	for (int j = 0; j < n; ++j)
		sort(ALL(queries[j]));
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> f[i][j];
	for (int col = 0; col < 3; ++col) {
		for (int start = 0; start < m; ++start) {
			int end = (start * 4) % 64;
			set<int> st;
			for (int j = 0; j < 3; ++j) if (f[col][j]) {
				int num = (start >> (j * 2)) & 3;
				st.insert(num);
			}
			int mex = 0;
			while (st.find(mex) != st.end()) ++mex;
			end += mex;
			c[col].a[start][end] = 1;
		}
		p[0] = add(p[0], c[col]);
	}
	for (int j = 1; j < 30; ++j)
		p[j] = mul(p[j - 1], p[j - 1]);
	dp[0] = 1;
	for (int strip = 0; strip < n; ++strip) {
		row cur;
		cur.a[63] = 1;
		int use = 0;
		for (auto x : queries[strip]) {
			cur = pw(cur, x.first - use - 1);
			cur = mul(cur, c[x.second]);
			use = x.first;
		}
		cur = pw(cur, a[strip] - use);
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		for (int cur_use = 0; cur_use < 4; ++cur_use) {
			int sum = 0;
			for (int s = cur_use; s < m; s += 4)
				sum = (sum + cur.a[s]) % mod;
			for (int last = 0; last < 4; ++last) {
				dp[last ^ cur_use] = (dp[last ^ cur_use] + (LL) sum * odp[last]) % mod;	
			}
		}
	}
	cout << dp[0] << '\n';
}