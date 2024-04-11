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
#define forr(n)                     for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, m, k;
vector<int>* g;
int* s;
int* sb;

ll path[2][MAXN];

void BFS(int ind, bool rev) {
    queue<int> q;
    q.push(ind);

    path[rev][ind] = 0;

    while (!q.empty()) {
        ind = q.front();
        q.pop();

        for (int u : g[ind]) {
//            debug(u)
            if (path[rev][u] == INF)  {
                path[rev][u] = path[rev][ind] + 1;
                q.push(u);
            }
        }
    }
}

struct st {
    ll x, y;
    ll e;
    void stt(int a, int b) {
        x = a;
        y = b;
        e = x - y;
    }

    bool operator <(st b) {
        return e < b.e;
    }
};

bool kk(int a, int b) {
    return path[0][a] - path[1][a] < path[0][b] - path[1][b];
}

int main() {
    fast_io;
    cin >> n >> m >> k;
    g = new vector<int>[n];
    s = new int[k];
    sb = new int[n];

    fill(path[0], path[0] + n,INF);
    fill(path[1], path[1] + n, INF);

    forr(n) {
        sb[i] = false;
    }

    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        t--;
        s[i] = t;
        sb[t] = true;
    }

    bool b = false;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        if (sb[u] && sb[v]) b = true;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    BFS(0, false);
    BFS(n - 1, true);

    if (b) return cout << path[0][n - 1] << endl, 0;

    ll l = 0;

    sort(s, s + k, kk);
    ll ma = -INF;
    ll best = 0;
    for (int i = 0; i < k; i++) {
        int a = s[i];
        best = max(best, ma + path[1][a]);
        ma = max(ma, path[0][a]);
    }

    cout << min(best + 1, path[0][n - 1]) << endl;
    return 0;
}