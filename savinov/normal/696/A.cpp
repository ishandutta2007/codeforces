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

ll lca(ll x, ll y) {
    vector <ll> pa, pb;
    while (x) {
        pa.pb(x);
        x >>= 1;
    }
    x = y;
    while (x) {
        pb.pb(x);
        x >>= 1;
    }

    reverse(all(pa));
    reverse(all(pb));

    ll last = 0;

    for (int i = 0; i < pa.size() && i < pb.size(); ++i) {
        if (pa[i] == pb[i]) {
            last = pa[i];
        } else {
            break;
        }
    }
    return last;
}


map <ll, ll> A;


void add(ll x, ll y, ll w) {
    ll z = lca(x, y);
    while (x != z) {
        A[x] += w;
//        cerr << x << " " << w << endl;
        x >>= 1;
    }
    x = y;
    while (x != z) {
        A[x] += w;

//        cerr << x << " " << w << endl;
        x >>= 1;
    }
}

ll get(ll x, ll y) {
    ll res = 0;
    ll z = lca(x, y);
    while (x != z) {
        auto it = A.find(x);
        if (it != A.end()) {
            res += it->y;
        }
        x >>= 1;
    }
    x = y;
    while (x != z) {
        auto it = A.find(x);
        if (it != A.end()) {
            res += it->y;
        }
        x >>= 1;
    }
    return res;
}

void solve(int test) {
    int q = nxt();
//    cerr << lca(6, 7) << endl;
    while (q--) {
        int t = nxt();
        if (t == 1) {
            ll x = nxt<ll>();
            ll y = nxt<ll>();
            ll w = nxt<ll>();
            add(x, y, w);
        } else {
            ll x = nxt<ll>();
            ll y = nxt<ll>();
            cout << get(x, y) << "\n";
        }

    }
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