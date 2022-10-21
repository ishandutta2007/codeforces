#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)5e5 + 50;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, m;
ll c[N];
vi G[N];
ll x[N], val[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        ll res = 0;
        for(int i = 0; i < n; i++) G[i].clear();
        for(int i = 0; i < n; i++) cin >> c[i];
        for(int i = 0; i < m; i++) {
            int u, v; cin >> u >> v; u--, v--;
            G[u].push_back(v);
        }
        for(int it = 0; it < 5; it++) {
            map<ll, ll> sum;
            for(int i = 0; i < n; i++) x[i] = rng(), val[i] = 0;
            for(int i = 0; i < n; i++) {
                for(int v : G[i]) val[v] ^= x[i];
            }
            for(int i = 0; i < n; i++) sum[val[i]] += c[i];
            for(auto &p : sum) {
                if(p.first == 0) continue;
                res = __gcd(res, p.second);
            }
        }
        cout << res << '\n';
    }


}