#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = (int)5e5 + 50, mod = (int)1e9 + 7;
int n, m;
int f[N], has[N];
vi res;

int find(int u) {
    return f[u] == u ? f[u] : f[u] = find(f[u]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 0, m) f[i] = i;
    rep(i, 0, n) {
        int k; cin >> k;
        if(k == 1) {
            int x; cin >> x; x--;
            if(!has[find(x)]) {
                res.push_back(i);
                has[find(x)] = 1;
            }
        } else {
            int a, b; cin >> a >> b; a--, b--;
            if(find(a) == find(b) || (has[find(a)] && has[find(b)])) continue;
            has[find(b)] |= has[find(a)];
            f[find(a)] = find(b);
            res.push_back(i);
        }
    }
    ll szT = 1;
    rep(i, 0, sz(res)) szT = (szT * 2) % mod;
    cout << szT << " " << sz(res) << '\n';
    for(int x : res) cout << x + 1 << " ";
    cout << '\n';


}