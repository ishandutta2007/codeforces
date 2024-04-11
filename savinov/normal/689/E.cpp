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

ll f[1 << 20];
ll mod = 1000000007;
void init() {

    forn(i, 1 << 20) {
        if (i == 0) {
            f[i] = 1;
        } else {
            f[i] = i * f[i - 1] % mod;
        }
    }
}

void solve(int test) {
    int n = nxt();
    int k = nxt();

    vector <PII> x;

    forn(i, n) {
        int l = nxt();
        int r = nxt() + 1;
        x.pb(make_pair(l, 1));
        x.pb(make_pair(r, -1));
    }

    sort(all(x));
    int s = 0;
    ll ans = 0;
    for (int i = 0; i < x.size(); ) {
        int j = i;
        while (j < x.size() && x[i].x == x[j].x) {
            s += x[j].y;
            ++j;
        }
        if (j == x.size()) break;
        if (s >= k) {
            ll len = (x[j].x - x[i].x) % mod;
//            cerr << s << " " << len << endl;
            ans += f[s] * pw(f[s - k], mod - 2, mod) % mod * pw(f[k], mod - 2, mod) % mod * len % mod;
        }
        i = j;
    }
    ans %= mod;
    cout << ans << "\n";

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
    init();
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