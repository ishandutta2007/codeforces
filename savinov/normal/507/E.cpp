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
#define x1 x12345
#define y1 y12345

using namespace std;

template <typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template <class _T> inline _T sqr(const _T& x) {return x * x;}
template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair < int, int > PII;
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

template <typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "war"
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    int n = nxt();
    int m = nxt();

    int f[m + m], t[m + m], w[m + m];

    vector <int> g[n];

    int s = 0;

    for (int i = 0; i < m; ++i) {
        f[i + i] = nxt() - 1;
        t[i + i] = nxt() - 1;
        w[i + i] = nxt() ^ 1;
        f[i + i + 1] = t[i + i];
        t[i + i + 1] = f[i + i];
        w[i + i + 1] = w[i + i];
        g[f[i + i]].pb(i + i);
        g[t[i + i]].pb(i + i + 1);
    }

    pair <int, int> dist[n];
    int parent[n];

    fill(dist, dist + n, mp(1e9, 1e9));

    auto cmp = [&](int u, int v) {
        return dist[u] < dist[v] || (dist[u] == dist[v] && u < v);
    };


    set <int, decltype(cmp)> q(cmp);
    dist[0] = {0, 0};
    q.insert(0);

    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());

        for (int e : g[v]) {
            int to = t[e];
            pair <int, int> nDist = {dist[v].x + 1, dist[v].y + w[e]};
            if (dist[to] > nDist) {
                q.erase(to);
                dist[to] = nDist;
                parent[to] = e;
                q.insert(to);
            }
        }
    }

    char used[m + m];
    clr(used);
    int ans = 0;

    int v = n - 1;
    while (v) {
        used[parent[v]] = 1;
        used[parent[v] ^ 1] = 1;
        v = f[parent[v]];
    }

    for (int i = 0; i < 2 * m; ++i) {
        if (w[i] == 0 && !used[i]) {
            ++ans;
        }
        if (w[i] == 1 && used[i]) {
            ++ans;
        }
    }
    cerr << ans << endl;
    cout << ans / 2 << "\n";
    for (int i = 0; i < m + m; ++i) {
        if (w[i] == 0 && !used[i] && f[i] < t[i]) {
            cout << f[i] + 1 << " " << t[i] + 1 << " " << (w[i]) << "\n";
        }
        if (w[i] == 1 && used[i] && f[i] < t[i]) {
            cout << f[i] + 1 << " " << t[i] + 1 << " " << (w[i]) << "\n";
        }
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}