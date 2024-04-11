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

//typedef vector <vector <long long> > matrix;

long long mod = 1000000007;

long long many = 7 * mod * mod;

const int N = 111;

struct matrix {
    long long u[N][N];
    matrix() {
        clr(u);
    }
};

void operator*=(matrix &l, const matrix &r) {
    matrix res;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                res.u[i][j] += l.u[i][k] * r.u[k][j];
                if (res.u[i][j] >= many) {
                    res.u[i][j] -= many;
                }
            }
            res.u[i][j] %= mod;
        }
    }
    memcpy(l.u, res.u, sizeof(res.u));
}

void pw(matrix a, matrix & res, int n) {
    for (int i = 0; i < N; ++i) {
        res.u[i][i] = 1;
    }
    while (n) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
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

    int n = nxt();
    int x = nxt();

    int d[n];

    for (int i = 0; i < n; ++i) {
        d[i] = nxt();
    }


    matrix M;

    for (int i = 0; i < n; ++i) {
        M.u[0][d[i] - 1]++;
    }

    const int K = 101;

    for (int i = 1; i < K; ++i) {
        M.u[i][i - 1] = 1;
    }
    M.u[K + 1][K + 1] = 1;
    M.u[0][K + 1] = 1;

    matrix X;
    pw(M, X, x);

    long long ans =  X.u[0][K + 1] + X.u[0][0];

    ans %= mod;

    cout << ans << "\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}