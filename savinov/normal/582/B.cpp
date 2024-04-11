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


long long mod = 1000000007;

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long inv(long long a) {
    return pw(a, mod - 2);
}


int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "race"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif


    int n = nxt();
    int t = nxt();

    int a[n];

    for (int i = 0; i < n; ++i) {
        a[i] = nxt() - 1;
    }

    if (t >= 2 * n) {
        int dp1[301];
        clr(dp1);
        for (int i = 0; i < n * n; ++i) {
            dp1[a[i % n]] = max(dp1[a[i % n]], *max_element(dp1, dp1 + a[i % n] + 1) + 1);
        }
        int dp2[301];
        clr(dp2);
        for (int i = n * n - 1; i >= 0; --i) {
            dp2[a[i % n]] = max(dp2[a[i % n]], *max_element(dp2 + a[i % n], dp2 + 301) + 1);
        }
        int cnt[301];
        clr(cnt);
        for (int i = 0; i < n; ++i) {
            cnt[a[i]]++;
        }
        int ans = 0;
        for (int u = 0; u <= 300; ++u) {
            int mx = 0;
            for (int v = u; v <= 300; ++v) {
                mx = max(mx, cnt[v]);
                ans = max(ans, dp1[u] + dp2[v] + mx * (t - 2 * n));
            }
        }
        cout << ans << "\n";
    } else {
        int dp1[301];
        clr(dp1);
        for (int i = 0; i < n * t; ++i) {
            dp1[a[i % n]] = max(dp1[a[i % n]], *max_element(dp1, dp1 + a[i % n] + 1) + 1);
        }
        cout << *max_element(dp1, dp1 + 301) << endl;
    }



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}