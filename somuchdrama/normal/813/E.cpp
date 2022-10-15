#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using std::cerr;
using std::cin;
using std::cout;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
#define sqr(x) ((x) * (x))
#ifdef LOCAL
#define dbg(as...) {\
    vector<string> _v; \
    std::stringstream _ss(#as);\
    string _cur, _loc;\
    while (getline(_ss, _cur, ',')) {\
        while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')')) {\
            getline(_ss, _loc, ',');\
            _cur += "," + _loc;\
        }\
    _v.pb(_cur);\
    }\
    err(_v.begin(), as);\
}
#else
#define dbg(as...)
#endif

template<typename T>
void err(vector<string>::iterator it, T a) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << '\n';
}
template<typename T, typename...Ts>
void err(vector<string>::iterator it, T a, Ts...as) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << ", ";
    err(++it, as...);
}

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        #ifdef LOCAL
        srand(300); 
        #else
        srand(time(0));
        #endif
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;

const int MAXN = 1e5 + 15; // maxs = 4 N + Q * (log N + 1)
const int MAXS = MAXN * 60;

struct node {
    node *l = nullptr, *r = nullptr;
    int val;
    node() {}
    node(int v) : val(v) {}
    node(node *other) : l(other->l), r(other->r), val(other->val) {}
} tree[MAXS];
using pnode = node*;
int ffr = 0, ffv = 0;

pnode clone(pnode v) {
    return &(tree[ffr++] = node(v));
}

int get(pnode v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl)
        return 0;
    if (l <= tl && tr <= r)
        return v->val;
    int tm = tl + tr >> 1;
    return get(v->l, tl, tm, l, r) + get(v->r, tm + 1, tr, l, r);
}

pnode update(pnode v, int tl, int tr, int ind, int val) {
    pnode nw = clone(v);
    dbg(v - tree, nw - tree, tl, tr, ind, val);
    if (tl == tr) {
        nw->val = val;
    } else {
        int tm = tl + tr >> 1;
        if (ind <= tm)
            nw->l = update(v->l, tl, tm, ind, val);
        else 
            nw->r = update(v->r, tm + 1, tr, ind, val);  
        nw->val = 0;
        nw->val += nw->l->val;
        nw->val += nw->r->val;
    }
    return nw;
}

pnode roots[MAXN + MAXN];
int n,k,sh = 1;
void build() {
    while (sh < n)
        sh *= 2;
    for (int i = 0; i < n; ++i) 
        tree[i + sh] = node(0);
    for (int i = sh - 1; i > 0; --i) {
        tree[i].l = &tree[i + i];
        tree[i].r = &tree[i + i + 1];
        tree[i].val = 0;
    }
    roots[0] = &tree[1];    
    ffr = n + n + 1, ffv = 1;
}

int get(int vers, int l, int r) {
    return get(roots[vers], 0, sh - 1, l, r);
}

void update(int vers, int index, int value) {
    roots[ffv++] = update(roots[vers], 0, sh - 1, index, value);
}

int a[MAXN];
vector<int> w[MAXN];

int rtsbyr[MAXN];

int main() {
    cin >> n >> k;
    build();

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        w[a[i]].pb(i);
        dbg(i, ffv - 1);
        update(ffv - 1, i, 1);
        dbg(i, ffv - 1);
        int sz = w[a[i]].size();
        if (sz > k) 
            update(ffv - 1, w[a[i]][sz - k - 1], 0);
        dbg(i, ffv - 1);
        rtsbyr[i] = ffv - 1;
    }
    dbg("ok");
    int last = 0, q, x, y;
    cin >> q;
    while (q--) {
        cin >> x >> y;
        int l = (x + last) % n;
        int r = (y + last) % n;
        if (l > r) swap(l, r);
        last = get(rtsbyr[r], l, r);
        cout << last << '\n';
    }

    return 0;
}