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

void fib(unsigned long long n, long long &x, long long &y) {
    if (n == 1) {
        x = 0, y = 1;
        return;
    }
    if (n & 1ull) {
        fib(n - 1, y, x);
        y += x;
        y %= mod;
    } else {
        long long a, b;
        fib(n / 2, a, b);
        x = (a * a + b * b) % mod;
        y = (2 * a + b) * b % mod;
    }
}

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

    int x[n], y[n];

    for (int i = 0; i < n; ++i) {
        x[i] = nxt(), y[i] = nxt();
    }

    set <long long> used[n];
    vector <long long> z;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];

            int a = -dy;
            int b = dx;
            int c = a * x[i] + b * y[i];
            int d = 1;
            if (a < 0 || (a == 0 && b < 0)) {
                a *= -1;
                b *= -1;
                c *= -1;
            }
            d = gcd(abs(a), abs(b));
            a /= d, b /= d;
            int gg = gcd(abs(d), abs(c));
            c /= gg;
            d /= gg;

            a += 300;
            b += 300;
            c += 300 * 300 * 2;
            d += 300;

            long long h = 0;
            h = h * 711 + a;
            h = h * 711 + b;
            h = h * 300 * 300 * 2 * 4 + c;
            h = h * 711 + d;

            if (!used[i].count(h)) {
                z.push_back(h);
                used[i].insert(h);
            }
            if (!used[j].count(h)) {
                used[j].insert(h);
                z.push_back(h);
            }
        }
    }

    long long ans = (long long)n * (n - 1) * (n - 2);

    sort(all(z));

    for (int i = 0; i < (int)z.size(); ++i) {
        int j = i;
        while (j < z.size() && z[i] == z[j]) {
            ++j;
        }
        long long T = j - i;
        ans -= T * (T - 1) * (T - 2);
        i = j - 1;
    }


    ans /= 6;

    cout << ans << "\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}