#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2005;
const ll MOD = 998244353;
int vis[MAXN], val[MAXN];
bool valid;
vector<ii> adj[MAXN];

void dfs(int s) {
    vis[s] = 1;
    //cout << s << " " << val[s] << '\n';
    for(auto e : adj[s]) {
        int v = e.first;
        int w = e.second;
        if(val[v] == -1) {
            //if(val[s] != -1)
            //    cout << s << " " << v << " " << val[s] << " " << w << " " << (val[s] ^ w) << '\n';
            val[v] = (val[s] ^ w);
            dfs(v);
        }
        else {
            if(val[v] != (val[s] ^ w)) {
                //cout << s << " " << v << " " << w << " " << (val[s] ^ w) << " " << val[v] << '\n';
                valid = false;
            }
            if(!vis[v])
                dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(s[i] != '?') {
            adj[i].push_back({n + i, s[i] - '0'});
            adj[n + i].push_back({i, s[i] - '0'});
        }
    }
    for(int i = 0; n - 1 - i > i; i++) {
        adj[i].push_back({n - 1 - i, 0});
        adj[n - 1 - i].push_back({i, 0});
    }
    ll ans = 0;
    for(int sz = 1; sz <= n - 1; sz++) {
        memset(val, -1, sizeof val);
        memset(vis, 0, sizeof vis);
        val[2*n - sz] = 1;
        for(int i = n; i < 2*n - sz; i++)
            val[i] = 0;
        //cout << "Palin edges:\n";
        for(int i = 2*n - sz; i < 2*n; i++) {
            //cout << i << " " << 4*n - sz - 1 - i << '\n';
            adj[i].push_back({4*n - sz - 1 - i, 0});
        }
        valid = true;
        //cout << "Solving size " << sz << '\n';
        for(int i = n; i <= 2*n - sz; i++) {
            if(!vis[i])
                dfs(i);
        }
        ll tmp = valid ? 1 : 0;
        for(int i = 0; i < 2*n; i++) {
            if(!vis[i]) {
                val[i] = 0;
                dfs(i);
                tmp = (tmp*2ll) % MOD;
            }
        }
        for(int i = 2*n - sz; i < 2*n; i++)
            adj[i].pop_back();
        if(valid)
            ans = (ans + tmp) % MOD;
    }
    cout << ans << endl;
}