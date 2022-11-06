// Problem: E. Mark and Professor Koro
// Contest: Codeforces - Codeforces Round #807 (Div. 2)
// URL: https://codeforces.com/contest/1705/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 3e5+5, W = 3e5;

int n, m, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int left[2], same[2], sum, len, tag;
	Node() {
		rep(i, 0, 1) left[i] = same[i] = 0;
		sum = len = 0; tag = -1;
	}
	void set(int x) {
		left[x] = sum;
		left[x^1] = 0;
		same[x] = 1;
		same[x^1] = 0;
		sum = x * len;
	}
	friend Node operator + (const Node& a, const Node& b) {
		Node c;
		rep(i, 0, 1) {
			if(a.same[i]) {
				c.same[i] = b.same[i];
				c.left[i] = a.len + b.left[i];
			}
			else {
				c.same[i] = 0;
				c.left[i] = a.left[i];
			}
		}
		c.sum = a.sum + b.sum;
		c.len = a.len + b.len;
		return c;
	}
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(int u) {
		t[u] = t[lc(u)] + t[rc(u)];
	}
	void pushdown(int u) {
		if(t[u].tag == -1) return;
		t[lc(u)].set(t[u].tag);
		t[rc(u)].set(t[u].tag);
		t[lc(u)].tag = t[u].tag;
		t[rc(u)].tag = t[u].tag;
		t[u].tag = -1;
	}
	void build(int u, int l, int r) {
		t[u].len = r - l + 1;
		if(l == r) {
			t[u].set(0);
			return;
		}
		int mid = (l + r) >> 1;
		build(lc(u), l, mid);
		build(rc(u), mid+1, r);
		pushup(u);
	}
	void modify(int u, int l, int r, int ql, int qr, int k) {
		if(ql <= l && r <= qr) {
			t[u].set(k);
			t[u].tag = k;
			return;
		}
		pushdown(u);
		int mid = (l + r) >> 1;
		if(ql <= mid) modify(lc(u), l, mid, ql, qr, k);
		if(qr > mid) modify(rc(u), mid+1, r, ql, qr, k);
		pushup(u);
	}
	Node query(int u, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) return t[u];
		pushdown(u);
		int mid = (l + r) >> 1;
		if(qr <= mid) return query(lc(u), l, mid, ql, qr);
		if(ql > mid) return query(rc(u), mid+1, r, ql, qr);
		return query(lc(u), l, mid, ql, qr) + query(rc(u), mid+1, r, ql, qr);
	}
	void del(int k) {
		int val = query(1, 1, W, k, k).sum;
		if(val) modify(1, 1, W, k, k, 0);
		else {
			int p = k + query(1, 1, W, k, W).left[0];
			// printf("DEL %d %d\n", k, p);
			modify(1, 1, W, k, p-1, 1);
			modify(1, 1, W, p, p, 0);
		}
	}
	void add(int k) {
		int val = query(1, 1, W, k, k).sum;
		if(!val) modify(1, 1, W, k, k, 1);
		else {
			int p = k + query(1, 1, W, k, W).left[1];
			// printf("ADD %d %d\n", k, p);
			modify(1, 1, W, k, p-1, 0);
			modify(1, 1, W, p, p, 1);
		}
	}
	int get(int u, int l, int r) {
		if(l == r) return l;
		pushdown(u);
		int mid = (l + r) >> 1;
		if(t[rc(u)].sum) return get(rc(u), mid+1, r);
		else return get(lc(u), l, mid);
	}
	#undef lc
	#undef rc
}sgt;

int main() {
	scanf("%d%d", &n, &m);
	sgt.build(1, 1, W);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		sgt.add(a[i]);
	}
	while(m --> 0) {
		int x, y;
		scanf("%d%d", &x, &y);
		sgt.del(a[x]);
		a[x] = y;
		sgt.add(a[x]);
		printf("%d\n", sgt.get(1, 1, W));
	}
	return 0;
}