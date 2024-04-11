#include<bits/stdc++.h>
const int maxn = 200200;
const int N = 200000;
using std::cin;
using std::cout;
int n, q;
int a[maxn];
namespace lct {
	int max[maxn << 2], Max[maxn << 2];
	struct mes {
		int pre_max, sum, suf_max, EP;
	} sum[maxn << 2];
	inline int val(const mes & x) {
		return x.pre_max + x.sum + x.suf_max;
	}

	inline void up(int & x, int y) {
		if(x < y) {
			x = y;
		}
	}

	inline mes operator + (const mes & x, const mes & y) {
		if(x.EP && y.EP) return (mes){ std::max(x.pre_max, y.pre_max), 0, 0, 1};
		if(x.EP) return (mes){ std::max(x.pre_max, y.pre_max), y.sum, y.suf_max, 0};
		if(y.EP) return (mes){ x.pre_max, x.sum, std::max(x.suf_max, y.pre_max), 0};
		return (mes) {x.pre_max, x.sum + std::max(x.suf_max, y.pre_max) + y.sum, y.suf_max, 0};
	}

	inline mes go(int cur, int v, int l = 1, int r = n) {
		if(l == r) return max[cur] >= v ? sum[cur] : mes {Max[cur], 0, 0, 1};
		int mid = l + r >> 1;
		if(max[cur << 1] < v) {
			mes res = go(cur << 1 | 1, v, mid + 1, r);
			up(res.pre_max, Max[cur << 1]);
			return res;
		} else {
			return go(cur << 1, v, l, mid) + sum[cur];
		}
	}
	inline void upt(int pos, int M, int S, int E, int cur = 1, int l = 1, int r = n) {
		if(l == r) return max[cur] = M, Max[cur] = S, sum[cur] = {S, 0, 0, E}, void();
		int mid = l + r >> 1;
		pos <= mid ? upt(pos, M, S, E, cur << 1, l, mid) : upt(pos, M, S, E, cur << 1 | 1, mid + 1, r);
		Max[cur] = std::max(Max[cur << 1], Max[cur << 1 | 1]);
		max[cur] = std::max(max[cur << 1], max[cur << 1 | 1]);
		sum[cur] = go(cur << 1 | 1, max[cur << 1], mid + 1, r);
	}
}
std::set<int> set[maxn];
inline void ins(int c) {
	if(set[c].size()) {
		lct::upt(* set[c].begin(), * set[c].rbegin(), 0, 1);
		lct::upt(* set[c].rbegin(), * set[c].rbegin(), set[c].size(), 0);
	}
}
inline void del(int c) {
	if(set[c].size()) {
		lct::upt(* set[c].begin(), 0, 0, 1);
		lct::upt(* set[c].rbegin(), 0, 0, 1);
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
		set[a[i]].emplace(i);
	}
	for(int i = 1;i <= N;++i) ins(i);
	cout << n - val(lct::go(1, 0)) << '\n';
	for(int i = 1, pos, c;i <= q;++i) {
		cin >> pos >> c;
		if(a[pos] != c) {
			del(a[pos]);
			del(c);
			set[a[pos]].erase(pos);
			set[c].insert(pos);
			ins(a[pos]);
			ins(c);
			a[pos] = c;
		}
		cout << n - val(lct::go(1, 0)) << '\n';
	}
}