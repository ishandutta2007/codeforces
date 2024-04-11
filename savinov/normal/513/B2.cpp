#include "bits/stdc++.h"

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
#define itn int

#define next next12345
#define prev prev12345
#define x1 x12345
#define y1 y12345

using namespace std;

template <typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template <class _T> inline _T sqr(const _T& x) {return x * x;}
template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > PII;
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

template <typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

vector <int> rec(int n, long long mask) {
    if (n == 1) {
        return vector <int>(1, 1);
    }
    if (mask & (1ll << (n - 2))) {
        vector <int> res = rec(n - 1, (1ll << (n - 1)) - mask - 1);
        for (int & x : res) {
            ++x;
        }
        reverse(all(res));
        res.push_back(1);
        return res;
    } else {
        vector <int> res = rec(n - 1, mask);
        vector <int> ret;
        ret.pb(1);
        for (int x : res) {
            ret.pb(x + 1);
        }
        return ret;
    }
}


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "guard"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n;
    long long m;
    cin >> n >> m;
    --m;

    vector <int> res = rec(n, m);

    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

//    int a[n];
//
//    for (int i = 0; i < n; ++i) {
//        a[i] = i;
//    }
//    int need = n * (n + 1) * (n + 2) / 6;
//
//    do {
//        int s = 0;
//        for (int i = 0; i < n; ++i) {
//            int mi = INT_MAX;
//            for (int j = i; j < n; ++j) {
//                mi = min(mi, a[j] + 1);
//                s += mi;
//            }
//        }
//        if (s == need) {
//            for (int i = 0; i < n; ++i) {
//                cout << a[i] + 1 << " ";
//            }
//            cout << endl;
////            --m;
////            if (m == 0) {
////
////                return 0;
////            }
//        }
//    } while(next_permutation(a, a + n));

//    int n = nxt();
//    int k = nxt();
//
//    int a[n];
//    for (int i = 0; i < n; ++i) {
//        a[i] = nxt();
//    }
//    int s[n + 1];
//    s[0] = 0;
//    for (int i = 0; i < n; ++i) {
//        s[i + 1] = s[i] + a[i];
//    }
//
//    int dp[n + 1][n + 1][k + 1];
//    memset(dp, 0, sizeof(dp));
//
//    for (int i = 0; i < n; ++i) {
//        for (int j = i; j < n; ++k) {
//            for (int l = j + 1)
//        }
//        for (int j = 0; j < k; ++j) {
//            int s = 0;
//            for (int l = i; l < n; ++l) {
//                s += a[l];
//                dp[l + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + abs(s));
//            }
//        }
//    }
//
//    cout << dp[n][k] << "\n";


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
};