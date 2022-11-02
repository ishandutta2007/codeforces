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


void pre() {

}

void gen() {

}


void read() {
    int n = nxt();
    ll A = nxt();
    ll B = nxt();

    vector <int> p;

    int a[n];
    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }


    long long inf = 1e18;
    long long ans = inf;
    
    for (int ee = 0; ee < 2; ++ee) {

        for (int Q = a[0] - 1; Q <= a[0] + 1; ++Q) {
            int x = Q;
            for (int i = 2; i * i <= x; ++i) {
                if (x % i == 0) {
                    p.push_back(i);
                    while (x % i == 0) {
                        x /= i;
                    }
                }
            }
            if (x > 1) {
                p.push_back(x);
            }
        }

        sort(all(p));
        p.erase(unique(all(p)), p.end());


        cerr << "OK" << endl;

        for (int pr : p) {
            int l = 0;
            long long s1[n + 1];
            long long s2[n + 1];
            for (int i = 0; i <= n; ++i) {
                s1[i] = inf;
                s2[i] = inf;
            }
            s1[0] = 0;
            s2[n] = 0;
            while (l < n) {
                s1[l + 1] = s1[l];
                if (a[l] % pr == 0) {
                    ++l;
                    continue;
                }
                if ((a[l] + 1) % pr == 0) {
                    s1[l + 1] += 1;
                    ++l;
                    continue;
                }
                if ((a[l] - 1) % pr == 0) {
                    s1[l + 1] += 1;
                    ++l;
                    continue;
                }
                s1[l + 1] = inf;
                break;
            }

            int r = n - 1;
            while (r >= 0) {
                s2[r] = s2[r + 1];
                if (a[r] % pr == 0) {
                    --r;
                    continue;
                }
                if ((a[r] + 1) % pr == 0) {
                    s2[r] += 1;
                    --r;
                    continue;
                }
                if ((a[r] - 1) % pr == 0) {
                    s2[r] += 1;
                    --r;
                    continue;
                }
                s2[r] = inf;
                break;
            }
            long long x[n + 1];
            long long y[n + 1];

            for (int i = 0; i <= n; ++i) {
                if (s1[i] == inf) {
                    x[i] = inf;
                } else {
                    x[i] = B * s1[i] - A * i;
                }

                if (s2[i] == inf) {
                    y[i] = inf;
                } else {
                    y[i] = B * s2[i] + A * i;
                }
            }

            long long mx = inf;

            for (int i = 0; i <= n; ++i) {
                mx = min(mx, x[i]);
                ans = min(ans, y[i] + mx);
            }
        }
        reverse(a, a + n);
    }

    cout << ans << endl;
}


void solve2() { }


int main(int argc, char ** argv) {

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
#endif

//    test();

    int c = 0;
    while (t--) {
        //gen();
        read();
//        gen();
//        gen2();
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}