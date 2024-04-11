//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 16;
const int V = 4;
const int M = 505;
const int X = (1 << 16) - 1;
const int mod = 1e9 + 7;
int dp[M][1 << N];
int c[1 << N], d[1 << N];
int fa[1 << N], fb[1 << N];
int ans[1 << N];
int cid[N * N];
vector<int> to_plus[N];
string s;
int nx = 0;
void add(int a[1 << N], int b[1 << N]) {
	for (int i = 0; i < (1 << N); ++i)
		a[i] = (a[i] + b[i]) % mod;
}
void flip(int a[1 << N]) {
	for (int i = 0; i < (1 << N); ++i)
		d[X ^ i] = a[i];
	for (int i = 0; i < (1 << N); ++i)
		a[i] = d[i];
}
void get_sum(int a[1 << N], int con[1 << N]) {
	for (int i = 0; i < (1 << N); ++i)
		con[i] = a[i];
	for (int i = 0; i < (1 << 4); ++i)
		for (int mask = 0; mask < (1 << N); ++mask)
			if (mask >> i & 1)
				con[mask] = (con[mask] + con[mask ^ (1 << i)]) % mod;
}
void merge(int a[1 << N], int b[1 << N]) {
	memset(c, 0, sizeof c);
	get_sum(a, fa);
	get_sum(b, fb);
	for (int i = 0; i < (1 << N); ++i)
		c[i] = fa[i] * 1LL * fb[i] % mod;
	for (int i = 0; i < (1 << N); ++i)
		if (__builtin_popcount(i) & 1)
			c[i] = (-c[i] + mod) % mod;
	get_sum(c, c);
	for (int i = 0; i < (1 << N); ++i)
		if (__builtin_popcount(i) & 1)
			c[i] = (-c[i] + mod) % mod;
}
void pr(int a[1 << N]) {
	for (int i = 0; i < (1 << N); ++i)
		if (a[i])
			cout << i << ' ' << a[i] << '\n';	
}
int solve(int b, int e) {
//	cout << b << ' ' << e << endl;
	int id = nx++;
	if (b + 1 == e) {
		int p = cid[s[b]];
		for (auto x: to_plus[p])
			dp[id][x]++;
		return id;
	}
	int l = 0, r = 0;
	int cnt = 0;
	int com = 0;
	for (int i = b; i < e; ++i) {
		if (s[i] == '(')
			cnt++;
		if (s[i] == ')')
			cnt--;
		if (cnt == 0 && (s[i] == '&' || s[i] == '|' || s[i] == '?')) {
			com = s[i];
			l = solve(b + 1, i - 1);
			r = solve(i + 2, e - 1);
			break;	
		}
	}
	memset(ans, 0, sizeof ans);
	if (com == '|' || com == '?') {
//	cout << l << ' ' << r << ' ' << com << '\n';
		merge(dp[l], dp[r]);
		add(ans, c);
//		pr(dp[r]);
	}
	if (com == '&' || com == '?') {
		flip(dp[l]);
		flip(dp[r]);
		merge(dp[l], dp[r]);
		flip(c);
		add(ans, c);	
	}
	for (int i = 0; i < (1 << N); ++i) {
		dp[id][i] = ans[i];
	}
	return id;
}
int main() {
	for (int i = 'a'; i <= 'd'; ++i)
		cid[i] = i - 'a' + 4;
	for (int i = 'A'; i <= 'D'; ++i)
		cid[i] = i - 'A';
	cid['?'] = 8;
	for (int i = 'A'; i <= 'D'; ++i) {
		int id = cid[i];
		int res = 0;
		for (int mask = 0; mask < (1 << 4); ++mask)
			if (mask >> id & 1)
				res |= 1 << mask;
		to_plus[id].push_back(res);
		to_plus[id + 4].push_back(X ^ res);
		to_plus[8].push_back(res);
		to_plus[8].push_back(X ^ res);
	}
	cin >> s;
	int n = (int) s.size();
	solve(0, n);
	int m; cin >> m;
	int want = 0, dont_want = 0;
	for (int i = 0; i < m; ++i) {
		int mask = 0;
		for (int k = 0; k < 4; ++k) {
			int x; cin >> x;
			mask += (1 << k) * x;
		}
		int res; cin >> res;
		if (res)
			want |= 1 << mask;
		else
			dont_want |= 1 << mask;
	}
	int p = 0;
	for (int i = 0; i < (1 << N); ++i) {
		if ((i & want) == want && ((i ^ X) & dont_want) == dont_want) {
			p = (p + dp[0][i]) % mod;	
		}
	}
	cout << p << endl;
	return 0;
}