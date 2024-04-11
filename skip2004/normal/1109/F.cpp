#include<bits/stdc++.h>
const int maxn = 200200;
using std::cin;
using std::cout;
typedef long long ll;
ll out;

int n, w, h;
namespace sgt {
	int min[maxn << 2], cnt[maxn << 2], tag[maxn << 2];
	inline void update(int cur) {
		min[cur] = std::min(min[cur << 1], min[cur << 1 | 1]);
		cnt[cur] = 0;
		if(min[cur] == min[cur << 1]) cnt[cur] += cnt[cur << 1];
		if(min[cur] == min[cur << 1 | 1]) cnt[cur] += cnt[cur << 1 | 1];
	}
	inline void put(int cur, int v) {
		min[cur] += v, tag[cur] += v;
	}
	inline void build(int cur, int l, int r) {
		if(l == r) {
			min[cur] = -1;
			cnt[cur] = 1;
			return ;
		}
		int mid = l + r >> 1;
		build(cur << 1, l, mid);
		build(cur << 1 | 1, mid + 1, r);
		update(cur);
	}
	inline void pushdown(int cur) {
		if(tag[cur] != 0) {
			put(cur << 1, tag[cur]);
			put(cur << 1 | 1, tag[cur]);
			tag[cur] = 0;
		}
	}
	inline void upt(int ql, int qr, int v, int cur = 1, int l = 1, int r = n) {
		if(ql <= l && r <= qr) return put(cur, v);
		int mid = l + r >> 1;
		pushdown(cur);
		if(ql <= mid) upt(ql, qr, v, cur << 1, l, mid);
		if(mid < qr) upt(ql, qr, v, cur << 1 | 1, mid + 1, r);
		update(cur);
	}
	inline int eval(int ql, int qr, int cur = 1, int l = 1, int r = n) {
		if(ql <= l && r <= qr) return min[cur] == 0 ? cnt[cur] : 0;
		int mid = l + r >> 1, ans = 0;
		pushdown(cur);
		if(ql <= mid) ans += eval(ql, qr, cur << 1, l, mid);
		if(mid < qr) ans += eval(ql, qr, cur << 1 | 1, mid + 1, r);
		return ans;
	}
}
namespace lct {
	const int N = maxn << 1;
	int son[N][2], fa[N], max[N], tag[N];
	inline int get(int x, int p = 1) {
		return son[fa[x]][p] == x;
	}
	inline int is_root(int x) {
		return !(get(x) || get(x, 0));
	}
	inline void put(int x) {
		if(x) {
			tag[x] ^= 1;
			std::swap(son[x][0], son[x][1]);
		}
	}
	inline void down(int x) {
		if(tag[x] != 0) {
			put(son[x][0]);
			put(son[x][1]);
			tag[x] = 0;
		}
	}
	inline void pushdown(int x) {
		if(!is_root(x)) pushdown(fa[x]);
		down(x);
	}
	inline void update(int x) {
		max[x] = x;
		if(son[x][0] && max[son[x][0]] > max[x]) max[x] = max[son[x][0]];
		if(son[x][1] && max[son[x][1]] > max[x]) max[x] = max[son[x][1]];
	}
	inline void rotate(int x) {
		int y = fa[x], z = fa[y], b = get(x);
		if(!is_root(y)) son[z][get(y)] = x;
		son[y][b] = son[x][!b], son[x][!b] = y;
		fa[son[y][b]] = y, fa[y] = x, fa[x] = z;
		update(y);
	}
	inline void splay(int x) {
		for(pushdown(x);!is_root(x);rotate(x))
			if(!is_root(fa[x])) rotate(get(x) ^ get(fa[x]) ? x : fa[x]);
		update(x);
	}
	inline void access(int x) {
		for(int t = 0;x;son[x][1] = t, t = x, x = fa[x])
			splay(x);
	}
	inline void makeroot(int x) {
		access(x), splay(x), put(x);
	}
	inline void split(int x, int y) {
		makeroot(x), access(y), splay(y);
	}
	inline bool con(int x, int y) {
		split(x, y);
		for(;son[y][0];) y = son[y][0];
		splay(y);
		return x == y;
	}
	std::vector<int> edge[N];
	int min;

	inline void cut(int x, int y) {
		if(con(x, y)) {
			split(x, y);
			if(son[y][0] == x && !son[x][1]) {
				son[y][0] = fa[x] = 0;
				update(y);
			}
		}
	}
	inline void link(int x, int y) {
		if(con(x, y)) {
			split(x, y);
			int id = max[y];
			for(int x : edge[id]) cut(id, x);
			min = std::min(min, id - 1);
		}
		makeroot(x), fa[x] = y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
}
int a[1010][1010];
int px[maxn], py[maxn];
inline int id(int x, int y) {
	return (x - 1) * h + y;
}
inline void try_link(int x, int y, int tx, int ty) {
	if(1 <= tx && tx <= w && 1 <= ty && ty <= h && a[x][y] < a[tx][ty]) {
		lct::link(a[x][y], a[tx][ty]);
		sgt::upt(a[tx][ty], n, -1);
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> w >> h, n = w * h;
	for(int i = 1;i <= w;++i) {
		for(int j = 1;j <= h;++j) {
			cin >> a[i][j];
			px[a[i][j]] = i;
			py[a[i][j]] = j;
		}
	}
	lct::min = n;
	sgt::build(1, 1, n);
	for(int i = n;i >= 1;--i) {
		int x = px[i], y = py[i];
		sgt::upt(i, n, 1);
		try_link(x, y, x - 1, y);
		try_link(x, y, x + 1, y);
		try_link(x, y, x, y - 1);
		try_link(x, y, x, y + 1);
		out += sgt::eval(i, lct::min);
	}
	cout << out << '\n';
}