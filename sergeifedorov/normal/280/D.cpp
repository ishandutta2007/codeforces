#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

const int kmax = 21;
const int nmax = 1 << 17;

struct seg{
    int l, r, sum;

    seg () {
        init();
    };

    seg (int l, int r, int sum) : l(l), r(r), sum(sum) {};


    void set(int l1, int r1, int sum1) {
        l = l1;
        r = r1;
        sum = sum1;
    }

    void update(int l1, int r1, int sum1) {
        if (sum1 > sum) 
            set(l1, r1, sum1);
    }

    void update(seg a) {
        if (a.sum > sum)
            set(a.l, a.r, a.sum);
    }

    void init() {
        l = 0; r = -1;
        sum = 0;
    }

    void write() {
        cerr << l << " " << r << " " << sum << endl;
    }
};

struct vertex {
    seg lft, rgt, al, sum;

    void init() {
        lft.init();
        rgt.init();
        al.init();
        sum.init();
    }

    vertex() {
        init();
    }   

    vertex(int x, int l) {
        init();
        lft.update(l, l, x);
        rgt.update(l, l, x);
        sum.update(l, l, x);
        al.set(l, l, x);
    }

};

seg merge(seg a, seg b) {
    return seg(a.l, b.r, a.sum + b.sum);
}

vertex merge (const vertex &a, const vertex &b) {
    vertex res;
    res.al.set(a.al.l, b.al.r, a.al.sum + b.al.sum);

    res.lft = a.lft;
    res.lft.update(merge(a.al, b.lft));
    res.rgt = b.rgt;
    res.rgt.update(merge(a.rgt, b.al));
    
    res.sum = a.sum;
    res.sum.update(a.sum);
    res.sum.update(b.sum);
    res.sum.update(merge(a.rgt, b.lft));

    return res;
}

int n, m;
vertex t1[nmax*2], t2[nmax * 2];
vertex res;
int a[nmax];

void build (int v, int l, int r) {
    if (l > n) return;
    if (l == r) {
        t1[v] = vertex(a[l-1], l);
        t2[v] = vertex(-a[l-1], l);
        return;
    }
    int m = (l + r) / 2;
    build(v * 2, l, m);
    build(v * 2 + 1, m + 1, r);
    t1[v] = merge(t1[v * 2], t1[v*2 + 1]);
    t2[v] = merge(t2[v * 2], t2[v*2 + 1]);
}

void update(int v, int l, int r, int c, int x) {
    if (l > c || r < c) return;
    if (l == r) {
        t1[v] = vertex(x, l);
        t2[v] = vertex(-x, l);
        return;
    }
    int m = (l + r) / 2;
    update(v * 2, l, m, c, x);
    update(v * 2 + 1, m + 1, r, c, x);
    t1[v] = merge(t1[v * 2], t1[v*2 + 1]);
    t2[v] = merge(t2[v * 2], t2[v*2 + 1]);
}

vertex calcMax(int v, int l, int r, int l1, int r1) {
    if (l1 > r1) return vertex ();
    if (l1 > r || r1 < l) return vertex ();
    if (l1 <= l && r <= r1) return t1[v];
    int m = (l + r) / 2;
    return merge(calcMax(v * 2, l, m, l1, r1), calcMax(v * 2 + 1, m + 1, r, l1, r1));
}

vertex calcMin(int v, int l, int r, int l1, int r1) {
    if (l1 > r1) return vertex ();
    if (l1 > r || r1 < l) return vertex ();
    if (l1 <= l && r <= r1) return t2[v];
    int m = (l + r) / 2;
    return merge(calcMin(v * 2, l, m, l1, r1), calcMin(v * 2 + 1, m + 1, r, l1, r1));
}

int get(int l, int r, int k) {
    vector<int> a;
    a.pb(l-1);
    a.pb(r+1);
    int res = 0;
    forn(i, k) {
//      cerr << res << " " << k << endl;
        int bst = 0, pl, pr;
        pl = pr = -1;
        forn(j, a.size() - 1) {
            vertex now;
            if (j & 1)
                now = calcMin(1, 1, nmax, a[j], a[j+1]);
            else
                now = calcMax(1, 1, nmax, a[j] + 1, a[j+1] - 1);
            if (now.sum.sum > bst) {
//              cerr << " === "  << " " << (j & 1) << " " << a[j] << " " << a[j+1] << endl;
//              now.sum.write();
                bst = now.sum.sum;
                pl = now.sum.l;
                pr = now.sum.r;
                if (j & 1) {
                    pl --; pr ++;
                }
            }
        }
//      cerr << bst << endl;
        if (bst == 0) break;
        a.pb(pl);
        a.pb(pr);
        sort(all(a));
        res += bst;
    }
    return res;
}

int main ()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("out", "wt", stdout);

    cin >> n;
    forn(i, n)
        scanf("%d", &a[i]);
    build(1, 1, nmax);
//  cerr << clock() << endl;

    cin >> m;
    forn(i, m) {
        int x, l, r, k;
        scanf("%d %d %d", &x, &l, &r);
        if (x == 0) {
            update(1, 1, nmax, l, r);
            continue;
        } else {
            scanf("%d", &k);
            printf("%d\n", get(l, r, k));
        }
    }

//  cerr << clock() << endl;


    return 0;
}