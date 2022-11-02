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

struct node {
    
    bool rev;
    int val;
    int h, sz, l, r;
    ll sum;
    
};

int ptr;
node d[N];
vi vals;

inline int get_rand() {
    return (rand() << 16) | rand();
}

inline void push(int v) {
    if (!d[v].rev) {
        return;
    }
    swap(d[v].l, d[v].r);
    if (d[v].l > 0) {
        d[d[v].l].rev ^= true;
    }
    if (d[v].r > 0) {
        d[d[v].r].rev ^= true;
    }
    d[v].rev = false;
}

void write(int v) {
    push(v);
    if (v == 0) {
        return;
    }
    write(d[v].l);
    vals.pb(d[v].val);
    write(d[v].r);
}

inline void calc(int v) {
    d[v].sz = d[d[v].l].sz + d[d[v].r].sz + 1;
    d[v].sum = d[d[v].l].sum + d[d[v].r].sum + d[v].val;
}

void split(int v, int sz, int &l, int &r) {
    push(v);
    if (v == 0) {
        l = r = 0;
        return;
    }
    if (d[d[v].l].sz + 1 <= sz) {
        split(d[v].r, sz - d[d[v].l].sz - 1, d[v].r, r);
        l = v;
    } else {
        split(d[v].l, sz, l, d[v].l);
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
    } else {
        d[r].l = merge(l, d[r].l);
        res = r;
    }
    calc(res);
    return res;
}

void add(int v) {
    push(v);
    if (v == 0) {
        return;
    }
    add(d[v].l);
    //assert(ptr < sz(vals));
    d[v].val += vals[ptr++];
    add(d[v].r);
    calc(v);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, q;
    scanf("%d %d", &n, &q);
    int root = 0;
    for (int i = 0; i < n; ++i) {
        d[i + 1].h = get_rand();
        d[i + 1].val = d[i + 1].sum = 1;
        d[i + 1].l = d[i + 1].r = 0;
        d[i + 1].sz = 1;
        root = merge(root, i + 1);
    }
    for (int i = 0; i < q; ++i) {
        int t, l;
        scanf("%d %d", &t, &l);
        if (t == 1) {
            int p1, p2, p3;
            split(root, l, p1, p3);
            split(p1, d[p1].sz - d[p3].sz, p1, p2);
            vals.clear();
            write(p2);
            reverse(vals.begin(), vals.end());
            ptr = 0;
            int p31, p32;
            split(p3, sz(vals), p31, p32);
            add(p31);
            if (p1 > 0) {
                d[p1].rev ^= true;
            }
            root = merge(merge(p31, p32), p1);
            continue;
        }
        int r;
        scanf("%d", &r);
        int p1, p2, p3;
        split(root, r, p1, p3);
        split(p1, l, p1, p2);
        printf(LLD"\n", d[p2].sum);
        root = merge(p1, merge(p2, p3));
    }
    return 0;
}