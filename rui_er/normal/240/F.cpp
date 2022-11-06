//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m, a[26];
char s[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int w, tag;
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void pushup(int u) {
		t[u].w = t[lc(u)].w + t[rc(u)].w;
	}
	void pushdown(int u, int l, int r) {
		if(t[u].tag == -1) return;
		int mid = (l + r) >> 1;
		t[lc(u)].tag = t[u].tag;
		t[lc(u)].w = t[u].tag * (mid - l + 1);
		t[rc(u)].tag = t[u].tag;
		t[rc(u)].w = t[u].tag * (r - mid);
		t[u].tag = -1;
	}
	void build(int u, int l, int r, char c) {
		t[u].tag = -1;
		if(l == r) {
			t[u].w = s[l] == c;
			return;
		}
		int mid = (l + r) >> 1;
		build(lc(u), l, mid, c);
		build(rc(u), mid+1, r, c);
		pushup(u);
	}
	void assign(int u, int l, int r, int ql, int qr, int k) {
		if(ql > qr) return;
		if(t[u].w == k * (r - l + 1)) return;
		if(ql <= l && r <= qr) {
			t[u].tag = k;
			t[u].w = k * (r - l + 1);
			return;
		}
		pushdown(u, l, r);
		int mid = (l + r) >> 1;
		if(ql <= mid) assign(lc(u), l, mid, ql, qr, k);
		if(qr > mid) assign(rc(u), mid+1, r, ql, qr, k);
		pushup(u);
	}
	int query(int u, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) return t[u].w;
		pushdown(u, l, r);
		int mid = (l + r) >> 1, ans = 0;
		if(ql <= mid) ans += query(lc(u), l, mid, ql, qr);
		if(qr > mid) ans += query(rc(u), mid+1, r, ql, qr);
		pushup(u);
		return ans;
	}
	#undef lc
	#undef rc
}sgt[26];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%s", &n, &m, s+1);
	rep(i, 0, 25) sgt[i].build(1, 1, n, 'a'+i);
	while(m --> 0) {
		int l, r, single = 0;
		scanf("%d%d", &l, &r);
		rep(i, 0, 25) {
			a[i] = sgt[i].query(1, 1, n, l, r);
			single += a[i] & 1;
		}
		if(single > 1) continue;
		rep(i, 0, 25) {
			if(a[i] & 1) {
				rep(j, 0, 25) {
					sgt[j].assign(1, 1, n, (l+r)>>1, (l+r)>>1, i==j);
				}
			}
			int len = a[i] >> 1;
			rep(j, 0, 25) {
				sgt[j].assign(1, 1, n, l, l+len-1, i==j);
				sgt[j].assign(1, 1, n, r-len+1, r, i==j);
			}
			l += len;
			r -= len;
		}
	}
	rep(i, 1, n) {
		rep(j, 0, 25) {
			if(sgt[j].query(1, 1, n, i, i)) {
				putchar('a'+j);
				break;
			}
		}
	}
	return 0;
}

/*
10 3
rrrrrrrrrr
2 8
5 8
3 10

8 2
abaacaca
5 8
1 5
*/