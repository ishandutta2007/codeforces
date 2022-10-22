#include<bits/stdc++.h>
const int maxn = 51;
const int mod = 1e9 + 7;
typedef long long ll;
using std::cin;
int n, d[maxn];
int dp[51][834280];
int map[3][maxn][maxn][maxn][maxn], tot;
struct state
{
	int a0, a1, a2, a3;
	int b0, b1, b2, b3;
	inline operator int() const {
		return map[a3 || b3 ? a3 ? 1 : 2 : 0][a1][a2][b1][b2];
	}
	inline bool good() const {
		return !a1 && !a2 && !a3 && !b1 && !b2 && !b3;
	}
} naive;
inline int dfs(int now, state & x) {
	if(now == n + 1) {
		return x.good();
	}
	x.a0 = x.b0 = 0;
	int & ans = dp[now][(int) x];
	if(~ans) return ans;
	state next = x;
	int * a = (int*) &next;
	const auto go = [&](int min, int rem, state s) {
		int * a = (int*) & s;
		if(min >= 4) {
			if(a[0] || a[1] || a[2] || a[3]) return 0;
			memcpy(a, a + 4, 4 << 2), memset(a + 4, 0, 4 << 2);
		}
		if(rem) a[4 + rem] += 1;
		return dfs(now + 1, s);
	};
	int w = 1; int cnt[8] = {};
	const auto push = [&](int x) { w *= a[x], w /= ++cnt[x], -- a[x], ++ a[x - 1]; };
	const auto pop = [&](int x) { ++ a[x], -- a[x - 1], w *= cnt[x]--, w /= a[x]; };
	ans = 0;
	for(int i = 0;i < 8;++i) if(a[i]) {
		push(i);
		for(int j = i;j < 8;++j) if(a[j] && j / 4 != i / 4) {
			push(j);
			if(d[now] == 3) for(int k = j;k < 8;++k) if(a[k]) {
				push(k);
				ans = (ans + (ll) w * go(i, d[now] - 3, next)) % mod;
				pop(k);
			}
			ans = (ans + (ll) w * go(i, d[now] - 2, next)) % mod;
			pop(j);
		}
		ans = (ans + (ll) w * go(i, d[now] - 1, next)) % mod;
		pop(i);
	}
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n;
	int tot = 0;
	for(int a1 = 0;a1 < n;++a1) {
		for(int a2 = 0;a2 < n;++a2) {
			for(int a3 = 0;a3 < 2;++a3) if(a1 + a2 + a3 < n){
				for(int b1 = 0;b1 < n;++b1) {
					for(int b2 = 0;b2 < n;++b2) {
						for(int b3 = 0;b3 < 2;++b3) if(a1 + a2 + a3 + b1 + b2 + b3 < n && a3 + b3 < 2){
							map[a3 || b3 ? a3 ? 1 : 2 : 0][a1][a2][b1][b2] = ++ tot;
						}
					}
				}
			}
		}
	}
	memset(dp, -1, sizeof dp);
	for(int i = 1;i <= n;++i) {
		cin >> d[i];
	}
	(d[1] == 2 ? naive.a2 : naive.a3) += 1;
	std::cout << dfs(2, naive) << '\n';
}