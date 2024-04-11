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

    double x[4];

    for (int i = 0; i < 4; ++i) {
        x[i] = nxt();
    }

    double l = 0, r = 1e30;

    int it = 100000;

    while (it--) {
        double m = (l + r) / 2;

        double t[4][4];

        for (int i = 0; i < 4; ++i) {
            t[i][0] = x[i] - m;
            t[i][1] = x[i] + m;
            if (t[i][0] <= 0 && t[i][1] >= 0) {
                t[i][2] = 0;
            } else {
                t[i][2] = x[i];
            }
            t[i][3] = x[i];
        }

        double L = 1e200, R = -1e200;

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    for (int p = 0; p < 4; ++p) {
                        double val = t[0][i] * t[3][j] - t[1][k] * t[2][p];
                        L = min(L, val);
                        R = max(R, val);
                    }
                }
            }
        }

        if (L <= 0 && R >= 0) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << setprecision(15) << fixed;
    cout << l << "\n";


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}