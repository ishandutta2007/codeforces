#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

//#define next next12345
//#define prev prev12345
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

template<class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
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
const ld PI = 3.1415926535897932384626433832795L;

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

bool check(int v) {
    if (v < 2) return false;
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

long long pw(long long a, long long n, long long m) {
    ll res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}



long long bin[5][5];

void pre() {
    for (int i = 0; i < 5; ++i) {
        bin[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            bin[i][j] = bin[i - 1][j] + bin[i - 1][j - 1];
        }
    }
}

void read() {

}




void test() {
//    auto l = get("99");
//    l.debug();
//    auto r = get("1");
//    r.debug();
//    auto d = merge(l, r);
//    d.debug();
//    exit(0);
}


long long mod = 1000000007;

void solve() {
    int n = nxt();
    int a[n];
    map <int, int> cnt;
    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
        cnt[a[i]]++;
    }
    vector <pair <int, int> > x;
    for (auto v : cnt) {
        x.push_back(v);
    }
    long long pr[x.size() + 1];
    pr[0] = 1;
    for (int i = 0; i < x.size(); ++i) {
        pr[i + 1] = pr[i] * (x[i].y + 1) % (mod - 1);
    }
    long long su[x.size() + 1];
    su[x.size()] = 1;
    for (int i = (int)x.size() - 1; i >= 0; --i) {
        su[i] = su[i + 1] * (x[i].y + 1) % (mod - 1);
    }
    long long ans = 1;
    for (int i = 0; i < x.size(); ++i) {
        long long q = pr[i] * su[i + 1] % (mod - 1);
        for (int k = 1; k <= x[i].y; ++k) {
//            cerr << q * k << endl;
            ans = ans * pw(x[i].x, q * k % (mod - 1), mod) % mod;
        }
    }
    cout << ans << endl;
}

void solve2() {

}


int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "d"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int t = 1;
    pre();
#ifdef LOCAL
    test();
#endif
    while (t--) {
        read();
        solve();
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}