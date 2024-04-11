#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define in(x) int (x); input((x));
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
typedef int itn;
using namespace std;
using vi = vector<int>;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

typedef long double ld;
typedef long long ll;
typedef pair<int, int> PII;

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

ll mod = 1000000007;



struct M {
    ll x[2][2];

    M() {
        memset(x, 0, sizeof(x));
    }

    void E() {
        x[0][0] = x[1][1] = 1;
    }

    M operator*(const M &r) const {
        M res;
#define F(i, j) res.x[i][j] = (x[i][0] * r.x[0][j] + x[i][1] * r.x[1][j]) % mod;
        F(0, 0);
        F(0, 1);

        F(1, 0);
        F(1, 1);

        return res;
    }
};

M pw(M x, ll n) {
    M res;
    res.E();
    while (n) {
        if (n & 1ll) {
            res = res * x;
        }
        x = x * x;
        n >>= 1;
    }
    return res;
}


void solve(int test) {
    M m;

    m.x[0][0] = 1;//(mod + 1) / 2;
    m.x[0][1] = 2;//(mod + 1) / 2;

    m.x[1][0] = 1;
    m.x[1][1] = 0;

    int k = nxt();

    ll t = 2;
    while (k--) {
        ll z = nxt<ll>();
        m = pw(m, z);
        t = pw(t, z, mod);
    }

    cout << (m.x[1][1] * ((mod + 1) / 2)) % mod << "/" << (t * ((mod + 1) / 2)) % mod << "\n";
}

int main(int argc, char **argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
#endif
#ifdef LOCAL
#else
#endif
//    init();
    int c = 0;
    int t = 1;
    while (t--) {
        solve(c++);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}