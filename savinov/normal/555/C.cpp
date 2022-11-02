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

long long mod = 1000000123;

struct st {
    vector <int> a;
    int sz;
    st(int n = 0) {
        sz = n;
        a.assign(sz + sz, INT_MAX);
    }

    void update(int pos, int val) {
        pos += sz;
        a[pos] = min(a[pos], val);

        for (; pos > 1; pos >>= 1) {
            a[pos >> 1] = min(a[pos], a[pos ^ 1]);
        }
    }

    int get(int l, int r) {
        int res = INT_MAX;
        for (l += sz, r += sz; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if (l & 1) {
                res = min(res, a[l]);
            }
            if (!(r & 1)) {
                res = min(res, a[r]);
            }
        }
        return res;
    }

    int get2(int pos, int val) {
        int l = pos, r = sz;
        while (l < r) {
            int mid = (l + r) / 2;
            if (get(pos, mid) > val) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};


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

    int n = nxt();
    int q = nxt();

    int x[q], y[q], d[q];

    vector <int> xx;
    vector <int> yy;

    for (int i = 0; i < q; ++i) {
        x[i] = nxt() - 1;
        y[i] = nxt() - 1;
        char s[2];
        scanf("%s", s);
        d[i] = s[0] == 'L';
        if (d[i] == 0) {
            yy.push_back(y[i]);
        } else {
            xx.push_back(x[i]);
        }
    }
    xx.push_back(n);
    yy.push_back(n);
    sort(all(yy));
    sort(all(xx));
    xx.erase(unique(all(xx)), xx.end());
    yy.erase(unique(all(yy)), yy.end());

    st X(xx.size());
    st Y(yy.size());

    set <PII> used;

    for (int i = 0; i < q; ++i) {
        if (used.count({x[i], y[i]})) {
            cout << "0\n";
            continue;
        }
        if (d[i] == 1) {
            int p = lower_bound(all(yy), y[i]) - yy.begin();
            int z = Y.get2(p, y[i]);
            int res;
            if (z == yy.size()) {
                res = 0;
            } else {
                res = n - yy[z];
            }
            cout << (x[i] - res + 1) << "\n";
            X.update(lower_bound(all(xx), x[i]) - xx.begin(), res);
        } else {
            int p = lower_bound(all(xx), x[i]) - xx.begin();
            int z = X.get2(p, x[i]);
            int res;
            if (z == xx.size()) {
                res = 0;
            } else {
                res = n - xx[z];
            }
            cout << (y[i] - res + 1) << "\n";
            Y.update(lower_bound(all(yy), y[i]) - yy.begin(), res);
        }
        used.insert({x[i], y[i]});
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}