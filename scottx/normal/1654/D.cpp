#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 200005, P = 998244353;
bool isp[N];
vector<tuple<int, int, int> > e[N];
vector<pair<int, int> > ps[N];
int bin[N], mn[N], ans;
int fpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = 1LL * a * a % P)
		if (b & 1) c = 1LL * c * a % P;
	return c;
}
void add(int v) {
	for (auto& x: ps[v]) {
		bin[get<0>(x)] += get<1>(x);
	}
}
void sub(int v) {
	for (auto& x: ps[v]) {
		bin[get<0>(x)] -= get<1>(x);
		mn[get<0>(x)] = min(mn[get<0>(x)], bin[get<0>(x)]);
	}
}
void dfs(int u, int fa, int v) {
	(ans += v) %= P;
	for (auto& x: e[u])
		if (get<0>(x) != fa) {
			add(get<1>(x));
			sub(get<2>(x));
			dfs(get<0>(x), u, 1LL * v * get<1>(x) % P * fpow(get<2>(x), P - 2) % P);
			add(get<2>(x));
			sub(get<1>(x));
		}
}
int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	fill(isp, isp + N, 1);
	isp[0] = isp[1] = 1;
	rep(i, 2, N - 1) if (isp[i]) {
		for (int j = i + i; j < N; j += i) isp[j] = 0;
		for (int j = i; j < N; j += i) {
			int x = j, c = 0;
			while (x % i == 0) x /= i, ++c;
			ps[j].emplace_back(i, c);
		}
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		rep(i, 1, n) e[i].clear();
		fill(bin + 1, bin + n + 1, 0);
		ans = 0;
		int cur = 1;
		rep(i, 2, n) {
			int u, v, x, y;
			scanf("%d%d%d%d", &u, &v, &x, &y);
			cur = 1LL * cur * x % P * y % P;
			e[u].emplace_back(v, y, x);
			e[v].emplace_back(u, x, y);
			for (auto& z: ps[x]) {
				bin[get<0>(z)] += get<1>(z);
			}
			for (auto& z: ps[y]) {
				bin[get<0>(z)] += get<1>(z);
			}
		}
		copy(bin + 1, bin + n + 1, mn + 1);
		dfs(1, 0, cur);
		int base = 1;
		rep(i, 1, n) base = 1LL * base * fpow(i, mn[i]) % P;
		ans = 1LL * ans * fpow(base, P - 2) % P;
		printf("%d\n", ans);
	}
}