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

template <class T>
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

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "parts"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    int n = nxt();
    int m = nxt();

    pair <int, pair <int, int> > x[m];

    for (int i = 0; i < m; ++i) {
        int w = nxt();
        int take = nxt() ^ 1;
        x[i] = mp(w, mp(take, i));
    }
    sort(x, x + m);

    int size = 1;

    PII ans[m];

    int last[n];
    for (int i = 0; i < n; ++i) {
        last[i] = i + 2;
    }

    auto cmp = [&](const int &l, const int &r) {
        return last[l] < last[r] || (last[l] == last[r] && l < r);
    };

    set <int, decltype(cmp)> q(cmp);

    for (int i = 0; i < n; ++i) {
        q.insert(i);
    }

    for (int i = 0; i < m; ++i) {
//        cerr << x[i].y.x << endl;
        if (x[i].y.x == 0) {
            ans[x[i].y.y] = mp(size, size + 1);
            ++size;
        } else {
            int best = *q.begin();
            if (last[best] < size) {
                q.erase(q.begin());
                ans[x[i].y.y] = mp(best + 1, last[best] + 1);
                last[best]++;
                q.insert(best);
            } else {
                cout << "-1\n";
                return 0;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i].x << " " << ans[i].y << "\n";
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}