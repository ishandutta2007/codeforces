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

long long f[51];

vector <int> get(int n, long long k) {
    if (n == 1) {
        return vector <int>(1, 0);
    }
    if (n == 2) {
        if (k == 0) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    if (k < f[n - 1]) {
        vector <int> res = get(n - 1, k);
        for (int & x : res) {
            ++x;
        }
        res.insert(res.begin(), 0);
        return res;
    } else {
        k -= f[n - 1];
        vector <int> res = get(n - 2, k);
        for (int & x : res) {
            x += 2;
        }
        res.insert(res.begin(), 0);
        res.insert(res.begin(), 1);
        return res;
    }
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

    f[1] = 1;
    f[2] = 2;

    for (int i = 3; i <= 50; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    cerr << f[50] << "\n";

    int n = nxt();
    long long k = nxt<ll>() - 1;

    vector <int> ans = get(n, k);

    for (int x : ans) {
        cout << x + 1 << " ";
    }
//    cout << "\n";
//
//    vector <int> a;
//    for (int i = 0; i < n; ++i) {
//        a.push_back(i);
//    }
//
//    int cnt = 0;
//
//    do {
//        vector <vector <int>>  cycles;
//        vector <int> used(n);
//        for (int i = n - 1; i >= 0; --i) {
//            if (!used[i]) {
//                cycles.push_back(vector <int>());
//                int v = i;
//                while (!used[v]) {
//                    used[v] = 1;
//                    cycles.back().push_back(v);
//                    v = a[v];
//                }
//            }
//        }
//        sort(all(cycles));
//        vector <int> b;
//        for (auto x : cycles) {
//            for (auto y : x) {
//                b.push_back(y);
//            }
//        }
//        if (a == b) {
////            for (int x : a) {
////                cout << x << " ";
////            }
////            cout << "\n";
//            vector <int> z = get(n, cnt);
//            assert(a == z);
////            for (int x : z) {
////                cout << x << " ";
////            }
////            cout << "\n";
//            ++cnt;
//        }
//    } while (next_permutation(all(a)));
//
//    cout << cnt << "\n";


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}