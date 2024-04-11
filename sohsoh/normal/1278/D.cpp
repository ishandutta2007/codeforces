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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<ll> adj[MAXN];
set<pll> E;
pll v[MAXN];
bool vis[MAXN] = {false};
ll n, EIND[MAXN] = {0};

void DFS(ll v) {
    vis[v] = true;
    for (ll u : adj[v]) {
        if (vis[u]) continue;
        DFS(u);
    }
}

int main() {
    fast_io;
    cin >> n;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        v[i] = {l, r};

    }

    sort(v, v + n);
    ll ind = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (v[ind].X == i) {
            auto it = E.lower_bound({v[ind].Y, 0});
            for (auto j = E.begin(); j != it; j++) {
                ll u = ind, v = j -> Y;
                adj[u].push_back(v);
                adj[v].push_back(u);
                cnt++;
            }

            if (cnt > n - 1) return cout << "NO" << endl, 0;
            E.insert({v[ind].Y, ind});
            EIND[v[ind].Y] = ind;
            ind++;
        } else {
            E.erase({i, EIND[i]});
        }
    }

    if (cnt != n - 1) return cout << "NO" << endl, 0;
    DFS(0);
    for (int i = 0; i < n; i++) if (vis[i] == false) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    return 0;
}