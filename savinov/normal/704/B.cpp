#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector <long long> vll;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;

const ld PI = 3.1415926535897932384626433832795L;

template <class T> bool uin(T&, const T&);
template <class T> bool uax(T&, const T&);
template<class T> T gcd(T, T);
template<class T> T lcm(T, T);
template<class _T> inline string tostr(const _T&);
template<typename T> void input(T&);
template<typename T = long long> T nxt();
bool checkp(long long);
long long pw(long long a, long long n, long long p);
long long inv(long long a, long long p);


void solve(int test) {
    int n = nxt();

    int s = nxt() - 1;
    int e = nxt() - 1;

    vi x(n), a(n), b(n), c(n), d(n);

    forn(i, n) x[i] = nxt();
    forn(i, n) a[i] = nxt();
    forn(i, n) b[i] = nxt();
    forn(i, n) c[i] = nxt();
    forn(i, n) d[i] = nxt();

    ll dp[n + 1][3];

    memset(dp, 0x3f, sizeof(dp));

    ll inf = dp[0][0];

    dp[0][1] = 0;

    for (int i = 0; i < n; ++i) {

        ll tmp[n + 1][3];
        memset(tmp, 0x3f, sizeof(dp));
        if (i == s) {
            for (int I = 0; I <= n; ++I) {
                for (int O = I - 1; O <= I + 1; ++O) {
                    int j = O - I + 1;
                    if (dp[I][j] == inf) continue;

                    do {
                        // I - 1, O
                        int nI = I - 1;
                        int nO = O;
                        int nj = nO - nI + 1;
                        if (nI < 0 || nI > n || nj > 2 || nj < 0 || nO < 0 || nO > n) break;
                        uin(tmp[nI][nj], dp[I][j] + x[i] + c[i]);
                    } while (0);

                    do {
                        // O + 1, I
                        //if (i > 0 && O == 0 && I == 0) break;
                        int nI = I;
                        int nO = O + 1;
                        int nj = nO - nI + 1;
                        if (nI < 0 || nI > n || nj > 2 || nj < 0 || nO < 0 || nO > n) break;
                        uin(tmp[nI][nj], dp[I][j] - x[i] + d[i]);
                    } while (0);
                }
            }
        } else if (i == e) {
            for (int I = 0; I <= n; ++I) {
                for (int O = I - 1; O <= I + 1; ++O) {
                    int j = O - I + 1;
                    if (dp[I][j] == inf) continue;

                    do {
                        // I, O - 1
                        int nI = I;
                        int nO = O - 1;
                        int nj = nO - nI + 1;
                        if (nI < 0 || nI > n || nj > 2 || nj < 0 || nO < 0 || nO > n) break;
                        uin(tmp[nI][nj], dp[I][j] + x[i] + a[i]);
                    } while (0);

                    do {
                        // O, I + 1
                        if (i && I == 0 && j == 0) break;
                        int nI = I + 1;
                        int nO = O;
                        int nj = nO - nI + 1;
                        if (nI < 0 || nI > n || nj > 2 || nj < 0 || nO < 0 || nO > n) break;
                        uin(tmp[nI][nj], dp[I][j] - x[i] + b[i]);
                    } while (0);
                }
            }
        } else {
            for (int I = 0; I <= n; ++I) {
                for (int O = I - 1; O <= I + 1; ++O) {
                    int j = O - I + 1;
                    if (dp[I][j] == inf) continue;
                    //-><-
                    do {
                        // I - 1, O - 1
                        int nI = I - 1;
                        int nO = O - 1;
                        int nj = nO - nI + 1;
                        if (nI < 0 || nI > n || nj > 2 || nj < 0 || nO < 0 || nO > n) break;
                        uin(tmp[nI][nj], dp[I][j] + x[i] + a[i] + x[i] + c[i]);
                    } while (0);
                    //->->
                    do {
                        if (O == 0) break;
                        int nI = I;
                        int nO = O;
                        int nj = nO - nI + 1;
                        if (nI < 0 || nI > n || nj > 2 || nj < 0 || nO < 0 || nO > n) break;
                        uin(tmp[nI][nj], dp[I][j] + a[i] + d[i]);
                    } while (0);
                    //<-<-
                    do {
                        if (I == 0) break;
                        int nI = I;
                        int nO = O;
                        int nj = nO - nI + 1;
                        if (nI < 0 || nI > n || nj > 2 || nj < 0 || nO < 0 || nO > n) break;
                        uin(tmp[nI][nj], dp[I][j] + c[i] + b[i]);
                    } while (0);
                    //<-->
                    do {
                        if (i && I == 0 && O == 0) break;
                        int nI = I + 1;
                        int nO = O + 1;
                        int nj = nO - nI + 1;
                        if (nI < 0 || nI > n || nj > 2 || nj < 0 || nO < 0 || nO > n) break;
                        uin(tmp[nI][nj], dp[I][j] + d[i] - x[i] + b[i] - x[i]);
                    } while (0);
                }
            }
        }
        memcpy(dp, tmp, sizeof(dp));
    }
    cout << dp[0][1] << "\n";

}


int main(int argc, char **argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(false);
//    pre();
//    test();
//    exit(0);
    int t = 1;
#ifdef LOCAL
#else
#endif
    for (int test = 1; test <= t; ++test) {
        solve(test);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}



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

bool checkp(long long v) {
    if (v < 2) return false;
    for (long long i = 2; i * i <= v; ++i) {
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



template <class T>
bool uin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool uax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}