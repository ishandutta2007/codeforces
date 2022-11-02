#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
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

template <class T>
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

int dp[2][1000][1000];

char is_pal[1000][1000];

int color[1000];

int solve(int l, int r, int type) {
    if (l >= r) {
        return 0;
    }

    int & res = dp[type][l][r];
    if (res != -1) {
        return res;
    }

    res = r - l;

    if (is_pal[l][r]) {
        return res = type;
    }

    for (int i = l + 1; i < r; ++i) {
        res = min(res, solve(l, i, type) + solve(i, r, 1));
        res = min(res, solve(l, i, 1) + solve(i, r, type));
    }

    int t = 0;

    while (color[l + t] == color[r - t - 1]) {
        int L = l + t + 1;
        int R = r - t - 1;
        res = min(res, solve(L, R, 0) + type);
        ++t;
    }
    return res;
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "ticket-office"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    memset(dp, 255, sizeof(dp));

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> color[i];
    }

    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            char ok = true;
            for (int j = 0; l + j < r - j; ++j) {
                if (color[l + j] != color[r - j]) {
                    ok = false;
                    break;
                }
            }
            is_pal[l][r + 1] = ok;
        }
    }

    cout << solve(0, n, 1) << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}