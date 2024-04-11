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

struct data {
    long long m1;
    long long m2;
    long long m3;
};

long long inf = 2e18;

data merge(const data &l, const data &r) {
    data res;
    res.m1 = max(l.m1, r.m1);
    res.m2 = max(l.m2, r.m2);
    res.m3 = max(r.m2 + l.m1, max(l.m3, r.m3));
    return res;
}



int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "strings"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    //cout << sizeof(tt) + sizeof(qq) + sizeof(ff) + sizeof(used) + sizeof(ans) << "\n";

    int n = nxt();
    int m = nxt();


    int k = 2 * n;

    int N = 1;
    while (N < k) {
        N *= 2;
    }
    long long d[n];
    long long h[n];

    for (int i = 0; i < n; ++i) {
        d[i] = nxt();
    }
    for (int i = 0; i < n; ++i) {
        h[i] = nxt();
    }
    long long s[k + 1];
    long long hh[k + 1];

    s[0] = 0;

    for (int i = 0; i < k; ++i) {
        int j = i % n;
        s[i + 1] = s[i] + d[j];
        hh[i] = 2 * h[j];
    }

    data st[N + N];

    for (int i = 0; i < k; ++i) {
        st[i + N] = {hh[i] - s[i], hh[i] + s[i], -inf};
        //cout << st[i + N].m1 << " " << st[i + N].m2 << " " << st[i + N].m3 << endl;
    }

    data neut = {-inf, -inf, -inf};

    for (int i = k; i < N; ++i) {
        st[i + N] = neut;
    }

    for (int i = N - 1; i > 0; --i) {
        st[i] = merge(st[i + i], st[i + i + 1]);
    }

    while (m--) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        int l, r;
        if (a <= b) {
            l = b + 1, r = n + a - 1;
        } else {
            l = n + b + 1, r = n + a - 1;
        }
        data L = neut, R = neut;
        for (l += N, r += N; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if (l & 1) {
                L = merge(L, st[l]);
            }
            if (!(r & 1)) {
                R = merge(st[r], R);
            }
        }
        data ans = merge(L, R);
        cout << ans.m3 << "\n";
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}