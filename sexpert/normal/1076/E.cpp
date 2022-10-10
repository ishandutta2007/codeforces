#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 3e5 + 5;
ll BIT[MAXN], tot[MAXN];
vector<int> adj[MAXN];
vector<pair<int, ll>> queries[MAXN];
int n, h[MAXN];

void dfs(int s, int p = 0) {
    h[s] = (p == 0 ? 1 : h[p] + 1);
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
    }
}

void add(int pos, ll val) {
    for(;pos <= n; pos += (pos & -pos))
        BIT[pos] += val;
}

ll sum(int pos) {
    ll ans = 0;
    for(;pos > 0; pos -= (pos & -pos))
        ans += BIT[pos];
    return ans;
}

ll sumright(int pos) {
    return sum(n) - sum(pos - 1);
}

void trav(int s, int p = 0) {
    for(auto p : queries[s])
        add(min(h[s] + p.first, n), p.second);
    tot[s] = sumright(h[s]);
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        trav(v, s);
    }
    for(auto p : queries[s])
        add(min(h[s] + p.first, n), -p.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int v, d;
        ll x;
        cin >> v >> d >> x;
        queries[v].push_back({d, x});
    }
    trav(1);
    for(int i = 1; i <= n; i++)
        cout << tot[i] << " ";
    cout << endl;
}