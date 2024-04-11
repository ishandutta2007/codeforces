#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;

int n;
set<int> G[N];
vi fib(30, 0);
map<int, int> mp;
int sub[N], has[N], par[N];

void dfs(int v, int p, int val, int val2) {
    sub[v] = 1;
    par[v] = p;
    has[v] = -1;
    for(int nxt : G[v]) {
        if(nxt != p) {
            dfs(nxt, v, val, val2);
            sub[v] += sub[nxt];
            if(has[nxt] != -1) has[v] = has[nxt];
        }
    }
    if(sub[v] == val || sub[v] == val2) has[v] = v;
}

bool solve(int v, int idx) {
    if(idx <= 1) return true;
    dfs(v, -1, fib[idx - 2], fib[idx - 1]);

    if(has[v] == -1) return false;
    int x = has[v], p = par[x];
    G[x].erase(p);
    G[p].erase(x);
    int sx = sub[x], sp = sub[v] - sub[x];
    return solve(x, mp[sx]) && solve(p, mp[sp]);
}

int main() {

    fib[0] = fib[1] = 1;
    rep(i, 2, 30) fib[i] = fib[i - 1] + fib[i - 2];
    rep(i, 0, 30) mp[fib[i]] = i;

    cin >> n;
    if(n == 1) {
        return cout << "YES\n", 0;
    }
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    cout << (mp[n] && solve(0, mp[n]) ? "YES" : "NO") << "\n";

}