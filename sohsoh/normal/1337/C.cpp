/*
    Soheil Mohammadkhani
    IDK :)
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
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<int> adj[MAXN];
ll n, k;
ll dist[MAXN] = {0};
ll ch[MAXN] = {0};
ll ind[MAXN] = {0};

ll DFS(int v = 1, ll par = -1, ll ps = 0) {
    dist[v] = min(ps, dist[v]);
    ll sum = 0;
    for (int u : adj[v]) {
        if (u != par) {
            sum++;
            sum += DFS(u, v, ps + 1);
        }
    }

    ch[v] = sum;
    return sum;
}

bool comp(int a, int b) {
    if (dist[a] == INF || a == 0) return false;
    if (dist[b] == INF || b == 0) return true;

    return (dist[a] - ch[a]) > (dist[b] - ch[b]);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(dist, dist + n + 1, INF);
    DFS();

    for (int i = 0; i < n; i++) {
        ind[i] = i + 1;
    }

    sort(ind, ind + n + 1, comp);
    ll sum = 0;

//    alog(ind, n + 1);
//    alog(dist, n + 1);
//    alog(ch, n + 1);

    for (int i = 0; i < k; i++) {
        sum += dist[ind[i]] - ch[ind[i]];
    }

    cout << sum << endl;

    return 0;
}