#include "bits/stdc++.h"

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

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

struct data {
    int a, b, c;
    bool operator<(const data & r) const {
        if (a != r.a) {
            return a < r.a;
        }
        if (b != r.b) {
            return b > r.b;
        }
        return c < r.c;
    }
};

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "war"
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int n = nxt();

    data a[n];
    int A[n], B[n], C[n];

    for (int i = 0; i < n; ++i) {
        A[i] = nxt();
    }

    for (int i = 0; i < n; ++i) {
        B[i] = -nxt();
    }

    for (int i = 0; i < n; ++i) {
        C[i] = nxt();
    }

    for (int i = 0; i < n; ++i) {
        a[i] = data{A[i], B[i], C[i]};
    }

    sort(A, A + n);
    sort(B, B + n);
    sort(C, C + n);

    int s1 = unique(A, A + n) - A;
    int s2 = unique(B, B + n) - B;
    int s3 = unique(C, C + n) - C;

    for (int i = 0; i < n; ++i) {
        a[i].a = lower_bound(A, A + s1, a[i].a) - A;
        a[i].b = lower_bound(B, B + s2, a[i].b) - B;
        a[i].c = lower_bound(C, C + s3, a[i].c) - C;
    }

    sort(a, a + n);

    int st[s2];
    memset(st, 255, sizeof(st));

    int ans = 0;

    for (int i = n - 1; i >= 0; --i) {
        int j = i;
        while (j >= 0 && a[i].a == a[j].a) {
            char ok = false;
            for (int r = a[j].b - 1; !ok && r >= 0; r &= r + 1, --r) {
                ok |= st[r] > a[j].c;
            }
            ans += ok;
            --j;
        }
        j = i;
        while (j >= 0 && a[i].a == a[j].a) {
            for (int r = a[j].b; r < s2; r |= r + 1) {
                st[r] = max(st[r], a[j].c);
            }
            --j;
        }
        i = j + 1;
    }

    cout << ans << "\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}