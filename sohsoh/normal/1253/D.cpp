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

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m, dsu_col = 0, col[MAXN] = {0}, mx_dsu[MAXN] = {0};
vector<ll> parts[MAXN], adj[MAXN];

void DFS(ll v) {
    col[v] = dsu_col;
    parts[dsu_col].push_back(v);
    mx_dsu[dsu_col] = max(mx_dsu[dsu_col], v);
    for (ll u : adj[v]) if (col[u] == 0) DFS(u);
}

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (col[i] == 0) {
            dsu_col++;
            DFS(i);
        }
    }

    ll tar = 0, dsu = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i > tar) {
            dsu = col[i];
            tar = mx_dsu[dsu];
        } else {
            if (col[i] != dsu) {
                ans++;
                ll false_dsu = col[i];
                for (ll u : parts[false_dsu]) {
                    col[u] = dsu;
                    parts[dsu].push_back(u);
                    tar = max(tar, u);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}