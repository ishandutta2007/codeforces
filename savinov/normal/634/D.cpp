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

struct fen {
    vector <int> s;
    fen(int n) {
        s.resize(n);
    }
    void add(int pos, int val) {
        for (; pos < s.size(); pos |= pos + 1) {
            s[pos] += val;
        }
    }

    int get(int pos) {
        int res = 0;
        for (; pos >= 0; pos &= pos + 1, --pos) {
            res += s[pos];
        }
        return res;
    }
};



void solve(int test) {
    int d = nxt();
    int n = nxt();
    int m = nxt();

    pair <int, int> x[m + 1];

    for (int i = 0; i < m; ++i) {
        x[i].x = nxt();
        x[i].y = nxt();
    }
    x[m].x = d;
    x[m].y = 0;
    ++m;

    sort(x, x + m);

    int l = 0, r = n;

    multiset <int> cost;

    int l1 = 0, r1 = 0;
    while (r1 < m && x[r1].x <= r) {
        cost.insert(x[r1].y);
        ++r1;
    }
    long long ans = 0;
    while (r < d) {
        if (cost.empty()) {
            cout << "-1\n";
            return;
        }
        int delta = min(x[r1].x - r, x[l1].x - l);
        assert(delta);

        ans += 1ll * delta * *cost.begin();
        l += delta;
        r += delta;
//        cerr << l << " " << r << endl;
//        cerr << l1 << " " << r1 << endl;
//        cerr << x[l1].x << " " << x[r1].x << endl;
        while (r1 < m && x[r1].x <= r) {
            cost.insert(x[r1].y);
            ++r1;
        }
        while (l1 < m && x[l1].x <= l) {
            cost.erase(cost.find(x[l1].y));
            ++l1;
        }

//        cerr << l1 << " " << r1 << endl;
    }
    cout << ans << endl;
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