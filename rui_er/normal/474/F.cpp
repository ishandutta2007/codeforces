//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5, inf = 0x3f3f3f3f; 

int n, m, a[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int gcd, mn, cnt;
	Node(int a=0, int b=inf, int c=0) : gcd(a), mn(b), cnt(c) {}
	friend Node operator + (const Node& a, const Node& b) {
		return Node(__gcd(a.gcd, b.gcd), min(a.mn, b.mn), a.mn<b.mn?a.cnt:a.mn>b.mn?b.cnt:a.cnt+b.cnt);
	}
};
struct SegTree {
	Node t[N<<2];
	#define lc(u) (u<<1)
	#define rc(u) (u<<1|1)
	void build(int* a, int u, int l, int r) {
		if(l == r) {
			t[u].gcd = t[u].mn = a[l];
			t[u].cnt = 1;
			return;
		}
		int mid = (l + r) >> 1;
		build(a, lc(u), l, mid);
		build(a, rc(u), mid+1, r);
		t[u] = t[lc(u)] + t[rc(u)];
	}
	Node query(int u, int l, int r, int ql, int qr) {
		if(ql <= l && r <= qr) return t[u];
		int mid = (l + r) >> 1;
		Node ans;
		if(ql <= mid) ans = ans + query(lc(u), l, mid, ql, qr);
		if(qr > mid) ans = ans + query(rc(u), mid+1, r, ql, qr);
		return ans;
	}
}sgt;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	sgt.build(a, 1, 1, n);
	for(scanf("%d", &m);m;m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		Node qwq = sgt.query(1, 1, n, l, r);
		if(qwq.gcd == qwq.mn) printf("%d\n", (r-l+1)-qwq.cnt);
		else printf("%d\n", r-l+1);
	}
	return 0;
}