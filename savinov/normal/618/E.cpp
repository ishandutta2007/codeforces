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


int ro[1 << 20];
double dx[1 << 20];
double dy[1 << 20];

double x[1 << 20];
double y[1 << 20];

void build(int v, int tl, int tr) {
    if (tr - tl == 1) {
        x[v] = 1, y[v] = 0;
        return;
    }
    int tm = (tl + tr) / 2;

    build(v + v, tl, tm);
    build(v + v + 1, tm, tr);

    x[v] = x[v + v] + x[v + v + 1];
    y[v] = y[v + v] + y[v + v + 1];
}

void push(int v) {
    ro[v + v] += ro[v];
//    ro[v + v] %= 360;

    ro[v + v + 1] += ro[v];
//    ro[v + v + 1] %= 360;

    ro[v] = 0;
}

void rot(int v, double &a, double &b) {
    double ang = ro[v] / 180.0 * PI;
    double co = cos(ang), si = sin(ang);
    a = x[v] * co - y[v] * si;
    b = x[v] * si + y[v] * co;
}

void add(int v, int tl, int tr, int pos, double delta) {
    if (tr - tl == 1) {
        x[v] += delta;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos < tm) {
        add(v + v, tl, tm, pos, delta);
    } else {
        add(v + v + 1, tm, tr, pos, delta);
    }
    double x1, y1, x2, y2;
    rot(v + v, x1, y1);
    rot(v + v + 1, x2, y2);
    x[v] = x1 + x2;
    y[v] = y1 + y2;
}



void rotate(int v, int tl, int tr, int l, int r, int delta) {
    if (l >= r) {
        return;
    }
    if (tl == l && tr == r) {
        ro[v] += delta;
//        ro[v] %= 360;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;

    rotate(v + v, tl, tm, l, min(tm, r), delta);
    rotate(v + v + 1, tm, tr, max(tm, l), r, delta);

    double x1, y1, x2, y2;
    rot(v + v, x1, y1);
    rot(v + v + 1, x2, y2);
    x[v] = x1 + x2;
    y[v] = y1 + y2;

    //cerr << tl << " " << tr << " " << x[v] << " " << y[v] << " " << ro[v] << endl;
}

void print(int v, int tl, int tr, double ang) {
    //cerr << ang << endl;
    ang += ro[v] / 180.0 * PI;
    if (tr - tl == 1) {
        double co = cos(ang), si = sin(ang);
        double xx = x[v] * co - y[v] * si;
        double yy = x[v] * si + y[v] * co;
//        cerr << tl << " " << xx << " " << yy << " " << ang << endl;
        return;
    }
    int tm = (tl + tr) / 2;
    print(v + v, tl, tm, ang);
    print(v + v + 1, tm, tr, ang);
}

void read() {
    int n = nxt();
    int m = nxt();

    build(1, 0, n);


    while (m--) {
        int type = nxt();
        int pos = nxt() - 1;
        int val = nxt();

        if (type == 1) {
            add(1, 0, n, pos, val);
        } else {
            val = 360 - val;
            rotate(1, 0, n, pos, n, val);
        }
//        cerr << "START" << endl;
//        print(1, 0, n, 0);
//        cerr << "END" << endl;
        double a, b;
        rot(1, a, b);
        printf("%.10f %.10f\n", a, b);
    }
}

void solve2() { }


int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "d"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int t = 1;
    pre();
#ifdef LOCAL
#endif
    int c = 0;
    while (t--) {
        read();
//        gen();
//        gen2();
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}