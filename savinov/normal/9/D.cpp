#include "bits/stdc++.h"

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
    static int c;
    a = 0;
    while (!isdigit(c = getchar()) && c != '-') {}
    char neg = 0;
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        a = 10 * a + c - '0';
        c = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

long long dp[40][40];

long long solve(int n, int h) {
    long long & res = dp[n][h];
    if (res != -1) {
        return res;
    }
    if (n == 0) {
        return res = (h == 0);
    }
    res = 0;
    for (int l = 0; l < n; ++l) {
        for (int h1 = 0; h1 < n; ++h1) {
            for (int h2 = 0; h2 < n; ++h2) {
                if (max(h1, h2) == h - 1) {
                    res += solve(l, h1) * solve(n - 1 - l, h2);
                }
            }
        }
    }
    return res;
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "war"
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    memset(dp, 255, sizeof(dp));
    int n = nxt(), h = nxt();

    long long res = 0;

    for (int i = h; i <= n; ++i) {
        res += solve(n, i);
    }
    cout << res << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}