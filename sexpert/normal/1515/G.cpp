#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

const int MAXN = 2e5 + 10;
vector<ii> adj[MAXN];

int tin[MAXN], low[MAXN], comp[MAXN], root[MAXN], curt, n, m, ncomps;
ll can[MAXN], dis[MAXN];
vector<int> curcomp;

void dfs(int s) {
    tin[s] = ++curt;
    low[s] = tin[s];
    curcomp.push_back(s);
    for(auto &[v, c] : adj[s]) {
        if(!tin[v]) {
            dfs(v);
            low[s] = min(low[s], low[v]);
        }
        else if(!comp[v])
            low[s] = min(low[s], tin[v]);
    }
    if(low[s] == tin[s]) {
        ncomps++;
        int x;
        root[ncomps] = s;
        do {
            x = curcomp.back(); curcomp.pop_back();
            comp[x] = ncomps;
        } while(x != s);
    }
}

void dfs2(int s, ll d = 0) {
    dis[s] = d;
    for(auto &[v, c] : adj[s]) {
        if(comp[v] != comp[s])
            continue;
        if(dis[v] == -1)
            dfs2(v, d + c);
        else if(abs(d + c - dis[v]) != 0)
            can[comp[s]] = __gcd(can[comp[s]], abs(d + c - dis[v]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        adj[a].push_back({b, l});
    }

    for(int i = 1; i <= n; i++)
        if(!comp[i])
            dfs(i);

    memset(dis, -1, sizeof dis);

    for(int i = 1; i <= n; i++)
        dfs2(root[i]);

    int q;
    cin >> q;
    while(q--) {
        int n;
        ll s, t;
        cin >> n >> s >> t;
        int cm = comp[n];
        if(can[cm] == 0) {
            if(s == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
            continue;
        }
        ll g = __gcd(can[cm], t);
        if(s % g != 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}