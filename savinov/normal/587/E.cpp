#include <bits/stdc++.h>


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
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

mt19937 generator;


long long mod = 1000000007;

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return pw(a, mod - 2);
}

struct data {
    int x;
    vector <int> rows;
    int fb[31];

    data() {
        memset(fb, 255, sizeof(fb));
        x = 0;
    }

    void clear() {
        x = 0;
        memset(fb, 255, sizeof(fb));
        rows.clear();
    }
};

void add(data &l, int x) {
    for (int j = 0; j < 31; ++j) {
        if (x & (1 << j)) {
            if (l.fb[j] == -1) {
                l.fb[j] = (int)l.rows.size();
                l.rows.push_back(x);
                break;
            } else {
                x ^= l.rows[l.fb[j]];
            }
        }
    }
}

void merge(data &l, const data &r) {
    for (int i = 0; i < r.rows.size(); ++i) {
        int x = r.rows[i];
        if (x & (1 << 30)) {
            x ^= r.x;
        }
        //int x = r.rows[i] ^ r.x;
        add(l, x);
    }
}

data st[1 << 19];

void build(int v, int tl, int tr, int *a) {
    //cerr << v << " " << tl << " " << tr << endl;
    if (tr - tl == 1) {
        add(st[v], a[tl] ^ (1 << 30));
        return;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm, a);
    build(v + v + 1, tm, tr, a);
    merge(st[v], st[v + v]);
    merge(st[v], st[v + v + 1]);
}

void push(int v) {
    st[v + v].x ^= st[v].x;
    st[v + v + 1].x ^= st[v].x;
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if (l >= r) return;
    if (tl == l && tr == r) {
        st[v].x ^= x;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v + v, tl, tm, l, min(r, tm), x);
    update(v + v + 1, tm, tr, max(tm, l), r, x);
    st[v].clear();
    merge(st[v], st[v + v]);
    merge(st[v], st[v + v + 1]);
}

void get(int v, int tl, int tr, int l, int r, data &res) {
    if (l >= r) return;
    if (l == tl && r == tr) {
        merge(res, st[v]);
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    get(v + v, tl, tm, l, min(r, tm), res);
    get(v + v + 1, tm, tr, max(tm, l), r, res);
    st[v].clear();
    merge(st[v], st[v + v]);
    merge(st[v], st[v + v + 1]);
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "race"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt();
    int q = nxt();

    int a[n];

    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }


    build(1, 0, n, a);


    while (q--) {
        int t = nxt();
        if (t == 1) {
            int l = nxt() - 1;
            int r = nxt();
            int x = nxt();
            update(1, 0, n, l, r, x);
        } else {
            int l = nxt() - 1;
            int r = nxt();
            data res;
            get(1, 0, n, l, r, res);

            for (int & v : res.rows) {
                if (v & (1 << 30)) {
                    v ^= (1 << 30);
                }
            }

            data res2;
            merge(res2, res);

            cout << (1ll << res2.rows.size()) << "\n";
        }
    }


    //01
    //10

    //11
    //00

    //11
    //01

    //01
    //10


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}