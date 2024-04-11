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

void myassert(bool v) {
    assert(v);
    //cout << "FAIL\n";
    //exit(0);
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
    int k = nxt();

    long long a[n + 2];
    long long b[n + 2];


    clr(b);
    clr(a);

    for (int i = 0; i <= n; ++i) {
        a[i] = nxt();
        b[i] = a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (b[i] < 0) {
            if (b[i] % 2 == 0) {
                b[i + 1] += b[i] / 2;
                b[i] = 0;
            } else {
                b[i + 1] += (b[i] - 1) / 2;
                b[i] = 1;
            }
        } else {
            if (b[i] % 2 == 0) {
                b[i + 1] += b[i] / 2;
                b[i] = 0;
            } else {
                b[i + 1] += (b[i] - 1) / 2;
                b[i] = 1;
            }
        }
    }

//    for (int i = 0; i <= n; ++i) {
//        cerr << b[i] << " ";
//    }
//    cerr << endl;

    int isNegative = 0;

    for (int j = n; j >= 0; --j) {
        if (b[j]) {
            isNegative = b[j] < 0;
            break;
        }
    }

    if (isNegative) {
        for (int i = 0; i <= n; ++i) {
            a[i] = -a[i];
            b[i] = a[i];
        }
        cerr << "NEG\n";
    } else {
        for (int i = 0; i <= n; ++i) {
            b[i] = a[i];
        }
    }



    for (int i = 0; i < n; ++i) {
        if (b[i] < 0) {
            if (b[i] % 2 == 0) {
                b[i + 1] += b[i] / 2;
                b[i] = 0;
            } else {
                b[i + 1] += (b[i] - 1) / 2;
                b[i] = 1;
            }
        } else {
            if (b[i] % 2 == 0) {
                b[i + 1] += b[i] / 2;
                b[i] = 0;
            } else {
                b[i + 1] += (b[i] - 1) / 2;
                b[i] = 1;
            }
        }
    }

//    for (int i = 0; i <= n; ++i) {
//        cerr << b[i] << " ";
//    }
//    cerr << endl;

    for (int j = n; j >= 0; --j) {
        if (b[j]) {
            assert(b[j] > 0);
            break;
        }
    }

//    for (int i = 0; i <= n; ++i) {
//        cerr << b[i] << " ";
//    }
//    cerr << endl;


    int ans = 0;

    for (int i = 0; i <= n; ++i) {
        if (b[i] % 2 != 0 || i == n) {
            long long delta = 0;
            for (int j = n; j >= i; --j) {
                delta = delta * 2 + b[j];
                if (abs(delta) > 2e18) {
                    cout << "0\n";
                    return;
                }
            }
            cerr << delta << "\n";
            int j = i;
            while (delta <= 2e18 && j >= 0) {
                if (j == n) {
                    if (delta != a[j] && abs(delta - a[j]) <= k) {
                        ++ans;
                    }
                } else {
                    if (abs(delta - a[j]) <= k) {
                        ans += 1;
                    }
                }

                --j;
                delta = delta * 2;
            }
            cout << ans << "\n";
            return;
        }
    }
}


int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
#ifdef LOCAL

    int t = 1;
#else
    int t = 1;
#endif
    int c = 0;
    while (t--) {
        solve(++c);
    }




#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}