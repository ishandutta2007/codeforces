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

struct dsu {
    vector <int> p;
    vector <int> size;
    int mx;

    void init(int n) {
        p.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
            size[i] = 1;
        }
        mx = 1;
    }

    int get(int v) {
        if (p[v] != v) {
            p[v] = get(p[v]);
        }
        return p[v];
    }

    void unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) {
            return;
        }
        if (size[a] > size[b]) {
            swap(a, b);
        }
        p[a] = b;
        size[b] += size[a];
        mx = max(mx, size[b]);
    }
};

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "a"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int w = nxt(), h = nxt(), n = nxt();

    int tp[n], p[n];

    dsu A, B;
    A.init(h);
    B.init(w);

    char u1[h], u2[w];
    clr(u1);
    clr(u2);

    for (int i = 0; i < n; ++i) {
        char s[2];
        int v;
        scanf("%s%d", s, &v);

        if (s[0] == 'H') {
            tp[i] = 0;
            p[i] = v;
            u1[v] = 1;
        } else {
            tp[i] = 1;
            p[i] = v;
            u2[v] = 1;
        }
    }

    for (int i = 1; i < h; ++i) {
        if (!u1[i]) {
            A.unite(i - 1, i);
        }
    }

    for (int i = 1; i < w; ++i) {
        if (!u2[i]) {
            B.unite(i - 1, i);
        }
    }
    long long ans[n];

    for (int i = n - 1; i >= 0; --i) {

        ans[i] = (long long)A.mx * B.mx;
        if (tp[i] == 0) {
            A.unite(p[i], p[i] - 1);
        } else {
            B.unite(p[i], p[i] - 1);
        }
    }


    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }

#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}