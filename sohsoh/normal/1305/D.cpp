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
#define SZ(x)                       ll(x.size())
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

ll n;
vector<int> adj[MAXN];
queue<int> proc;
set<int> ex;
bool avail[MAXN] = {0};

pair<int, int> find_leave() {
    int k = -1;
    int l = -1;
    for (int i = 1; i <= n; i++) {
        if (SZ(adj[i]) == 1) {
            if (k == -1) {
                k = i;
            } else {
                l = i;
                break;
            }
        }
    }

    return make_pair(k, l);
}

void rmv(int i) {
    for (int u : adj[i]) {
        adj[u].erase(find(adj[u].begin(), adj[u].end(), i));
    }
    avail[i] = false;
    adj[i].clear();
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(avail + 1, avail + n + 1, true);

    while (true) {
        pair<int, int> l = find_leave();
        if (l.X == -1 || l.Y == -1) {
            break;
        }
        cout << "? " << l.X << " " << l.Y << endl;
        cout.flush();

        ll res;
        cin >> res;
        if (res == l.X || res == l.Y) {
            return cout << "! " << res << endl, 0;
        }

        rmv(l.X);
        rmv(l.Y);
    }

    for (int i = 1; i <= n; i++) if (avail[i]) return cout << "! " << i << endl, 0;
    return 0;
}