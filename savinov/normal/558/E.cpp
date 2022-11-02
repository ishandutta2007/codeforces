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

void fib(unsigned long long n, long long &x, long long &y) {
    if (n == 1) {
        x = 0, y = 1;
        return;
    }
    if (n & 1ull) {
        fib(n - 1, y, x);
        y += x;
        y %= mod;
    } else {
        long long a, b;
        fib(n / 2, a, b);
        x = (a * a + b * b) % mod;
        y = (2 * a + b) * b % mod;
    }
}

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

long long pw(long long a, long long n, long long m) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

const int K = 26;

struct data {
    int cnt[K];

    data() {
        clr(cnt);
    }

    data(const data &r) {
        memcpy(cnt, r.cnt, sizeof(cnt));
    }


    data & operator=(const data & r) {
        if (&r == this) {
            return *this;
        }
        memcpy(cnt, r.cnt, sizeof(cnt));
        return *this;
    }

    void operator+=(const data &r) {
        for (int i = 0; i < K; ++i) {
            cnt[i] += r.cnt[i];
        }
    }

    void clear() {
        clr(cnt);
    }

    void split(int len, int type, data &l, data &r) {
        if (type == 1) {
            int c = 0;

            for (int i = 0; i < K; ++i) {
                int need = min(len - c, cnt[i]);
                c += need;
                l.cnt[i] = need;
                r.cnt[i] = cnt[i] - need;
            }
        } else {
            int c = 0;

            for (int i = K - 1; i >= 0; --i) {
                int need = min(len - c, cnt[i]);
                c += need;
                l.cnt[i] = need;
                r.cnt[i] = cnt[i] - need;
            }
        }
    }
};

data add[1 << 18];
int flag[1 << 18];
data sum[1 << 18];
int len[1 << 18];

void push(int v) {
    if (flag[v]) {
        add[v].split(len[v + v], flag[v], add[v + v], add[v + v + 1]);
        sum[v + v] = add[v + v];
        sum[v + v + 1] = add[v + v + 1];
        flag[v + v] = flag[v + v + 1] = flag[v];
        flag[v] = 0;
    }
}

data get(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return data();
    }

    if (tl == l && tr == r) {
        return sum[v];
    }
    push(v);
    int tm = (tl + tr) / 2;

    data res;
    res += get(v + v, tl, tm, l, min(r, tm));
    res += get(v + v + 1, tm + 1, tr, max(tm + 1, l), r);

    return res;
}

void sort(int v, int tl, int tr, int l, int r, data x, int type) {
    if (l > r) return;

    if (tl == l && tr == r) {
        flag[v] = type;
        sum[v] = add[v] = x;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;

    int k = max(0, min(r, tm) - l + 1);

    data a, b;
    x.split(k, type, a, b);

    sort(v + v, tl, tm, l, min(r, tm), a, type);
    sort(v + v + 1, tm + 1, tr, max(tm + 1, l), r, b, type);

    sum[v].clear();
    sum[v] += sum[v + v];
    sum[v] += sum[v + v + 1];
}

string s;

void init(int v, int tl, int tr) {
    if (tl == tr) {
        len[v] = 1;
        sum[v].cnt[s[tl] - 'a'] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    init(v + v, tl, tm);
    init(v + v + 1, tm + 1, tr);
    sum[v] += sum[v + v];
    sum[v] += sum[v + v + 1];
    len[v] = len[v + v] + len[v + v + 1];
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "carpet"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int n = nxt();
    int q = nxt();
    cin >> s;
    init(1, 0, n - 1);
    while (q--) {
        int l = nxt() - 1;
        int r = nxt() - 1;
        int x = (nxt() ^ 1) + 1;
        data v = get(1, 0, n - 1, l, r);
        sort(1, 0, n - 1, l, r, v, x);



    }

    for (int i = 0; i < n; ++i) {
        data p = get(1, 0, n - 1, i, i);
        cout << (char)(max_element(p.cnt, p.cnt + 26) - p.cnt + 'a');
    }
    cout << "\n";




#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}