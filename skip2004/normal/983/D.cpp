#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
#define pb push_back
using std::cin; using std::cout;
const int maxn = 200200;
const int mod = 998244353;
typedef long long ll;
struct heap {
	std::priority_queue<int> q0, q1;
	inline void push(int x){ q0.push(x); }
	inline void pop(int x){ q1.push(x); }
	inline int max() {
		for(;q1.size() && q0.top() == q1.top();)
			q0.pop(), q1.pop();
		return q0.size() ? q0.top() : 0;
	}
} tree[maxn << 2];

int vis[maxn];
int min[maxn << 3], max[maxn << 3];
std::vector<int> vc0, vc1;
inline void up(int x) {
	min[x] = std::min(min[x << 1], min[x << 1 | 1]);
	min[x] = std::max(min[x], tree[x].max());
	max[x] = std::max(max[x << 1], max[x << 1 | 1]);
	max[x] = std::max(max[x], tree[x].max());
	if(max[x] < min[x] || vis[max[x]]) max[x] = 0;
}
inline void add(int ql, int qr, int v, int cur = 1, int l = 1, int r = vc0.size()) {
	if(ql <= l && r <= qr) {
		if(v < 0) {
			tree[cur].pop(-v);
		} else {
			if(!vis[v]) tree[cur].push(v);
		}
	} else {
		int mid = l + r >> 1;
		if(ql <= mid) add(ql, qr, v, cur << 1, l, mid);
		if(mid < qr) add(ql, qr, v, cur << 1 | 1, mid + 1, r);
	}
	up(cur);
}


int n;
struct T { int x0, y0, x1, y1; } a[maxn];
inline int get(std::vector<int> & v, int x) { return std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1; }
struct M { int l, r, id, type; };
std::vector<M> opt[maxn];
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i].x0 >> a[i].y0 >> a[i].x1 >> a[i].y1;
		vc0.pb(a[i].x0), vc0.pb(a[i].x1);
		vc1.pb(a[i].y0), vc1.pb(a[i].y1);
	}
	sort(vc0.begin(), vc0.end()), vc0.erase(unique(vc0.begin(), vc0.end()), vc0.end());
	sort(vc1.begin(), vc1.end()), vc1.erase(unique(vc1.begin(), vc1.end()), vc1.end());
	rep(i, 1, n) {
		a[i].x0 = get(vc0, a[i].x0), a[i].x1 = get(vc0, a[i].x1) - 1;
		a[i].y0 = get(vc1, a[i].y0), a[i].y1 = get(vc1, a[i].y1);
		opt[a[i].y0].push_back((M) {a[i].x0, a[i].x1, i, 0});
		opt[a[i].y1].push_back((M) {a[i].x0, a[i].x1, i, 1});
	}
	int ans = 1;
	rep(i, 1, vc1.size()) {
		for(const M & x : opt[i]) {
			add(x.l, x.r, x.type ? - x.id : x.id);
		}
		for(;int id = max[1];) {
			vis[id] = 1, add(a[id].x0, a[id].x1, id);
			++ ans;
		}
	}
	cout << ans << '\n';
}