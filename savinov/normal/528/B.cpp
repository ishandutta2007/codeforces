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


struct fen {
    vector <int> x;

    fen(int n) {
        x.resize(n);
    }

    int get(int r) {
        int res = 0;
        for (; r >= 0; r &= r + 1, --r) {
            res = max(res, x[r]);
        }
        return res;
    }
    void re(int r, int val) {
        for (; r < x.size(); r |= r + 1) {
            x[r] = max(x[r], val);
        }
    }
};

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "a"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt();

    PII a[n];

    int b[n];
    for (int i = 0; i < n; ++i) {
        a[i].x = nxt();
        a[i].y = nxt();
        b[i] = (a[i].x + a[i].y);
    }

    sort(b, b + n);
    int sz = unique(b, b + n) - b;

    fen f(sz);


    sort(a, a + n);

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int p = upper_bound(b, b + sz, a[i].x - a[i].y) - b - 1;
        int v = f.get(p) + 1;
        ans = max(ans, v);
        f.re(lower_bound(b, b + sz, a[i].x + a[i].y) - b, v);
    }

    cout << ans << "\n";


#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}