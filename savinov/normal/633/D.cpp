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

void solve(int test) {
    int n = nxt();
    int a[n];
    map <int, int> cnt;
    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
        cnt[a[i]]++;
    }

    vector <pair <int, int> > q;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                q.pb(mp(a[i], a[j]));
            }
        }
    }

    sort(all(q));
    q.erase(unique(all(q)), q.end());

    vector <int> x(q.size(), -1);
    vector <int> y(q.size(), -1);

    for (int i = 0; i < q.size(); ++i) {
        auto v = q[i];
        auto z = mp(v.y, v.x + v.y);
        auto pos = lower_bound(all(q), z);
        if (pos != q.end() && *pos == z) {
            x[i] = pos - q.begin();
            y[pos - q.begin()] = i;
        }
    }

    vector <vector <int> > chains;
    char used[q.size()];
    clr(used);

    for (int i = 0; i < q.size(); ++i) {
        if (used[i]) continue;
        if (y[i] == -1 && x[i] != -1) {
            int v = i;
            vector <int> chain;
            while (x[v] != -1) {
                used[v] = 1;
                chain.pb(q[v].x);
                v = x[v];
            }
            used[v] = 1;
            chain.pb(q[v].x);
            chain.pb(q[v].y);
            chains.pb(chain);
        }
    }

    vector <vector <int> > cycles;

    for (int i = 0; i < q.size(); ++i) {
        if (used[i]) continue;
        if (x[i] != -1) {
            int v = i;
            vector <int> chain;
            while (x[v] != -1 && !used[v]) {
                used[v] = 1;
                chain.pb(q[v].x);
                v = x[v];
            }
            cycles.pb(chain);
        }
    }
    int ans = 2;
    for (auto chain : chains) {
        int l = 0, r = 0;
        while (r < chain.size()) {
            while (cnt[chain[r]] == 0) {
                cnt[chain[l++]] += 1;
            }
            cnt[chain[r++]] -= 1;
            ans = max(ans, r - l + 0);
        }
        while (l < r) {
            cnt[chain[l++]] += 1;
        }
    }

    for (auto chain : cycles) {
        map <int, int> cc;
        for (int x : chain) {
            cc[x] += 1;
        }
        int mx = INT_MAX;
        for (auto v : cc) {
            mx = min(cnt[v.x] / v.y, mx);
        }
        for (auto v : cc) {
            cnt[v.x] -= mx * v.y;
        }
        int l = 0, r = 0;
        while (r < chain.size()) {
            while (cnt[chain[r]] == 0) {
                cnt[chain[l++]] += 1;
            }
            cnt[chain[r++]] -= 1;
            ans = max(ans, r - l + mx);
        }
        while (l < r) {
            cnt[chain[l++]] += 1;
        }
        for (auto v : cc) {
            cnt[v.x] += mx * v.y;
        }
    }

    cout << ans << endl;


}

int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sociology"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int t = 1;
//    pre();
#ifdef LOCAL
#endif
    ios_base::sync_with_stdio(false);

    int c = 0;
    while (t--) {
        solve(++c);
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}