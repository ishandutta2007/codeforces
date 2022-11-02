#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 75005

int n, m;

struct data {
    int x1, x2, y1, y2, a, b;
    data () {}
    void input() {
		scanf("%d %d %d %d %d %d", &x1, &x2, &y1, &a, &b, &y2);
    }
} a[N];

bool cmp1(data x, data y) {
    return x.x1 > y.x1;
}
bool cmp2(data x, data y) {
	return x.x2 < y.x2;
}
struct Data {
    int x, a, b;
    ll y;
    Data(int x = 0, int a = 0, int b = 0, ll y = 0) : x(x), a(a), b(b), y(y) {}
} ;
bool Cmp1(Data a, Data b) {
	return a.x > b.x;
}
bool Cmp2(Data a, Data b) {
    return a.x < b.x;
}

vector <Data> v[2][N<<2];
int sa[N<<2], sb[N<<2];

void func(int L, int R, int seg) {
    vector <data> w;
    f1(i, L, R) w.pb(a[i]);
    sort(w.begin(), w.end(), cmp1);
    int pa = 0, pb = 0; ll py = 0;
    f0(i, 0, w.size()) {
        pa += w[i].a, pb += w[i].b, py += w[i].y1;
        v[0][seg].pb(Data(w[i].x1, pa, pb, py));
    }
    sa[seg] = pa, sb[seg] = pb;
    sort(w.begin(), w.end(), cmp2);
    pa = pb = 0, py = 0;
    f0(i, 0, w.size()) {
        pa += w[i].a, pb += w[i].b, py += w[i].y2;
        v[1][seg].pb(Data(w[i].x2, pa, pb, py));
    }
    return;
}

void build(int L, int R, int seg) {
    if (L == R) {
        func(L, R, seg);
		return;
    }
	int mid = L + R >> 1;
    build(L, mid, seg << 1);
    build(mid + 1, R, seg << 1 | 1);
    func(L, R, seg);
    return;
}

ll gunc(int seg, int x) {
    ll res = 0, aa = sa[seg], bb = sb[seg];
    int k;
    k = lower_bound(v[0][seg].begin(), v[0][seg].end(), x - 1, Cmp1) - v[0][seg].begin();
    if (k > 0) {k --; res += v[0][seg][k].y, aa -= v[0][seg][k].a; bb -= v[0][seg][k].b;}
	k = lower_bound(v[1][seg].begin(), v[1][seg].end(), x, Cmp2) - v[1][seg].begin();
    if (k > 0) {k --; res += v[1][seg][k].y, aa -= v[1][seg][k].a; bb -= v[1][seg][k].b;}
    return res + 1ll * x * aa + bb;
}

ll query(int l, int r, int x, int L, int R, int seg) {
    if (l <= L && R <= r) return gunc(seg, x);
    int mid = L + R >> 1;
    ll res = 0;
    if (l <= mid) res += query(l, r, x, L, mid, seg << 1);
    if (mid < r) res += query(l, r, x, mid + 1, R, seg << 1 | 1);
    return res;
}

int main() {
    scanf("%d", &n);
    int mod = 1e9;
    f1(i, 1, n) a[i].input();
    build(1, n, 1);
    scanf("%d", &m);
    int l, r, x;
    ll lst = 0;
    f1(i, 1, m) {
        scanf("%d %d %d", &l, &r, &x);
        x = (x + lst) % mod;
        lst = query(l, r, x, 1, n, 1);
        printf("%I64d\n", lst);
    }
	return 0;
}