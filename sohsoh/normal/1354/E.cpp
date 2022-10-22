/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Expert" :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5000 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, n1, n2, n3;
ll color[MAXN] = {0}, dp[MAXN][MAXN];
vector<ll> adj[MAXN];
vector<vector<ll>> parts;
vector<ll> tmp;

ll rev_col(ll c) {
    if (c == 1) return 2;
    return 1;
}

pll possible(vector<ll> part) {
    ll x = 0;
    for (ll v : part) {
        if (color[v] == 2) x++;
    }

    return {x, SZ(part) - x};
}

ll rev_part(vector<ll> part) {
    for (ll v : part) {
        color[v] = rev_col(color[v]);
    }
}

ll DFS(ll v) {
    tmp.push_back(v);
    for (ll u : adj[v]) {
        if (color[u] == 0) {
            color[u] = rev_col(color[v]);
            DFS(u);
        } else if (color[u] == color[v]) {
            cout << "NO" << endl;
            exit(0);
        }
    }
}

int main() {
    fast_io;
    cin >> n >> m >> n1 >> n2 >> n3;

    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (ll i = 1; i <= n; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            tmp.clear();
            DFS(i);
            parts.push_back(tmp);
        }
    }

    for (int i = 0; i <= n; i++) fill(dp[i], dp[i] + MAXN, -1);
    dp[0][0] = 0;

    ll i = 0;
    for (vector<ll> p : parts) {
        ll x = possible(p).X;
        ll y = possible(p).Y;
        for (int j = 0; j < MAXN; j++) {
            if (dp[i][j] == -1) continue;
            dp[i + 1][j + y] = 1;
            dp[i + 1][j + x] = 0;
        }
        i++;
    }

    if (dp[parts.size()][n2] == -1) return cout << "NO" << endl, 0;
    cout << "YES" << endl;

    reverse(all(parts));
    i = parts.size();
    for (vector<ll> p : parts) {
        if (dp[i][n2] == 1) {
            n2 -= possible(p).Y;
            rev_part(p);
        } else {
            n2 -= possible(p).X;
        }

        i--;
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] == 1) {
            if (n1 > 0) {
                n1--;
                cout << 1;
            } else cout << 3;
        } else cout << 2;
    }

    cout << endl;
    return 0;
}