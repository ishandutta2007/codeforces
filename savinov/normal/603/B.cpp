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


int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "ticket-office"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
    int p = nxt();
    int k = nxt();

    if (k == 0) {
        long long ans = 1;
        for (int i = 1; i < p; ++i) {
            ans = ans * p % 1000000007;
        }
        cout << ans << endl;
        return 0;
    }
    if (k == 1) {
        long long ans = 1;
        for (int i = 0; i < p; ++i) {
            ans = ans * p % 1000000007;
        }
        cout << ans << endl;
        return 0;
    }
    long long value[p];
    memset(value, 255, sizeof(value));
    long long ik = -1;
    for (int i = 1; i < p; ++i) {
        if (i * 1ll * k % p == 1) {
            ik = i;
            break;
        }
    }
    long long ans = 1;
    for (int i = 1; i < p; ++i) {
        if (value[i] != -1) {
            continue;
        }
        queue <int> q;
        long long mul = p;
        value[i] = 1;
        q.push(i);
        while (!q.empty()) {
            ll v = q.front();
            q.pop();

            long long to = v * k % p;
            if (value[to] == -1) {
                value[to] = value[v] * k % p;
                q.push(to);
            } else if (value[to] != value[v] * k % p) {
                mul = 1;
            }
            to = v * ik % p;
            if (value[to] == -1) {
                value[to] = value[v] * ik % p;
                q.push(to);
            } else if (value[to] != value[v] * ik % p) {
                mul = 1;
            }
        }
        ans = ans * mul % 1000000007;
    }

    cout << ans << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}