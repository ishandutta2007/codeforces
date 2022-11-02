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

    int n, x0, y0;
    n = nxt(), x0 = nxt(), y0 = nxt();

    vector <PII> a;

    for (int i = 0; i < n; ++i) {
        int x = nxt() - x0;
        int y = nxt() - y0;
        if (x < 0) {
            x = -x, y = -y;
        } else {
            if (x == 0) {
                y = abs(y);
            }
        }
        int g = gcd(abs(x), abs(y));
        x /= g, y /= g;
        a.pb({x, y});
    }
    sort(all(a));
    cout << unique(all(a)) - a.begin() << "\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}