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

struct event {
    long long pos;
    int add;
    int type;

    bool operator<(const event &r) const {
        return pos < r.pos;
    }
};

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

    int h = nxt();
    int q = nxt();

    vector <event> e;

    int cntGood = 1;

    e.push_back({1ll << (h - 1), +1, 1});
    e.push_back({(1ll << (h - 1)) + 1, 0, 2});

    e.push_back({1ll << h, -1, 1});
    e.push_back({(1ll << h) - 1, 0, 2});

    while (q--) {
        int level = nxt();
        long long l = nxt<ll>();
        long long r = nxt<ll>();
        int ans = nxt();

        e.push_back({l << (h - level), +1, ans});
        e.push_back({(l << (h - level)) - 1, 0, 2});
        e.push_back({(l << (h - level)) + 1, 0, 2});
        e.push_back({((r + 1) << (h - level)), -1, ans});
        e.push_back({((r + 1) << (h - level)) - 1, 0, 2});
        e.push_back({((r + 1) << (h - level)) - 2, 0, 2});

        cntGood += ans;
    }

    sort(all(e));

    int c[3];
    clr(c);

    long long ans = -1;

    for (int i = 0; i < (int)e.size(); ++i) {
        int j = i;
        while (j < (int)e.size() && e[j].pos == e[i].pos) {
            ++j;
        }
        for (int k = i; k < j; ++k) {
            c[e[k].type] += e[k].add;
        }

        if (c[1] == cntGood && c[0] == 0) {
            if (ans != -1) {
                cout << "Data not sufficient!\n";
                return 0;
            }
            ans = e[i].pos;
        }

        i = j - 1;
    }

    if (ans == -1) {
        cout << "Game cheated!\n";
        return 0;
    }

    cout << ans << "\n";



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}