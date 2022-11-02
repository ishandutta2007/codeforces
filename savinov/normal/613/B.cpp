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



void pre() { }

void read() { }

void test() { }

void solve() {
    int n = nxt();
    long long A = nxt<ll>();
    long long cf = nxt<ll>();
    long long cm = nxt<ll>();
    long long m = nxt<ll>();

    long long a[n + 1];

    for (int i = 0; i < n; ++i) {
        a[i] = nxt<ll>();
    }

    int o[n + 1];
    iota(o, o + n, 0);
    sort(o, o + n, [&](int u, int v) {
        return a[u] < a[v];
    });
    long long b[n];
    for (int i = 0; i < n; ++i) {
        b[i] = a[o[i]];
    }
    long long s[n + 1];

    s[0] = 0;

    for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] + a[o[i]];
    }

    long long k = m;

    long long best = -1;
    int pos = -1;

    for (int i = n - 1; i >= 0; --i) {
        if (k < 0) break;
        long long l = a[o[0]], r = A;
        while (l < r) {
            long long mid = (l + r + 1) / 2;
            int p = lower_bound(b, b + i + 1, mid) - b;
            long long su = mid * p - s[p];
            if (su > k) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        long long q = l * cm + cf * (n - i - 1);
        if (q > best) {
            best = q;
            pos = i;
        }
        k -= A - a[o[i]];
    }

    if (k >= 0) {
        long long q = n * cf + cm * A;
        if (q > best) {
            best = q;
            pos = -1;
        }
    }
    cout << best << "\n";
    cerr << pos << endl;
    if (pos == -1) {
        for (int i = 0; i < n; ++i) {
            cout << A << " ";
        }
        cout << "\n";
        return;
    }
    k = m;
    for (int i = n - 1; i >= 0; --i) {
        if (pos == i) {
            long long l = a[o[0]], r = A;
            while (l < r) {
                long long mid = (l + r + 1) / 2;
                int p = lower_bound(b, b + i + 1, mid) - b;
                long long su = mid * p - s[p];
                if (su > k) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            for (int j = 0; j < n && a[o[j]] < l; ++j) {
                a[o[j]] = l;
            }
            for (int j = i + 1; j < n; ++j) {
                a[o[j]] = A;
            }
            for (int j = 0; j < n; ++j) {
                cout << a[j] << " ";
            }
            cout << "\n";
            return;
        }

        k -= A - a[o[i]];
    }

}


void solve2() { }


int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "d"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int t = 1;
    pre();
#ifdef LOCAL
    test();
#endif
    while (t--) {
        read();
//        gen();
//        gen2();
        solve();
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}