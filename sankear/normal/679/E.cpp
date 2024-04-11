#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <queue>

using namespace std;

#define pb push_back
#define pbk pop_back
#define fs first
#define sc second
#define sz(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#define mt make_tuple
#define mp make_pair
#define next hunext
#define prev huprev

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const ll inf = ll(1e18);
const double pi = 4 * atan(1.0);
const double eps = 1e-9;
const int SIZE = int(4e6);

struct node {
    
    ll add, max_val, val, init;
    int l, r, h, cl, cr;
    
};

int sz = 0;
vector<ll> pws;
node d[SIZE];

inline void init() {
    ll pw = 1;
    for (;;) {
        pws.pb(pw);
        if (pw > inf / 42) {
            break;
        }
        pw *= 42;
    }
    cerr << "sz(pws) = " << sz(pws) << endl;
}

inline int get_rand() {
    return (rand() << 15) ^ rand();
}

inline int new_node(int l, int r, ll val) {
    int pos = lower_bound(all(pws), val) - pws.begin();
    assert(pos < sz(pws));
    int res = ++sz;
    d[res].l = l;
    d[res].r = r;
    d[res].h = get_rand();
    d[res].init = val;
    d[res].val = d[res].max_val = val - pws[pos];
    d[res].add = 0;
    d[res].cl = d[res].cr = 0;
    return res;
}

inline void push(int v) {
    if (v == 0 || d[v].add == 0) {
        return;
    }
    d[v].init += d[v].add;
    d[v].val += d[v].add;
    d[v].max_val += d[v].add;
    if (d[v].cl) {
        d[d[v].cl].add += d[v].add;
    }
    if (d[v].cr) {
        d[d[v].cr].add += d[v].add;
    }
    d[v].add = 0;
}

inline void calc(int v) {
    d[v].max_val = d[v].val;
    if (d[v].cl) {
        push(d[v].cl);
        d[v].max_val = max(d[v].max_val, d[d[v].cl].max_val);
    }
    if (d[v].cr) {
        push(d[v].cr);
        d[v].max_val = max(d[v].max_val, d[d[v].cr].max_val);
    }
}

void split(int v, int pos, int& l, int& r) {
    push(v);
    if (v == 0) {
        l = r = 0;
        return;
    }
    if (d[v].r <= pos) {
        split(d[v].cr, pos, d[v].cr, r);
        l = v;
        calc(v);
    } else if (d[v].l > pos) {
        split(d[v].cl, pos, l, d[v].cl);
        r = v;
        calc(v);
    } else {
        assert(d[v].l <= pos && pos < d[v].r);
        l = new_node(d[v].l, pos, d[v].init);
        r = new_node(pos + 1, d[v].r, d[v].init);
        d[l].cl = d[v].cl;
        d[r].cr = d[v].cr;
        calc(l);
        calc(r);
    }
}

int merge(int l, int r) {
    push(l);
    push(r);
    if (l == 0) {
        return r;
    }
    if (r == 0) {
        return l;
    }
    int res;
    if (d[l].h > d[r].h) {
        d[l].cr = merge(d[l].cr, r);
        res = l;
    } else {
        d[r].cl = merge(l, d[r].cl);
        res = r;
    }
    calc(res);
    return res;
}

inline ll get_val(int v, int pos) {
    push(v);
    assert(v > 0);
    if (d[v].l <= pos && pos <= d[v].r) {
        return d[v].init;
    }
    if (d[v].l > pos) {
        return get_val(d[v].cl, pos);
    } else {
        return get_val(d[v].cr, pos);
    }
}

inline void update(int v) {
    push(v);
    assert(v > 0 && d[v].max_val > 0);
    if (d[v].val > 0) {
        int pos = lower_bound(all(pws), d[v].init) - pws.begin();
        assert(pos < sz(pws));
        d[v].val = d[v].init - pws[pos];
        calc(v);
        return;
    }
    if (d[v].cl) {
        push(d[v].cl);
        if (d[d[v].cl].max_val > 0) {
            update(d[v].cl);
            calc(v);
            return;
        }
    }
    if (d[v].cr) {
        push(d[v].cr);
        if (d[d[v].cr].max_val > 0) {
            update(d[v].cr);
            calc(v);
            return;
        }
    }
    assert(false);
}

int main() {
    cerr << sizeof(d) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    init();
    int n, m;
    cin >> n >> m;
    int root = 0;
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);
        root = merge(root, new_node(i + 1, i + 1, cur));
    }
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int pos;
            scanf("%d", &pos);
            printf("%lld\n", get_val(root, pos));
            continue;
        }
        int l, r, val;
        scanf("%d %d %d", &l, &r, &val);
        if (t == 2) {
            int p1, p2, p3;
            split(root, r, p1, p3);
            split(p1, l - 1, p1, p2);
            root = merge(p1, merge(new_node(l, r, val), p3));
            continue;
        }
        assert(t == 3);
        int p1, p2, p3;
        split(root, r, p1, p3);
        split(p1, l - 1, p1, p2);
        for (;;) {
            d[p2].add += val;
            push(p2);
            while (d[p2].max_val > 0) {
                update(p2);
            }
            if (d[p2].max_val < 0) {
                break;
            }
        }
        root = merge(p1, merge(p2, p3));
    }
    return 0;
}