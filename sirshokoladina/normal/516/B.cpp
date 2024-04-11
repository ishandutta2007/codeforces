#include <bits/stdc++.h>
using namespace std;

#ifdef SG
    #include <debug.h>
#else
    #define show(...)
    #define debug(...)
    #define deepen(...)
    #define timer(...)
#endif

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 2000;

struct Input {
    int n, m;
    char c[N][N];
    
    bool read () {
        if (!(cin >> n >> m)) {
            return 0;
        }
        string s;
        getline(cin, s);
        forn (i, n) {
            getline(cin, s);
            forn (j, m) {
                c[i][j] = s[j];
            }
        }
        return 1;
    }

    void init (const Input &input) {
        *this = input;
    }
};

struct Data: Input {
    bool res;
    
    void write () {
        if (!res) {
            puts("Not unique");
            return;
        }
        forn (i, n) {
            forn (j, m) {
                printf("%c", c[i][j]);
            }
            puts("");
        }
    }
    
    virtual void solve () {}
    
    virtual void clear () {
        *this = Data();
    }
};

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
const char dc[4] = {'v', '>', '^', '<'};

struct Solution: Data {
    int d[N][N];
    bool u[N][N];
    ve<pii> q;
    
    void del (int i, int j) {
        u[i][j] = 1;
        forn (k, 4) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || x >= n || y < 0 || y >= m || c[x][y] != '.') {
                continue;
            }
            --d[x][y];
            if (d[x][y] < 2) {
                q.pb(mp(x, y));
            }
        }
    }
    
    void solve () {
        memset(d, 0, sizeof d);
        memset(u, 0, sizeof u);
        forn (i, n) {
            forn (j, m) {
                forn (k, 4) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= m || c[x][y] != '.') {
                        continue;
                    }
                    ++d[i][j];
                }
                if (c[i][j] == '.' && d[i][j] < 2) {
                    q.pb(mp(i, j));
                }
            }
        }
        res = 1;
        forn (t, sz(q)) {
            int i = q[t].fs, j = q[t].sc;
            if (u[i][j]) {
                continue;
            }
            if (d[i][j] < 1) {
                res = 0;
                return;
            }
            int x, y;
            forn (k, 4) {
                x = i + dx[k];
                y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= m || c[x][y] != '.') {
                    continue;
                }
                c[i][j] = dc[k];
                c[x][y] = dc[(k + 2) % 4];
                break;
            }
            del(i, j);
            del(x, y);
        }
        forn (i, n) {
            forn (j, m) {
                if (c[i][j] == '.') {
                    res = 0;
                    return;
                }
            }
        }
    }
    
    void clear () {
        *this = Solution();
    }
};

Solution sol;

int main () {
    cout.setf(ios::showpoint | ios::fixed);
    cout.precision(20);
#ifdef SG
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    while (sol.read()) {
        sol.solve();
        sol.write();
        puts("");
        sol.clear();
    }
#else
    sol.read();
    sol.solve();
    sol.write();
#endif
    return 0;
}