#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

//#define next next12345
//#define prev prev12345
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

template<class T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
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
const ld PI = 3.1415926535897932384626433832795L;

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

bool check(int v) {
    if (v < 2) return false;
    for (int i = 2; i * i <= v; ++i) {
        if (v % i == 0) {
            return false;
        }
    }
    return true;
}

long long pw(long long a, long long n, long long m) {
    ll res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}


void pre() {

}

struct Line {
    long long m, b;

    long long eval(long long x) {
        return m * x + b;
    }
};

//fb(x_inter(a, c)) - y_inter(a, c)
long long comp(Line a, Line b, Line c) {
    return (b.m - a.m) * (c.b - a.b) + (b.b - a.b) * (a.m - c.m);
}

struct Hull {
    vector <Line> lines;

    void add(const Line &line) {
        while (lines.size() >= 2 && comp(lines[lines.size() - 2], lines[lines.size() - 1], line) >= 0) {
            lines.pop_back();
        }
        lines.push_back(line);
    }

    int ptr = 0;

    long long eval(long long x) {
        while (ptr > 0 && lines[ptr].eval(x) < lines[ptr - 1].eval(x)) {
            --ptr;
        }
        while (ptr + 1 < lines.size() && lines[ptr].eval(x) < lines[ptr + 1].eval(x)) {
            ++ptr;
        }
        return lines[ptr].eval(x);
    }
};

void solve(int test) {
    int n = nxt();
    long long a[n];
    long long s[n + 1];
    s[0] = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }
    partial_sum(a, a + n, s + 1);

    Hull h;

    long long ans = LLONG_MIN;
    for (int i = 0; i <= n; ++i) {
        h.add(Line{i, -s[i]});
    }
    int order[n];
    iota(order, order + n, 0);
//    shuffle(order, order + n, generator);
    sort(order, order + n, [&](int u, int v) {
        return a[u] > a[v];
    });

    for (int i : order) {
        long long value = h.eval(a[i]) + s[i] - a[i] * i;
        ans = max(ans, value);
    }
    for (int i = 0; i < n; ++i) {
        ans += (i + 1) * a[i];
    }
    cout << ans << "\n";
}



int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sociology"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int t = 1;
//    pre();
#ifdef LOCAL
#endif
    pre();
    int c = 0;
    while (t--) {
        solve(++c);
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}