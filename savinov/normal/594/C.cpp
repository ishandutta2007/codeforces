#include <bits/stdc++.h>
#include <x86intrin.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define ford(i, n) for (int i = (n) - 1; i >= 0; --i)
#define in(x) int (x); input((x));
#define x first
#define fi first
#define y second
#define se second
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
typedef pair<int, int> pii;
typedef vector <int> vi;
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

bool check(int v) {
    if (v == 1) return false;
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

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

struct m {
    ll x1, y1;
    ll x2, y2;
};

int k;

vector <int> o[4];

int used[200000];

multiset <ll> x1, y1, x2, y2;

long long ans;

m x[200000];

void rec(int pos, int cnt) {
    if (cnt > k) return;
    if (pos == 4) {
        ans = min(ans, (max(1ll, (*x2.rbegin() - *x1.begin() + 1) / 2)) * max(1ll, ((*y2.rbegin() - *y1.begin() + 1) / 2)));
        return;
    }
    rec(pos + 1, cnt);
    for (int i = 0; i < o[pos].size(); ++i) {
        int p1 = o[pos][i];
        if (!used[p1]) {
            x1.erase(x1.find(x[p1].x1));
            x2.erase(x2.find(x[p1].x2));
            y1.erase(y1.find(x[p1].y1));
            y2.erase(y2.find(x[p1].y2));
            ++cnt;
        }
        ++used[p1];
        rec(pos + 1, cnt);
    }

    for (int i = 0; i < o[pos].size(); ++i) {
        int p1 = o[pos][i];
        if (used[p1] == 1) {
            x1.insert(x[p1].x1);
            x2.insert(x[p1].x2);
            y1.insert(x[p1].y1);
            y2.insert(x[p1].y2);
            --cnt;
        }
        --used[p1];
    }
}

void solve() {
    int n = nxt();
    k = nxt();

    for (int i = 0; i < n; ++i) {
        x[i].x1 = nxt();
        x[i].y1 = nxt();

        x[i].x2 = nxt();
        x[i].y2 = nxt();

        x[i].x1 = x[i].x2 = (x[i].x1 + x[i].x2);
        x[i].y1 = x[i].y2 = (x[i].y1 + x[i].y2);
    }

    vector <int> o1, o2, o3, o4;
    for (int i = 0; i < n; ++i) {
        o1.push_back(i);
        o2.push_back(i);
        o3.push_back(i);
        o4.push_back(i);
    }

    sort(all(o1), [&](int u, int v) {
        return x[u].x1 < x[v].x1;
    });

    sort(all(o2), [&](int u, int v) {
        return x[u].y1 < x[v].y1;
    });

    sort(all(o3), [&](int u, int v) {
        return x[u].x2 > x[v].x2;
    });

    sort(all(o4), [&](int u, int v) {
        return x[u].y2 > x[v].y2;
    });

    o1.resize(k);
    o2.resize(k);
    o3.resize(k);
    o4.resize(k);

    o[0] = o1;
    o[1] = o2;
    o[2] = o3;
    o[3] = o4;
    
    for (int i = 0; i < n; ++i) {
        x1.insert(x[i].x1);
        x2.insert(x[i].x2);
        y1.insert(x[i].y1);
        y2.insert(x[i].y2);
    }

    ans = LLONG_MAX;

    rec(0, 0);
    cout << ans << "\n";
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "atoms"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif


    int t = 1;
    while (t--) {
        solve();
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}