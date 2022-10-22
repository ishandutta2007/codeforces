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

const ll MAXN = 5e5 + 10;
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<vector<ll>> dsu;
vector<ll> tmp;
bool vis[MAXN] = {false};
ll a[MAXN], n, ans[MAXN];

void DFS(ll v) {
    vis[v] = true;
    tmp.push_back(v);
    if (vis[a[v]]) return;
    DFS(a[v]);
}

ll solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (vis[i] == false) {
            tmp.clear();
            DFS(i);
            dsu.push_back(tmp);
        }
    }

    for (vector<ll> v : dsu) {
        for (ll x : v) {
            ans[x] = SZ(v);
        }
    }

    dsu.clear();
    fill(vis, vis + n + 10, false);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << sep;
    }

    cout << endl;
}

int main() {
    fast_io;
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}