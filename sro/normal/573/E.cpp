/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int Seed = 19260817;
int inline Rand() {
	Seed ^= Seed << 13;
	Seed ^= Seed >> 17;
	Seed ^= Seed << 5;
	return Seed;
}

struct Node {
	ll sm, wp, wc, len, val;
	int l, r, fix;
} t[1 << 18];
int nds;

int inline newnode(ll val) {
	++nds; t[nds].sm = val; t[nds].wp = t[nds].wc = 0;
	t[nds].l = t[nds].r = 0;
	t[nds].len = 1; t[nds].val = val;
	t[nds].fix = Rand();
	return nds;
}

void inline pd(int now) {
	if(!now) return;
	t[now].val += t[now].wp;
	t[now].sm += t[now].len * t[now].wp;
	if(t[now].l) t[t[now].l].wp += t[now].wp;
	if(t[now].r) t[t[now].r].wp += t[now].wp;
	t[now].wp = 0;
	int cnt = 0;
	t[now].sm += t[now].len * (t[now].len - 1) / 2 * t[now].wc;
	if(t[now].l) {
		cnt += t[t[now].l].len;
		t[t[now].l].wc += t[now].wc;
	}
	t[now].val += cnt * t[now].wc; ++cnt;
	if(t[now].r) {
		t[t[now].r].wp += cnt * t[now].wc;
		t[t[now].r].wc += t[now].wc;
	}
	t[now].wc = 0;
}

void inline pu(int now) {
	t[now].len = t[t[now].l].len + 1 + t[t[now].r].len;
}

int inline merge(int a, int b) {
	pd(a); pd(b);
	if(!a || !b) return a + b;
	int now;
	if(t[a].fix > t[b].fix) {
		now = a;
		t[now].r = merge(t[a].r, b);
	} else {
		now = b;
		t[now].l = merge(a, t[b].l);
	}
	return pu(now), now;
}

void inline split(int now, int len, int &a, int &b) {
	if(!now) return void(a = b = 0);
	pd(now);
	if(t[t[now].l].len >= len) {
		b = now;
		split(t[now].l, len, a, t[b].l);
	} else {
		a = now;
		split(t[now].r, len - t[t[now].l].len - 1, t[a].r, b);
	}
	pu(now);
}

int n, rt;
int a[1 << 17];

ll inline get(int rnk) {
	int l, m, r;
	split(rt, rnk, l, r);
	split(l, rnk - 1, l, m);
	ll val = t[m].val;
	rt = merge(l, merge(m, r));
	return val;
}

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%d", a + i);
	rt = merge(newnode(0), newnode(a[1]));
	circ(i, 2, n) {
		int l = 0, r = i;
		while(r - l > 1) {
			int m = (l + r) >> 1;
			if(get(m) + 1ll * m * a[i] > get(m + 1)) r = m;
			else l = m;
		}
		int L, R;
		ll val = get(r);
		split(rt, r - 1, L, R);
		t[R].wp += 1ll * r * a[i];
		t[R].wc += a[i];
		rt = merge(L, merge(newnode(val), R));
	}
	ll ans = 0;
	cont(i, n + 1) ans = max(ans, get(i));
	printf("%lld\n", ans);
	return 0;
}