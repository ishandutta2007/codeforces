/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 50 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool a[MAXN][MAXN], vis[MAXN][MAXN];
ll n, m;
vector<pll> G;

void DFS(pll p) {
    ll i = p.X, j = p.Y;
    vis[i][j] = true;
    if (!vis[i + 1][j] && a[i + 1][j]) DFS({i + 1, j});
    if (i > 0 && !vis[i - 1][j] && a[i - 1][j]) DFS({i - 1, j});
    if (!vis[i][j + 1] && a[i][j + 1]) DFS({i, j + 1});
    if (j > 0 && !vis[i][j - 1] && a[i][j - 1]) DFS({i, j - 1});
}

ll solve() {
    cin >> n >> m;
    G.clear();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'B') {
                if (i > 0) a[i - 1][j] = false;
                if (j > 0) a[i][j - 1] = false;
                a[i][j + 1] = false;
                a[i + 1][j] = false;
                a[i][j] = false;
            } else if (c == 'G') {
                G.push_back({i, j});
            } else if (c == '#') {
                a[i][j] = false;
            }

            vis[i][j] = false;
        }
    }

    DFS({n - 1, m - 1});
    for (pll p : G) {
//        debug(p.X)
//        debug(p.Y)
        if (!vis[p.X][p.Y] || !a[p.X][p.Y] || !a[n - 1][m - 1]) return cout << "NO" << endl, 0;
    }

    cout << "YES" << endl;
    return 0;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}