#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 20200;
typedef long long ll;
int n, k;
int dp[110][maxn], * a0, * a1;
int a[maxn];
inline void down(int & x, int y) { if(x > y) x = y; }
struct fc {
	int a, k;
	inline int operator () (int x) const {
		int ans = a + k * x;
		return ans;
	}
};
inline ll cross(const fc & x, const fc & y, const fc & z) { return ll(z.a - x.a) * (y.k - x.k) - ll(y.a - x.a) * (z.k - x.k); }
struct hull {
	std::deque<fc> q;
	inline int size() { return q.size(); }
	inline void pb(const fc & x) {
		for(;q.size() >= 2;) {
			const fc & a0 = *std::next(q.rbegin()), &a1 = q.back();
			if(cross(a0, a1, x) >= 0) {
				q.pop_back();
			} else {
				break;
			}
		}
		q.push_back(x);
	}
	inline void pf(const fc & x) {
		for(;q.size() >= 2;) {
			const fc & a0 = q.front(), a1 = * std::next(q.begin());
			if(cross(x, a0, a1) >= 0) {
				q.pop_front();
			} else {
				break;
			}
		}
		q.push_front(x);
	}
	inline void add0(hull & b) {
		for(;b.q.size();) pf(b.q.back()), b.q.pop_back();
	}
	inline void add1(hull & b) {
		for(;b.q.size();) pb(b.q.front()), b.q.pop_front();
	}
	inline int qmin(int x) {
		int l = -1, r = q.size() - 1;
		for(;l + 1 != r;) {
			int mid = l + r >> 1;
			const fc & a0 = q[mid], & a1 = q[mid + 1];
			if(a0(x) < a1(x)) {
				r = mid;
			} else {
				l = mid;
			}
		}
		return q[r](x);
	}
	inline void clear(){ q.clear(); }
} q[maxn];
int st[maxn], top;
int ls[maxn], rs[maxn];
inline int build(int l, int r) {
	if(l > r) return 0;
	int max = std::max_element(a + l, a + r + 1) - a;
	ls[max] = build(l, max - 1);
	rs[max] = build(max + 1, r);
	return max;
}

fc tree[maxn << 2];
bool ept[maxn << 2];
inline void base_add(fc x, int cur, int l, int r) {
	if(ept[cur]) {
		tree[cur] = x;
		ept[cur] = 0;
	} else {
		int mid = l + r >> 1;
		if(tree[cur](mid) > x(mid)) std::swap(tree[cur], x);
		if(l == r) return ;
		if(tree[cur](l) > x(l)) base_add(x, cur << 1, l, mid);
		if(tree[cur](r) > x(r)) base_add(x, cur << 1 | 1, mid + 1, r);
	}
}
inline void clear(int cur = 1,int l = 1,int r = n) {
	ept[cur] = 1;
	if(l == r) return ;
	int mid = l + r >> 1;
	clear(cur << 1, l, mid);
	clear(cur << 1 | 1, mid + 1, r);
}
inline int test(int pos, int cur = 1,int l = 1,int r = n) {
	int ans = 1e9;
	for(;;) {
		int mid = l + r >> 1;
		if(!ept[cur]) down(ans, tree[cur](pos));
		if(l == r) return ans;
		if(pos <= mid) {
			cur <<= 1;
			r = mid;
		} else {
			cur = cur << 1 | 1;
			l = mid + 1;
		}
	}
}
inline void add(int ql, int qr, const fc & x, int cur = 1,int l = 1,int r = n) {
	if(ql <= l && r <= qr) return base_add(x, cur, l, r);
	int mid = l + r >> 1;
	if(ql <= mid) add(ql, qr, x, cur << 1, l, mid);
	if(mid < qr) add(ql, qr, x, cur << 1 | 1, mid + 1, r);
}

inline void dfs(int x, int l, int r) {
	if(!x) return ;
	dfs(ls[x], l, x - 1), dfs(rs[x], x + 1, r);
	q[x].q = {{a0[x - 1], 1 - x}};
	if(q[ls[x]].size() > q[x].size()) {
		q[ls[x]].add1(q[x]);
		std::swap(q[x], q[ls[x]]);
	} else {
		q[x].add0(q[ls[x]]);
	}
	int min = q[x].qmin(a[x]);
	add(x, r, {min, a[x]});
	// for(int i = x;i <= r;++i) down(a1[i], min + i * a[x]);
	if(q[rs[x]].size() > q[x].size()) {
		q[rs[x]].add0(q[x]);
		std::swap(q[x], q[rs[x]]);
	} else {
		q[x].add1(q[rs[x]]);
	}
}
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	std::mt19937 rd(1);
	cin >> n >> k;
	for(int i = 1;i <= n;++i) {
		cin >> a[i];
	}
	for(int i = 1, max = 0;i <= n;++i) {
		if(max < a[i]) max = a[i];
		dp[1][i] = max * i;
	}
	int root = build(1, n);
	for(int i = 2;i <= k;++i) {
		a0 = dp[i - 1], a1 = dp[i];
		clear();
		dfs(root, 1, n);
		rep(i, 1, n) a1[i] = std::min(a0[i], test(i));
	}
	cout << dp[k][n] << '\n';
}
/*
10 4
2 7 10 5 7 4 6 4 8 6


*/