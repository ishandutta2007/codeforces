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
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dist[MAXN], a[MAXN], n;
queue<ll> q;
vector<ll> adj[MAXN];

void BFS() {
    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll u : adj[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int main() {
    fast_io;
    cin >> n;
    fill(dist, dist + n + 1, -1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (i + a[i] < n) {
            adj[a[i] + i].push_back(i);
            if (a[i] % 2 != a[i + a[i]] % 2) {
                dist[i] = 1;
                q.push(i);
            }
        }

        if (i - a[i] >= 0) {
            adj[i - a[i]].push_back(i);
            if (a[i] % 2 != a[i - a[i]] % 2) {
                dist[i] = 1;
                q.push(i);
            }
        }
    }

    BFS();
    for (int i = 0; i < n; i++) cout << dist[i] << sep; cout << endl;
    return 0;
}