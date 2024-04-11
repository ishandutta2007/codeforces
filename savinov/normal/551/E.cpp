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

long long mod = 1000000007;

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

const int N = 1000000;

long long t[N];

int n;

void add(int pos, long long v) {
    for (; pos < n; pos |= pos + 1) {
        t[pos] += v;
    }
}

void add(int l, int r, long long v) {
    add(l, v);
    add(r, -v);
}

long long get(int pos) {
    long long res = 0;
    for (; pos >= 0; pos &= pos + 1, --pos) {
        res += t[pos];
    }
    return res;
}

set <int> bounds;

long long numbers[N];
long long a[N];
vector <long long> pos[N];

int sz;

void recalc() {
    sz = 0;
    for (int i = 0; i < n; ++i) {
        a[i] += get(i);
        numbers[i] = a[i];
        add(i, i + 1, -get(i));
    }
    sort(numbers, numbers + n);
    sz = unique(numbers, numbers + n) - numbers;

    for (int i = 0; i < sz; ++i) {
        pos[i].clear();
    }

    for (int i = 0; i < n; ++i) {
        int p = lower_bound(numbers, numbers + sz, a[i]) - numbers;
        pos[p].push_back(i);
    }

    bounds.clear();
    bounds.insert(0);
    bounds.insert(n);
}

pair <int, int> findLeftRight(int l, int r, long long val) {
    pair <int, int> res = {INT_MAX, INT_MIN};
    if (!binary_search(numbers, numbers + sz, val)) {
        return res;
    }
    int p = lower_bound(numbers, numbers + sz, val) - numbers;

    auto it1 = lower_bound(pos[p].begin(), pos[p].end(), l);
    auto it2 = lower_bound(pos[p].begin(), pos[p].end(), r);

    if (it2 != pos[p].begin()) {
        --it2;
        if (*it2 >= l) {
            res.y = *it2;
        }
    }
    if (it1 != pos[p].end()) {
        if (*it1 < r) {
            res.x = *it1;
        }
    }
    return res;
}

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

    n = nxt();
    int m = nxt();


    for (int i = 0; i < n; ++i) {
        a[i] = nxt();
    }
    const int MAGIC = 2000;

    recalc();

    while (m--) {
        int t = nxt();

        if (t == 1) {
            int l = nxt() - 1;
            int r = nxt();
            bounds.insert(l);
            bounds.insert(r);
            long long x = nxt();
            add(l, r, x);
        } else {
            long long y = nxt();

            int left = INT_MAX;
            int right = INT_MIN;

            for (auto it = bounds.begin(), it2 = ++bounds.begin(); it2 != bounds.end(); ++it, ++it2) {
                auto z = findLeftRight(*it, *it2, y - get(*it));
                left = min(left, z.x);
                right = max(right, z.y);
            }

            if (left > right) {
                cout << "-1\n";
            } else {
                cout << right - left << "\n";
            }
        }
        if (m % 4000 == 0) {
            recalc();
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}