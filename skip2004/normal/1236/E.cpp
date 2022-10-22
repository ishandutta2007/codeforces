#include<bits/stdc++.h>
int n, m;
const int maxn = 100100;
typedef long long ll;
int a[maxn], b[maxn], c[maxn];
using std::cin;
using std::cout;
ll ans = 0;
namespace seg {
	struct sgt {
		int max[maxn << 2], min[maxn << 2], tag[maxn << 2];
		inline void update(int cur) {
			max[cur] = std::max(max[cur << 1], max[cur << 1 | 1]);
			min[cur] = std::min(min[cur << 1], min[cur << 1 | 1]);
		}
		inline void build(int cur, int l, int r, int * a) {
			if(l == r) {
				min[cur] = max[cur] = a[l];
				return ;
			}
			int mid = l + r >> 1;
			build(cur << 1, l, mid, a);
			build(cur << 1 | 1, mid + 1, r, a);
			update(cur);
		}
		inline void ask(int cur, int l, int r, int * a) {
			if(l == r) {
				a[l] = min[cur];
				return ;
			}
			int mid = l + r >> 1;
			down(cur);
			ask(cur << 1, l, mid, a);
			ask(cur << 1 | 1, mid + 1, r, a);
		}
		inline void put(int cur, int v) {
			min[cur] += v;
			max[cur] += v;
			tag[cur] += v;
		}
		inline void down(int cur) {
			put(cur << 1, tag[cur]);
			put(cur << 1 | 1, tag[cur]);
			tag[cur] = 0;
		}
		inline void upt(int v, int ad, int cur = 1, int l = 1, int r = n) {
			if(max[cur] < v) return ;
			if(min[cur] > v) return ;
			if(max[cur] == v && min[cur] == v) return put(cur, ad);
			int mid = l + r >> 1;
			down(cur);
			upt(v, ad, cur << 1, l, mid);
			upt(v, ad, cur << 1 | 1, mid + 1, r);
			update(cur);
		}
	} sb, sc;
	inline void solve() {
		for(int i = 1;i <= n;++i) b[i] = i == 1 ? 1 : i - 1, c[i] = i == n ? n : i + 1;
		sb.build(1, 1, n, b);
		sc.build(1, 1, n, c);
		for(int i = 1;i <= m;++i) {
			const int v = a[i];
			sb.upt(v, 1);
			sb.upt(1, 1);
			sb.put(1, -1);
			sc.upt(v, -1);
			sc.upt(n, -1);
			sc.put(1, 1);
		}
		sb.ask(1, 1, n, b);
		sc.ask(1, 1, n, c);
		for(int i = 1;i <= n;++i) ans += c[i] - b[i] + 1;
		if(n == 1) ans = 0;
	}
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;++i) {
		cin >> a[i];
	}
	seg::solve();
	cout << ans << '\n';
}