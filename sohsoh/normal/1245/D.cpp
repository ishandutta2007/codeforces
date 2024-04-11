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

const ll MAXN = 2000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll G[MAXN][MAXN], C[MAXN], K[MAXN], par[MAXN], key[MAXN], n;
pll pos[MAXN];
vector<ll> ans;
bool mst[MAXN] = {false};

ll best() {
    ll mn = INF, mn_ind = 0;
    for (int i = 0; i <= n; i++) if (!mst[i] && key[i] < mn) mn = key[i], mn_ind = i;
    return mn_ind;
}

void prim() {
    fill(key, key + MAXN, INF);
    key[0] = 0;
    par[0] = -1;

    for (int c = 0; c < n; c++) { //debug it
        ll u = best();
        mst[u] = true;
        for (int v = 0; v <= n; v++) if (G[u][v] != INF && !mst[v] && G[u][v] < key[v]) par[v] = u, key[v] = G[u][v];
    }
}

int main() {
    fast_io;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> pos[i].X >> pos[i].Y;
    for (int i = 1; i <= n; i++) cin >> C[i];
    for (int i = 1; i <= n; i++) cin >> K[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            G[i][j] = INF;
            if (i == j) continue;
            G[i][j] = abs(pos[i].X - pos[j].X) + abs(pos[i].Y - pos[j].Y);
            G[i][j] *= K[i] + K[j];
        }

        G[0][i] = C[i];
        G[i][0] = C[i];
    }

    prim();
    ll sum = 0;
    for (int i = 1; i <= n; i++) sum += G[i][par[i]];
    cout << sum << endl;
    for (int i = 1; i <= n; i++) if (par[i] == 0) ans.push_back(i);
    cout << ans.size() << endl;
    for (ll e : ans) cout << e << sep;
    cout << endl;
    ans.clear();
    for (int i = 1; i <= n; i++) if (par[i] != 0) ans.push_back(i);
    cout << ans.size() << endl;
    for (ll e : ans) cout << e << sep << par[e] << endl;
    return 0;
}