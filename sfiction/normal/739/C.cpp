#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 3E5 + 10;

int a[MAXN];

struct SegmentTree{
	static const int MAXN = ::MAXN;

	struct node{
		ll val;
		int len;
		int ps, pre, ss, suf;
		int ans;

		int sign(ll x){
			return x < 0 ? -1 : x == 0 ? 0 : 1;
		}

		void update(int c){
			val += c;
			ps = ss = sign(val);
			pre = suf = ans = !!ps;
		}

		node operator +(const node &r){
			node ret;
			ret.len = len + r.len;
			ret.ps = ps, ret.pre = pre;
			ret.ss = r.ss, ret.suf = r.suf;
			ret.ans = max(ans, r.ans);
			if (ss && r.ps && ss >= r.ps){
				ret.ans = max(ret.ans, suf + r.pre);
				if (pre == len)
					ret.pre += r.pre;
				if (r.suf == r.len)
					ret.suf += suf;
			}
			return ret;
		}
	}a[MAXN << 2];

	void build(int u, int l, int r){
		if (l + 1 == r){
			a[u].val = 0, a[u].len = 1;
			a[u].update(::a[l] - ::a[l - 1]);
			return;
		}
		int m = l + r >> 1;
		build(u << 1, l, m);
		build(u << 1 | 1, m, r);
		a[u] = a[u << 1] + a[u << 1 | 1];
	}

	void update(int u, int l, int r, int L, int c){
		if (l + 1 == r){
			a[u].update(c);
			return;
		}
		int m = l + r >> 1;
		if (L < m)
			update(u << 1, l, m, L, c);
		else
			update(u << 1 | 1, m, r, L, c);
		a[u] = a[u << 1] + a[u << 1 | 1];
	}
}SGT;

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	if (n > 1)
		SGT.build(1, 1, n);

	int q;
	scanf("%d", &q);
	for (int l, r, d, qi = 0; qi < q; ++qi){
		scanf("%d%d%d", &l, &r, &d);
		if (l > 1)
			SGT.update(1, 1, n, l - 1, d);
		if (r < n)
			SGT.update(1, 1, n, r, -d);
		printf("%d\n", SGT.a[1].ans + 1);
	}

	return 0;
}