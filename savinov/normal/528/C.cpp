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

const int N = 500000;

int from[N], to[N];
int deg[N];
char used[N];

vector <int> g[N];

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
    int n = nxt(), m = nxt();
    for (int i = 0; i < m; ++i) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        from[i] = a, to[i] = b;
        g[from[i]].push_back(i);
        g[to[i]].push_back(i);
        deg[a]++;
        deg[b]++;
    }
    vector <int> o;
    for (int i = 0; i < n; ++i) {
        if (deg[i] % 2) {
            o.push_back(i);
        }
    }
    assert(o.size() % 2 == 0);
    for (int i = 0; i < (int)o.size(); i += 2) {
        from[m] = o[i];
        to[m] = o[i + 1];
        g[from[m]].push_back(m);
        g[to[m]].push_back(m);
        m++;
    }

    if (m % 2 == 1) {
        g[0].push_back(m);
        from[m] = to[m] = 0;
        m++;
    }

    vector <int> st;

    vector <int> ans;

    st.push_back(0);

    while (!st.empty()) {
        int v = st.back();
        while (!g[v].empty() && used[g[v].back()]) {
            g[v].pop_back();
        }
        if (g[v].empty()) {
            ans.push_back(v);
            st.pop_back();
        } else {
            int e = g[v].back();
            int t;
            if (from[e] == v) {
                t = to[e];
            } else {
                t = from[e];
            }
            st.push_back(t);
            used[e] = 1;
        }
    }

    assert(ans.size() == m + 1);
    cout << ans.size() - 1 << "\n";

    for (int i = 0; i < (int)ans.size() - 1; ++i) {
        if (i % 2) {
            cout << ans[i] + 1 << " " << ans[i + 1] + 1 << "\n";
        } else {
            cout << ans[i + 1] + 1 << " " << ans[i] + 1 << "\n";
        }
    }

#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}