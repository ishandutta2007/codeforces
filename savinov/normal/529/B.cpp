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

inline string next() {
    static int c;
    string res;
    while (isspace(c = getchar())) {}
    while (!isspace(c)) {
        res = res + (char)c;
        c = getchar();
    }
    return res;
}

const int MAXMEM = 2e8;

char buf[MAXMEM];
char * cur = buf;

void * operator new(size_t n) {
    char * res = cur;
    cur += n;
    assert(cur - buf <= MAXMEM);
    return res;
}

void operator delete(void * x) {
}

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

    int n = nxt();

    int w[n], h[n];

    int minH = 0;

    for (int i = 0; i < n; ++i) {
        w[i] = nxt();
        h[i] = nxt();
    }

    int ans = 1e9;

    for (int H = 1; H <= 1000; ++H) {
        vector <int> free;
        vector <int> shouldLie;
        vector <int> shouldStand;
        char ok = true;
        for (int i = 0; i < n; ++i) {
            if (w[i] > H) {
                if (h[i] > H) {
                    ok = false;
                    break;
                }
                shouldStand.push_back(i);
            } else if (h[i] > H) {
                if (w[i] > H) {
                    ok = false;
                    break;
                }
                shouldLie.push_back(i);
            } else {
                free.push_back(i);
            }
        }
        if (!ok || shouldLie.size() > n / 2) {
            continue;
        }
        int width = 0;
        for (int x : shouldLie) {
            width += h[x];
        }
        for (int x : shouldStand) {
            width += w[x];
        }
        sort(all(free), [&](int u, int v) {
            return w[u] - h[u] > w[v] - h[v];
        });
        int cnt = min(n / 2 - shouldLie.size(), free.size());
        for (int i = 0; i < cnt; ++i) {
            int x = free[i];
            width += min(w[x], h[x]);
        }
        for (int i = cnt; i < (int)free.size(); ++i) {
            int x = free[i];
            width += w[x];
        }
        ans = min(ans, H * width);
    }

    cout << ans << "\n";

#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}