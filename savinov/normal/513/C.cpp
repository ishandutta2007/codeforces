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



int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "guard"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt();

    int l[n], r[n];
    int len[n];

    int minl = INT_MAX;
    int maxr = INT_MIN;

    for (int i = 0; i < n; ++i) {
        l[i] = nxt(), r[i] = nxt();
        //l[i] = 1, r[i] = 10000;
        len[i] = r[i] - l[i] + 1;
        minl = min(minl, l[i]);
        maxr = max(maxr, r[i]);
    }

    double ans = 0;

    double mul1[10001][n];
    double mul2[10001][n];

    for (int j = 0; j < n; ++j)
    for (int i = 1; i < 10001; ++i) {
        if (i > r[j]) {
            mul1[i][j] = len[j];
            mul2[i][j] = len[j];
        } else {
            mul1[i][j] = max(0, i - l[j] + 1);
            mul2[i][j] = max(0, i - l[j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = l[i]; j <= r[i]; ++j) {
            for (int pr = 1; pr < j; ++pr) {
                double c1 = 1, c2 = 1;
                for (int k = 0; k < n; ++k) {
                    if (k == i) {
                        continue;
                    }
                    c1 *= mul1[pr][k];
                    c2 *= mul2[pr][k];
//                    if (pr > r[k]) {
//                        c1 *= len[k];
//                        c2 *= len[k];
//                    } else {
//                        c1 *= max(0, pr - l[k] + 1);
//                        c2 *= max(0, pr - l[k]);
//                    }
                }
                ans += pr * (c1 - c2);
            }
        }
    }


    for (int i = 1; i < (1 << n); ++i) {
        if (i & (i - 1)) {
            for (int p = minl; p <= maxr; ++p) {
                char ok = true;
                for (int j = 0; j < n; ++j) {
                    if (i & (1 << j)) {
                        if (l[j] > p || r[j] < p) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (!ok) continue;
                double c1 = 1;
                for (int j = 0; j < n; ++j) {
                    if (!(i & (1 << j))) {
                        if (p > r[j]) {
                            c1 *= r[j] - l[j] + 1;
                        } else {
                            c1 *= max(0, p - l[j]);
                        }
                    }
                }
                ans += p * c1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        ans /= (r[i] - l[i] + 1);
    }
    cout << setprecision(10) << fixed;
    cout << ans << "\n";

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