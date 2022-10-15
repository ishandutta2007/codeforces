// 
//     
// 

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
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
template<typename T> 
void _dbg(const char* _s, T _h) {
    cerr << _s << " = " << _h <<"\n"; 
}
template<typename T, typename... Ts>
void _dbg(const char* _s, T _h, Ts... _t) {
    int _b = 0;
    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++; 
    cerr << " = " << _h << ","; 
    _dbg(_s+1, _t...);
}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(5);
        #ifdef LOCAL
        srand(300); 
        #else
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
        #endif
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;

const int MAXN = 1017, D = 4, INF = 1e9;
char f[MAXN][MAXN];
int d[MAXN][MAXN][D];
bool used[MAXN][MAXN];
const int dx[] = {0, +1, 0, -1};
const int dy[] = {+1, 0, -1, 0};

pii q[MAXN * MAXN];

int main() {
    
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i <= n + 1; ++i)
        for (int j = 0; j <= m + 1; ++j) {
            f[i][j] = '#';
            for (int yo = 0; yo < 4; ++yo)
                d[i][j][yo] = INF;
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> f[i][j];
    int x1, y1, x2, y2, l = 0, r = 0;
    cin >> x1 >> y1 >> x2 >> y2;

    d[x1][y1][0] = d[x1][y1][1] = d[x1][y1][2] = d[x1][y1][3] = 0;
    used[x1][y1] = 1;
    q[r++] = {x1, y1};
    while (l < r) {
        pii v = q[l++];
        int x = v.ff, y = v.ss, dd = min({d[x][y][0], d[x][y][1], d[x][y][2], d[x][y][3]});
        for (int i = 0; i < D; ++i) {
            for (int j = 1; j <= k; ++j) {
                int tox = x + dx[i] * j, toy = y + dy[i] * j;
                if (f[tox][toy] == '#') break;
                if (d[tox][toy][i] > dd + 1) {
                    d[tox][toy][i] = dd + 1;
                    if (!used[tox][toy]) {
                        used[tox][toy] = 1;
                        q[r++] = {tox, toy};
                    }
                } else break;
            }
        }
    }
    int ans = min({d[x2][y2][0], 
                   d[x2][y2][1], 
                   d[x2][y2][2], 
                   d[x2][y2][3]});
    if (ans == INF)
        ans = -1;
    cout << ans << '\n';
    
    

    return 0;
}