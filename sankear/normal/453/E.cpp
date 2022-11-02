#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int N = int(1e5) + 100;

struct ponny {
    
    int s, m, r;
    
};

struct node {
    
    int t;
    ll sum, add_a, add_b;
    int h, sz, p, l, r;
    
};

int root = 0;
set<pii> times;
ponny p[N];
int t[N];
node d[N];
vi add[N], del[N];

inline int get_rand() {
    return (rand() << 16) | rand();
}

inline void push(int v) {
    if (v == 0) {
        return;
    }
    d[v].sum += 1LL * d[v].add_a * d[v].t + d[v].add_b;
    if (d[v].l > 0) {
        d[d[v].l].add_a += d[v].add_a;
        d[d[v].l].add_b += d[v].add_b;
    }
    if (d[v].r > 0) {
        d[d[v].r].add_a += d[v].add_a;
        d[d[v].r].add_b += d[v].add_b;
    }
    d[v].add_a = d[v].add_b = 0;
}

inline void calc(int v) {
    d[v].p = 0;
    d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
    if (d[v].l > 0) {
        d[d[v].l].p = v;
    }
    if (d[v].r > 0) {
        d[d[v].r].p = v;
    }
}

void split(int v, int t, int &l, int &r) {
    push(v);
    if (v == 0) {
        l = r = 0;
        return;
    }
    if (d[v].t < t) {
        split(d[v].r, t, d[v].r, r);
        l = v;
    }
    else {
        split(d[v].l, t, l, d[v].l);
        r = v;
    }
    calc(v);
}

void split_size(int v, int sz, int &l, int &r) {
    push(v);
    if (v == 0) {
        l = r = 0;
        return;
    }
    if (d[d[v].l].sz + 1 <= sz) {
        split_size(d[v].r, sz - d[d[v].l].sz - 1, d[v].r, r);
        l = v;
    }
    else {
        split_size(d[v].l, sz, l, d[v].l);
        r = v;
    }
    calc(v);
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
        d[l].r = merge(d[l].r, r);
        res = l;
    }
    else {
        d[r].l = merge(l, d[r].l);
        res = r;
    }
    calc(res);
    return res;
}

inline void insert_num(int num) {
    int l, r;
    split(root, d[num].t, l, r);
    root = merge(l, merge(num, r));
}

inline int get_num(int v) {
    int res = d[d[v].l].sz + 1;
    while (d[v].p > 0) {
        int pv = d[v].p;
        if (d[pv].r == v) {
            res += d[d[pv].l].sz + 1;
        }
        v = pv;
    }
    return res;
}

inline void del_num(int num) {
    int n = get_num(num);
    int l, r, tmp;
    split_size(root, n, l, r);
    split_size(l, n - 1, l, tmp);
    assert(tmp == num);
    root = merge(l, r);
}

inline void insert_with_new_diff(int num, int new_diff) {
    if (times.find(mp(t[num], num)) != times.begin()) {
        del_num(num);
    }
    d[num].t = new_diff;
    insert_num(num);
}

inline void add_query(int num) {
    set<pii>::iterator it = times.upper_bound(mp(t[num], num));
    d[num].h = get_rand();
    d[num].sz = 1;
    d[num].add_a = d[num].add_b = d[num].sum = 0;
    d[num].p = d[num].l = d[num].r = 0;
    if (it != times.end()) {
        int next_num = it->sc;
        insert_with_new_diff(next_num, it->fs - t[num]);
    }
    times.insert(mp(t[num], num));
    it = times.find(mp(t[num], num));
    if (it == times.begin()) {
        return;
    }
    --it;
    d[num].t = t[num] - it->fs;
    insert_num(num);
}

inline void del_query(int num) {
    set<pii>::iterator it = times.find(mp(t[num], num));
    int add = 0;
    if (it != times.begin()) {
        del_num(num);
        add = d[num].t;
    }
    ++it;
    if (it != times.end()) {
        int next_num = it->sc;
        if (add > 0) {
            insert_with_new_diff(next_num, d[next_num].t + add);
        }
        else {
            del_num(next_num);
        }
    }
    times.erase(mp(t[num], num));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &p[i].s, &p[i].m, &p[i].r);
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        int l, r;
        scanf("%d %d %d", &t[i], &l, &r);
        --l;
        --r;
        add[l].pb(i);
        del[r].pb(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz(add[i]); ++j) {
            add_query(add[i][j]);
        }
        if (!times.empty()) {
            int first = times.begin()->sc;
            ll mana = min(1LL * t[first] * p[i].r + p[i].s, 1LL * p[i].m);
            d[first].sum += mana;
            if (times.size() >= 2 && p[i].r > 0) {
                int critical = (p[i].m + p[i].r - 1) / p[i].r;
                int l, r;
                split(root, critical, l, r);
                if (r > 0) {
                    d[r].add_b += p[i].m;
                }
                if (l > 0) {
                    d[l].add_a += p[i].r;
                }
                root = merge(l, r);
            }
        }
        for (int j = 0; j < sz(del[i]); ++j) {
            del_query(del[i][j]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        printf(LLD"\n", d[i].sum);
    }
    return 0;
}