#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;

const ld PI = 3.1415926535897932384626433832795L;

template<class T>
bool uin(T &, const T &);

template<class T>
bool uax(T &, const T &);

template<class T>
T gcd(T, T);

template<class T>
T lcm(T, T);

template<class _T>
inline string tostr(const _T &);

template<typename T>
void input(T &);

template<typename T = long long>
T nxt();

bool checkp(long long);

template <typename T>
T pw(T a, T n, T p);

template <typename T>
T inv(T a, T p);

void pre() {
}

int mod = 30011;

template <class T>
void walshTransform(vector <T> &data) {
    int n = (int) data.size();
    for (int len = 2; len <= n; len <<= 1) {
        int len2 = len >> 1;
        for (int r = 0; r < n; r += len) {
            int p1 = r, p2 = p1 + len2;
            for (int j = 0; j < len2; ++j, ++p1, ++p2) {
                T u = data[p1];
                T v = data[p2];
                data[p1] = u + v;
                data[p2] = u - v;
            }
        }
    }
}

void NO() {
    cout << "Impossible\n";
    exit(0);
}

void find(string x, int &a, int &b, int &c, int &d) {
    a = b = c = d = 0;
    for (int i = 0; i < x.length(); ++i) {
        for (int j = i + 1; j < x.length(); ++j) {
            if (x[i] == '0' && x[j] == '0') ++a;
            if (x[i] == '0' && x[j] == '1') ++b;
            if (x[i] == '1' && x[j] == '0') ++c;
            if (x[i] == '1' && x[j] == '1') ++d;
        }
    }
}

void solve(int test) {
//    string z = "110101011";
//    int a, b, c, d;
////    cin >> a >> b >> c >> d;
//    find(z, a, b, c, d);
    int a = nxt();
    int b = nxt();
    int c = nxt();
    int d = nxt();

    int e = b + c;

    if (e == 0) {
        if (a && d) {
            NO();
        }
        if (!a && !d) {
            cout << "0\n";
            return;
        }
        int v = a + d;
        int x;
        for (x = 1; x * (x - 1) / 2 < v; ++x) {

        }
        if (x * (x - 1) / 2 == v) {
            if (a) {
                cout << string(x, '0') << endl;
            } else {
                cout << string(x, '1') << endl;
            }
            return;
        }
        NO();
    }

    int x, y;

    for (x = 1; x * (x - 1) / 2 < a; ++x) {}
    for (y = 1; y * (y - 1) / 2 < d; ++y) {}

    if (x * (x - 1) / 2 != a) NO();
    if (y * (y - 1) / 2 != d) NO();

    if (x * y != b + c) NO();

    int u = b / x;
    int v = b % x;

    string ans;

    if (v == 0) {
        ans = string(y - u, '1') + string(x, '0') + string(u, '1');
    } else {
        ans = string(y - u - 1, '1') + string(v, '0') + "1" + string(x - v, '0') + string(u, '1');
    }
#ifdef LOCAL
    int A, B, C, D;
    find(ans, A, B, C, D);
    assert(A == a && B == b && C == c && D == d);
#endif
    cout << ans << endl;

}


int main(int argc, char **argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    pre();
    int t = 1;
#ifdef LOCAL
#else
#endif
    for (int test = 1; test <= t; ++test) {
        solve(test);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}


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


template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') {}
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

template<typename T = long long>
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

bool checkp(long long v) {
    if (v < 2) return false;
    for (long long i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}
template <typename T>
T pw(T a, T n, T m) {
    T res = 1;
    while (n) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

template <typename T>
T inv(T a, T p) {
    T res = 1;
    while (a > 1) {
        res = res * (p - p / a) % p;
        a = p % a;
    }
    return res;
}


template<class T>
bool uin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}