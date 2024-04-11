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

void myassert(bool v) {
    assert(v);
    //cout << "FAIL\n";
    //exit(0);
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

int p[1 << 20];
int sz[1 << 20];

int get(int v) {
    if (p[v] != v) {
        p[v] = get(p[v]);
    }
    return p[v];
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (sz[a] > sz[b]) {
        swap(a, b);
    }
    p[a] = b;
    sz[b] += sz[a];
}

void solve(int test) {
    int n = nxt();
    int m = nxt();
    long long T;
    cin >> T;

    int a[n * m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i * m + j] = nxt();
            p[i * m + j] = i * m + j;
            sz[i * m + j] = 1;
        }
    }

    auto cmp = [&](int x, int y) {
        return a[x] > a[y];
    };
    int o[n * m];
    iota(o, o + n * m, 0);

    sort(o, o + n * m, cmp);

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int t[n * m];
    clr(t);

    for (int v : o) {
        int x = v / m;
        int y = v % m;
        t[v] = 1;

        for (int k = 0; k < 4; ++k) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                if (t[xx * m + yy]) {
                    unite(xx * m + yy, v);
                }
            }
        }

        if (T % a[v] == 0 && sz[get(v)] >= T / a[v]) {
            cout << "YES\n";
            int need = T / a[v];
            char used[n * m];
            clr(used);
            queue <int> q;
            q.push(v);
            used[v] = 1;
            --need;
            while (!q.empty()) {
                x = q.front() / m;
                y = q.front() % m;
                q.pop();

                for (int k = 0; k < 4; ++k) {
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
                        if (t[xx * m + yy] && !used[xx * m + yy] && need) {
                            --need;
                            used[xx * m + yy] = 1;
                            q.push(xx * m + yy);
                        }
                    }
                }
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (used[i * m + j]) {
                        --need;
                        cout << a[v] << " ";
                    } else {
                        cout << "0 ";
                    }
                }
                cout << "\n";
            }
            return;
        }
    }
    cout << "NO\n";
}



int main(int argc, char ** argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    #define fname "sequence"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif
#ifdef LOCAL

    int t = 1;
#else
    int t = 1;
#endif
    int c = 0;
    while (t--) {
        solve(++c);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}