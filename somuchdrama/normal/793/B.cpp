#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using std::cerr;
using std::cin;
using std::cout;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
#define sqr(x) ((x) * (x))
#ifdef LOCAL
#define dbg(as...) {\
    vector<string> _v; \
    std::stringstream _ss(#as);\
    string _cur, _loc;\
    while (getline(_ss, _cur, ',')) {\
        while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')')) {\
            getline(_ss, _loc, ',');\
            _cur += "," + _loc;\
        }\
    _v.pb(_cur);\
    }\
    err(_v.begin(), as);\
}
#else
#define dbg(as...)
#endif

template<typename T>
void err(vector<string>::iterator it, T a) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << '\n';
}
template<typename T, typename...Ts>
void err(vector<string>::iterator it, T a, Ts...as) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << ", ";
    err(++it, as...);
}

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        #ifdef LOCAL
        srand(300); 
        #else
        srand(time(0));
        #endif
    }
    ~init() {
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;


const int MAXN = 1002, D = 4;
const int dx[D] = {+1, 0, -1, 0};
const int dy[D] = {0, +1, 0, -1};
char f[MAXN][MAXN];
struct vertex{
    int x, y, d;
};
int n, m, sx, sy, tx, ty;
bool u[D][MAXN][MAXN];
bool ok(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m && f[x][y] != '*';
}
int d[MAXN][MAXN];
vertex q[MAXN * MAXN * D];
int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            d[i][j] = 3;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> f[i][j];
            if (f[i][j] == 'S') sx = i, sy = j;
            if (f[i][j] == 'T') tx = i, ty = j;
        }
    d[sx][sy] = -1;
    for (int k = -1; k <= 1; ++k) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (d[i][j] == k)
                    for (int dd = 0; dd < D; ++dd)
                        for (int a = 1; a < n + m; ++a) {
                            int tox = i + dx[dd] * a;
                            int toy = j + dy[dd] * a;
                            if (ok(tox, toy) && d[tox][toy] > d[i][j] + 1) d[tox][toy] = d[i][j] + 1;
                            else break;
                        }
    }
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= m; ++j)
    //         dbg(i, j, d[i][j]);
    dbg(d[tx][ty]);
    if (d[tx][ty] <= 2) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}