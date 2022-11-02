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
typedef vector<long long> vll;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;

const ld PI = 3.1415926535897932384626433832795L;

template<class T>
bool uin(T &, const T &);

template<class T>
bool uax(T &, const T &);

template<class T>
T gcd(T, T);

template<class T>
T lcm(T, T);

template<class _T>
inline string tostr(const _T &);

template<typename T>
void input(T &);

template<typename T = long long>
T nxt();

bool checkp(long long);

template<typename T>
T pw(T a, T n, T p);

template<typename T>
T inv(T a, T p);

void pre() {

}


struct basis {
    int pos[62];
    ll x[62];
    int sz;
    basis() {
        sz = 0;
        memset(pos, 255, sizeof(pos));
    }
    void add(ll v) {
        forn(i, 62) {
            if (v & (1ll << i)) {
                if (pos[i] == -1) {
                    x[sz] = v;
                    pos[i] = sz++;
                    return;
                } else {
                    v ^= x[pos[i]];
                }
            }
        }
        assert(v == 0);
    }
};

ll s[1 << 20];

vector <pair <int ,ll >> g[1 << 20];

int used[1 << 20];

vll t;

void dfs(int v, int p, basis &b, int &cnt) {
    used[v] = 1;
    t.push_back(s[v]);
    ++cnt;
    for (auto x : g[v]) {
        int to = x.x;
        ll l = x.y;
        if (to == p) continue;
        if (used[to] == 2) continue;

        if (used[to] == 1) {
            b.add(s[v] ^ s[to] ^ l);
        } else {
            s[to] = s[v] ^ l;
            dfs(to, v, b, cnt);
        }
    }
    used[v] = 2;
}


void solve(int test) {
    int n = nxt();
    int m = nxt();

    forn(i, m) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        ll x = nxt();
        g[u].pb(mp(v, x));
        g[v].pb(mp(u, x));
    }
    ll mod = 1000000007;

    ll bin[63][63];
    clr(bin);



    for (int i = 0; i <= 62; ++i) {
        bin[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            bin[i][j] = bin[i - 1][j] + bin[i - 1][j - 1];
            bin[i][j] %= mod;
        }
    }

    ll zero[63][63];
    ll one[63][63];
    clr(zero);
    clr(one);

    ll two[63];
    clr(two);
    two[0] = 1;
    forn(i, 62) {
        two[i + 1] = two[i] * 2 % mod;
    }

    for (int a = 0; a <= 62; ++a) {
        for (int b = 0; a + b <= 62; ++b) {
            for (int x = 0; x <= a; ++x) {
                if (x % 2 == 1) {
                    one[a][b] += bin[a][x] * two[b];
                    one[a][b] %= mod;
                } else {
                    zero[a][b] += bin[a][x] * two[b];
                    zero[a][b] %= mod;
                }
            }
        }
    }
    ll ans[62];
    clr(ans);

    forn(i, n) {
        if (!used[i]) {
            basis b;
            int cnt = 0;
            t.clear();
            dfs(i, i, b, cnt);
            int ca[62], cb[62];
            clr(ca);
            clr(cb);
            forn(j, b.sz) forn(k, 62) {
                    if (b.x[j] & (1ll << k)) {
                        ca[k]++;
                    } else {
                        cb[k]++;
                    }
                }

            int C[62][2];
            clr(C);

            for (ll v : t) {
                forn(j, 62) {
                    if (v & (1ll << j)) {
                        ans[j] += C[j][1] * one[ca[j]][cb[j]];
                        ans[j] += C[j][0] * zero[ca[j]][cb[j]];
                        C[j][1]++;
                    } else {
                        ans[j] += C[j][0] * one[ca[j]][cb[j]];
                        ans[j] += C[j][1] * zero[ca[j]][cb[j]];
                        C[j][0]++;
                    }
                }
            }

        }
    }
    ll res = 0;
    forn(i, 62) {
        res = (res + ans[i] % mod * two[i] % mod) % mod;
    }
    cout << res << "\n";
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
    pre();
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
    while (!isdigit(ed = getchar()) && ed != '-') {}
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

template<typename T = long long>
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

template<typename T>
T pw(T a, T n, T m) {
    T res = 1;
    while (n) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

template<typename T>
T inv(T a, T p) {
    T res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}


template<class T>
bool uin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}