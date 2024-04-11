#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN], primes;
int h[MAXN], val[MAXN], prime[MAXN], mh, mv;
vector<ii> edges[MAXN];

void dfs(int s, int p = -1) {
    h[s] = (p != -1 ? h[p] + 1 : 0);
    if(h[s] > mh) {
        mh = h[s];
        mv = s;
    }
    for(auto v : adj[s]) {
        if(v != p)
            dfs(v, s);
    }
}

int diam(int s) {
    mh = -1;
    dfs(s);
    mh = -1;
    dfs(mv);
    return mh;
}

int main() {
    for(int i = 2; i < MAXN; i++) {
        if(!prime[i]) {
            primes.push_back(i);
            for(int j = i; j < MAXN; j += i)
                prime[j] = i;
        }
    }
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> val[i];
        if(val[i] > 1)
            ans = 1;
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v, g;
        cin >> u >> v;
        u--, v--;
        g = __gcd(val[u], val[v]);
        while(g > 1) {
            int p = prime[g];
            while(g % p == 0)
                g /= p;
            edges[p].emplace_back(u, v);
        }
    }
    if(ans == 0) {
        cout << 0 << endl;
        return 0;
    }
    memset(h, -1, sizeof h);
    vector<int> src;
    for(auto p : primes) {
        for(auto e : edges[p]) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
            src.push_back(e.first);
            src.push_back(e.second);
        }
        for(auto s : src) {
            if(h[s] == -1)
                ans = max(ans, diam(s) + 1);
        }
        src.clear();
        for(auto e : edges[p]) {
            adj[e.first].pop_back();
            adj[e.second].pop_back();
            h[e.first] = -1;
            h[e.second] = -1;
        }
    }
    cout << ans << endl;
}