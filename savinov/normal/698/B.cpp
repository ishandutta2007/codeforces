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


struct dsu {
    vi p;

    dsu(int n) {
        p.resize(n);
        iota(all(p), 0);
    }

    int get(int v) {
        if (p[v] == v) return v;
        return p[v] = get(p[v]);
    }

    bool unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) return false;
        p[a] = b;
        return true;
    }
};

void solve(int test) {
    int n = nxt();
    int p[n];
    forn(i, n) p[i] = nxt() - 1;

    dsu d(n);

    int root = -1;

    forn(i, n) if (p[i] == i) root = i;

    int ans = 0;

    forn(i, n) {
        if (i == root) {
            continue;
        }
        if (!d.unite(i, p[i])) {
            if (root == -1) {
                root = i;
            }
            p[i] = root;
            ++ans;
        }
    }

    cout << ans << "\n";
    forn(i, n) cout << p[i] + 1 << " ";
    cout << "\n";

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