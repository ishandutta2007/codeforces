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


int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "guard"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n, m, k;
    n = nxt(), m = nxt(), k = nxt();

    int a[m][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[j][i] = nxt();
        }
    }

    const int K = 17;
    int ma[m][K][n];

    for (int i = 0; i < m; ++i) {
        auto cur = ma[i];
        for (int j = 0; j < n; ++j) {
            cur[0][j] = a[i][j];
        }
        for (int j = 1; j < K; ++j) {
            memcpy(cur[j], cur[j - 1], sizeof(cur[j]));
            for (int l = 0; l + (1 << (j - 1)) < n; ++l) {
                cur[j][l] = max(cur[j][l], cur[j - 1][l + (1 << (j - 1))]);
            }
        }
    }
    int best = 0;
    int bcnt[m];
    clr(bcnt);
    for (int i = 0; i < n; ++i) {
        int cnt[m];
        clr(cnt);
        int pos = i;
        for (int j = K - 1; pos < n && j >= 0; --j) {
            int cc[m];
            for (int l = 0; l < m; ++l) {
                cc[l] = max(cnt[l], ma[l][j][pos]);
            }
            int ss = accumulate(cc, cc + m, 0);
            if (ss <= k) {
                pos = min(n, pos + (1 << j));
                memcpy(cnt, cc, sizeof(cnt));
            }
        }
        if (pos - i > best) {
            best = pos - i;
            memcpy(bcnt, cnt, sizeof(cnt));
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << bcnt[i] << " ";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}