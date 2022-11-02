#include "bits/stdc++.h"

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

#define next next12345
#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const long double PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int c;
    a = 0;
    while (!isdigit(c = getchar()) && c != '-') {}
    char neg = 0;
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        a = 10 * a + c - '0';
        c = getchar();
    }
    if (neg) a = -a;
}


template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

inline string next() {
    static int c;
    string res;
    while (isspace(c = getchar())) {}
    while (!isspace(c)) {
        res = res + (char)c;
        c = getchar();
    }
    return res;
}

const int MAXMEM = 2e8;

char buf[MAXMEM];
char * cur = buf;

void * operator new(size_t n) {
    char * res = cur;
    cur += n;
    assert(cur - buf <= MAXMEM);
    return res;
}

void operator delete(void * x) {
}

struct node {
    int value;
    node *l, *r;

    node(int value) : value(value), l(0), r(0) {}
    node(node *l, node *r) : l(l), r(r) {
        value = min(l->value, r->value);
    }
};

int get(node *v, int tl, int tr, int l, int r) {
    if (l > r) {
        return INT_MAX;
    }
    if (tl == l && tr == r) {
        return v->value;
    }
    int tm = (tl + tr) / 2;
    return min(get(v->l, tl, tm, l, min(r, tm)), get(v->r, tm + 1, tr, max(tm + 1, l), r));
}

node* update(node *v, int tl, int tr, int pos, int value) {
    if (tl == tr) {
        return new node(value);
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        return new node(update(v->l, tl, tm, pos, value), v->r);
    } else {
        return new node(v->l, update(v->r, tm + 1, tr, pos, value));
    }
}

node* init(int tl, int tr) {
    if (tl == tr) {
        return new node(INT_MIN);
    }
    int tm = (tl + tr) / 2;
    return new node(init(tl, tm), init(tm + 1, tr));
}


int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "a"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt(), m = nxt(), k = nxt(), q = nxt();

    PII a[k];

    for (int i = 0; i < k; ++i) {
        a[i].x = nxt();
        a[i].y = nxt();
    }

    node * byX[n + 1];
    byX[0] = init(1, m);
    node * byY[m + 1];
    byY[0] = init(1, n);

    sort(a, a + k, [&](PII u, PII v) {
        return u.x < v.x;
    });

    for (int i = 1, j = 0; i <= n; ++i) {
        byX[i] = byX[i - 1];
        while (j < k && a[j].x == i) {
            byX[i] = update(byX[i], 1, m, a[j++].y, i);
        }
    }

    sort(a, a + k, [&](PII u, PII v) {
        return u.y < v.y;
    });

    for (int i = 1, j = 0; i <= m; ++i) {
        byY[i] = byY[i - 1];
        while (j < k && a[j].y == i) {
            byY[i] = update(byY[i], 1, n, a[j++].x, i);
        }
    }

    while (q--) {
        int x1 = nxt(), y1 = nxt();
        int x2 = nxt(), y2 = nxt();

        bool ok = false;

        ok = ok || get(byX[x2], 1, m, y1, y2) >= x1;
        ok = ok || get(byY[y2], 1, n, x1, x2) >= y1;

        puts(ok ? "YES" : "NO");
    }

#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}