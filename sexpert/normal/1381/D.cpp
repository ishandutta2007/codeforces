#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
vector<int> adj[MAXN], snek;
int n, down[MAXN], up[MAXN], insnek[MAXN], orz[MAXN], uwu[MAXN], par[MAXN], head, tail, length;

void dfs(int s, int p = 0) {
    par[s] = p;
    down[s] = 0;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
        down[s] = max(down[s], down[v] + 1);
    }
}

void weary(int s, int p = 0) {
    int sz = adj[s].size();
    vector<int> pf(sz), sf(sz);
    for(int i = 0; i < sz; i++) {
        int v = adj[s][i];
        if(v == p) {
            pf[i] = (i ? pf[i - 1] : 0);
            continue;
        }
        pf[i] = max(down[v] + 1, (i ? pf[i - 1] : 0));
    }
    for(int i = sz - 1; i >= 0; i--) {
        int v = adj[s][i];
        if(v == p) {
            sf[i] = (i + 1 < sz ? sf[i + 1] : 0);
            continue;
        }
        sf[i] = max(down[v] + 1, (i + 1 < sz ? sf[i + 1] : 0));
    }
    for(int i = 0; i < sz; i++) {
        int v = adj[s][i];
        if(v == p)
            continue;
        up[v] = 0;
        up[v] = max(up[v], i ? pf[i - 1] : 0);
        up[v] = max(up[v], (i + 1 < sz ? sf[i + 1] : 0));
        up[v] = max(up[v], up[s]);
        up[v]++;
    }
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        weary(v, s);
    }
}

int depth(int s, int p) {
    uwu[s] = 1;
    int res = 1;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        res = max(res, depth(v, s) + 1);
    }
    return res;
}

void solve() {
    cin >> n >> head >> tail;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        orz[i] = 0;
        uwu[i] = 0;
        up[i] = 0;
        down[i] = 0;
        insnek[i] = 0;
    }
    length = 0;
    snek.clear();
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(head);
    weary(head);

    int cur = tail;
    while(cur != head) {
        insnek[cur] = 1;
        snek.push_back(cur);
        cur = par[cur];
    }
    insnek[head] = 1;
    snek.push_back(head);

    length = snek.size();

    for(int u = 1; u <= n; u++) {
        int cnt = 0;
        for(auto v : adj[u]) {
            if(v == par[u])
                continue;
            if(down[v] + 1 >= length - 1)
                cnt++;
        }
        if(up[u] >= length - 1)
            cnt++;
        if(cnt >= 3)
            orz[u] = 1;
    }

    /*cout << "orz vertices:" << endl;
    for(int u = 1; u <= n; u++)
        if(orz[u]) cout << u << " ";
    cout << endl;*/
    

    /*cout << "snek is:" << endl;
    for(auto v : snek)
        cout << v << " ";
    cout << endl;*/

    int tp = 0, tb = 0, hp = length - 1, hb = length - 1;

    while(tp <= tb || hp >= hb) {
        bool tl = (tp <= tb);
        int idx = tl ? tp++ : hp--;
        int s = snek[idx];
        uwu[s] = 1;
        int mdep = 0;
        for(auto v : adj[s]) {
            if(insnek[v])
                continue;
            //cout << "uwuify all of " << v << endl;
            mdep = max(mdep, depth(v, s));
        }
        mdep = min(mdep, length - 1);
        mdep++;
        int chorizo = length - mdep;
        if(tl)
            hb = min(idx + chorizo, hb);
        else
            tb = max(idx - chorizo, tb);
    }

    /*cout << "uwu vertices" << endl;
    for(int u = 1; u <= n; u++)
        if(uwu[u]) cout << u << " ";
    cout << endl;*/

    for(int u = 1; u <= n; u++) {
        if(uwu[u] && orz[u]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";

    //cout << "===========" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}