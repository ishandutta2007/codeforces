#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
map<long long, bool> vis;
map<long long, pair<int, long long> > dp;
long long cub[100009];
pair<int, long long> solve(long long n) {
	if (n == 0) return make_pair(0, 0LL);
	if (vis[n]) return dp[n];
	int ptr = lower_bound(cub, cub + 100002, n + 1) - cub - 1;
	pair<int, long long> r1 = solve(n - cub[ptr]); r1.first++; r1.second += cub[ptr];
	pair<int, long long> r2 = ptr >= 2 ? solve(cub[ptr] - cub[ptr - 1] - 1) : make_pair(0, 0LL);
	if (ptr >= 2) r2.first++, r2.second += cub[ptr - 1];
	pair<int, long long> ret = max(r1, r2);
	vis[n] = true;
	dp[n] = ret;
	return ret;
}
long long x;
int main() {
	for (int i = 0; i <= 100001; i++) cub[i] = 1LL * i * i * i;
	cin >> x;
	pair<int, long long> ret = solve(x);
	cout << ret.first << ' ' << ret.second << endl;
	return 0;
}