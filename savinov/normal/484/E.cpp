#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define x first
#define y second
#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)
#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))

using namespace std;

template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR;

typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

struct data {
    int l;
    int r;
    int mid;
    int len;
};


void merge(const data & l, const data & r, data & res) {
    res.len = l.len + r.len;
    res.mid = 0;
    remax(res.mid, l.mid);
    remax(res.mid, r.mid);
    remax(res.mid, l.r + r.l);

    if (l.len == l.l) {
        res.l = l.l + r.l;
    } else {
        res.l = l.l;
    }
    if (r.len == r.r) {
        res.r = r.r + l.r;
    } else {
        res.r = r.r;
    }
}

struct node {
    data info;
    int val;

    node *l, *r;

    node(int v) {
        val = v;
        info = data{v, v, v, 1};
    }

    node(node *a, node *b) {
        merge(a->info, b->info, info);
        l = a, r = b;
    }
};

node * build(int tl, int tr) {
    if (tr - tl == 1) {
        return new node(0);
    }
    int tm = (tl + tr) / 2;
    return new node(build(tl, tm), build(tm, tr));
}

node * update(node * v, int tl, int tr, int pos, int val) {
    if (tr - tl == 1) {
        return new node(val);
    }
    int tm = (tl + tr) / 2;
    if (pos < tm) {
        return new node(update(v->l, tl, tm, pos, val), v->r);
    } else {
        return new node(v->l, update(v->r, tm, tr, pos, val));
    }
}

data get(node * v, int tl, int tr, int l, int r) {
    if (l >= r) return data{0, 0, 0, 0};
    if (tl == l && tr == r) {
        return v->info;
    }
    int tm = (tl + tr) / 2;

    data res;
    merge(get(v->l, tl, tm, l, min(tm, r)), get(v->r, tm, tr, max(tm, l), r), res);
    return res;
}

void print(node * v, int tl, int tr) {
    if (tr - tl == 1) {
        cout << v->val << " ";
        return;
    }
    int tm = (tl + tr) / 2;
    print(v->l, tl, tm);
    print(v->r, tm, tr);
}

int main() {
    srand(33);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //string filename = "immetric";
    //freopen((filename + ".in").c_str(), "r", stdin);
    //freopen((filename + ".out").c_str(), "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    in(n);
    int h[n];
    int id[n];
    for (int i = 0; i < n; ++i) {
        h[i] = nxt();
        id[i] = i;
    }
    node * st[n + 1];
    st[0] = build(0, n);
    sort(id, id + n, [&](int a, int b) {
        return h[a] > h[b];
    });
    for (int i = 0; i < n; ++i) {
        int cur = id[i];
        st[i + 1] = update(st[i], 0, n, cur, 1);
    }
    in(q);
    while (q--) {
        in(l); in(r);
        --l;
        in(w);

        int lo = 0, hi = n - 1;

        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            data res = get(st[mid + 1], 0, n, l, r);
            if (res.mid < w) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        //print(st[lo + 1], 0, n);
        cout << h[id[lo]] << "\n";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#endif

    return 0;
}