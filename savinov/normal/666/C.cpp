#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)

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

void myassert(bool v) {
    assert(v);
    //cout << "FAIL\n";
    //exit(0);
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

long long inv(long long a, long long p) {
    long long res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}

char b[1 << 20];

int get() {
    scanf("%s", b);
    int l = strlen(b);
    return l;
}

long long re[1 << 20];
const int N = 100001;
long long mod = 1000000007;

void pre() {
    re[0] = 1;
    re[1] = 1;
    for (int i = 2; i < N + 10; ++i) {
        re[i] = (mod / i * re[mod % i]) % mod;
        re[i] = (mod - re[i]) % mod;
    }
}

inline void M(long long &x) {
    if (x >= mod) {
        x %= mod;
    }
}

void solve(int test) {
    int m = nxt();
    int l = get();
    vector <int> lens;
    vector <pair <int, int> > q;
    map <int, vector <int> > v;
    while (m--) {
        int t = nxt();
        if (t == 2) {
            int z = nxt();
            q.pb(mp(l, z));
            v[l].pb(z);
        } else {
            l = get();
        }
    }

    map <pair <int, int>, long long> d;

    for (auto it = v.begin(); it != v.end(); ++it) {
        auto len = it->first;
        auto r = it->second;
        sort(all(r));
        r.erase(unique(all(r)), r.end());

        int pos = lower_bound(all(r), len) - r.begin();
        int last = r.back();
        long long ans = 1;
        long long f = len * 25 % mod;
        for (int i = len; i <= last; ++i) {
            if (pos < r.size() && r[pos] == i) {
                //cerr << len << " " << i << " " << ans << "\n";
                d[mp(len, i)] = ans;
                ++pos;
            }
            ans = ans * 26 + f;
            M(ans);
            f = f * 25 * (i + 1);
            M(f);
            f = f * re[i - len + 2];
            M(f);
        }
    }

    for (auto r : q) {
        cout << d[r] << "\n";
    }

}


int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    pre();
    int t = 1;

#ifdef LOCAL
#else
#endif
    int c = 0;

    while (t--) {
        solve(++c);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}