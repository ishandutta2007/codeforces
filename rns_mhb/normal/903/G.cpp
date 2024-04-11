#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define x first
#define y second
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

typedef pair <int, int> pii;
typedef pair <ll, int> pli;

const ll linf = 2e18 + 100;
const int inf = 0x3f3f3f3f;

#define N 200005

int n, m, q, a[N], b[N];
ll c[N];
vector <pii> v[N];
set <pli> st;

ll mn[N<<2], inc[N<<2];
void init() {
	memset(mn, 0, sizeof mn);
	memset(inc, 0, sizeof inc);
	return;
}
void build(int L, int R, int seg) {
	inc[seg] = 0;
	if (L == R) {
		mn[seg] = b[L-1];
		return;
	}
	int mid = L + R >> 1;
	build(L, mid, seg<<1);
	build(mid+1, R, seg<<1|1);
	mn[seg] = min(mn[seg<<1], mn[seg<<1|1]);
	return;
}
void add_delta(int seg, ll v) {
	mn[seg] += v, inc[seg] += v;
	return;
}
void update(int l, int r, int v, int L, int R, int seg) {
	if (l <= L && R <= r) return add_delta(seg, v);
	if (inc[seg]) {
		add_delta(seg << 1, inc[seg]);
		add_delta(seg << 1 | 1, inc[seg]);
		inc[seg] = 0;
	}
	int mid = L + R >> 1;
	if (l <= mid) update(l, r, v, L, mid, seg<<1);
	if (mid < r) update(l, r, v, mid+1, R, seg<<1|1);
	mn[seg] = min(mn[seg<<1], mn[seg<<1|1]);
	return;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
    f0(i, 1, n) scanf("%d %d", &a[i], &b[i]);
    int x, y, d;
    f1(i, 1, m) {
		scanf("%d %d %d", &x, &y, &d);
		v[x].pb(pii(y, d));
    }
    build(1, n, 1);
    f1(i, 1, n) {
        for (auto x : v[i]) update(1, x.x, x.y, 1, n, 1);
        c[i] = mn[1];
    }
    f1(i, 1, n) c[i] += a[i], st.insert(pli(c[i], i));
    printf("%I64d\n", st.begin() -> x);
    while (q --) {
        scanf("%d %d", &x, &y);
        st.erase(pli(c[x], x));
        c[x] += y - a[x];
        a[x] = y;
        st.insert(pli(c[x], x));
        printf("%I64d\n", st.begin() -> x);
    }
	return 0;
}