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
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') {}
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

const int N = 3000;

int dist[N][N];

vector <int> g[N];

int n;

void calc(int v) {
    int * d = dist[v];
    memset(d, 0x3f, n * sizeof(int));

    d[v] = 0;

    queue <int> q;

    q.push(v);

    while (!q.empty()) {
        int z = q.front(); q.pop();

        for (int to : g[z]) {
            if (d[to] > n) {
                d[to] = d[z] + 1;
                q.push(to);
            }
        }
    }
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

    for (int i = 0; i < m; ++i) {
        int u = nxt() - 1;
        int v = nxt() - 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int s1 = nxt() - 1, t1 = nxt() - 1, l1 = nxt();
    int s2 = nxt() - 1, t2 = nxt() - 1, l2 = nxt();

    for (int i = 0; i < n; ++i) {
        calc(i);
    }

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            cout << dist[i][j] << " ";
//        }
//        cout << "\n";
//    }

    if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
        cout << "-1\n";
        return 0;
    }

    int ans = max(0, m - dist[s1][t1] - dist[s2][t2]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cnt;
            if (dist[i][s1] + dist[i][j] + dist[j][t1] <= l1 && dist[i][s2] + dist[i][j] + dist[j][t2] <= l2) {
                cnt = dist[i][s1] + dist[i][s2] + dist[i][j] + dist[j][t1] + dist[j][t2];
                //cerr << i << " " << j << " " << cnt << "\n";
                ans = max(ans, m - cnt);
            }
            if (dist[i][s1] + dist[i][j] + dist[j][t1] <= l1 && dist[j][s2] + dist[i][j] + dist[i][t2] <= l2) {
                cnt = dist[i][s1] + dist[j][s2] + dist[i][j] + dist[j][t1] + dist[i][t2];
                ans = max(ans, m - cnt);
            }
        }
    }

    cout << ans << "\n";


    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}