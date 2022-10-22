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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, col[3][MAXN], c[3], t_ans, ans = INF;
vector<ll> adj[MAXN];
vector<pll> t_ans_v, ans_v;

void DFS(ll v, ll cnum, ll par = -1) {
    t_ans += col[c[cnum]][v];
    t_ans_v.push_back({v, c[cnum] + 1});
    for (ll u : adj[v]) if (u != par) DFS(u, (cnum + 1) % 3, v);
}

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < 3; i++) for (int j = 1; j <= n; j++) cin >> col[i][j];
    for (int i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    queue<ll> q;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() > 2) return cout << -1 << endl, 0;
        if (adj[i].size() == 1) q.push(i);
    }

    while (!q.empty()) {
        ll root = q.front();
        q.pop();
        for (int c1 = 0; c1 < 3; c1++) {
            for (int c2 = 0; c2 < 3; c2++) {
                if (c1 == c2) continue;
                ll c3 = 3 - c1 - c2;
                c[0] = c1; c[1] = c2; c[2] = c3;
                t_ans = 0;
                t_ans_v.clear();
                DFS(root, 0);
                if (t_ans < ans) {
                    ans = t_ans;
                    ans_v = t_ans_v;
                }
            }
        }
    }

    cout << ans << endl;
    sort(all(ans_v));
    for (pll e : ans_v) cout << e.Y << sep;
    cout << endl;
    return 0;
}