#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6 + 10;
int to[MAXN], dis[MAXN], seen[MAXN], col[MAXN], poop[MAXN], nc, ans, n, m;
vector<int> wow, cys[MAXN], reach[MAXN];

void dfs(int s) {
    while(!seen[s]) {
        seen[s] = 1;
        wow.push_back(s);
        s = to[s];
    }
    poop:
    if(seen[s] == 2) {
        int d = dis[s], en = poop[s];
        while(wow.size()) {
            int u = wow.back();
            wow.pop_back();
            dis[u] = ++d;
            reach[en].push_back(u);
            poop[u] = en;
            seen[u] = 2;
        }
        return;
    }
    else {
        int u, ci, sz = 0;
        ++nc;
        do {
            u = wow.back();
            wow.pop_back();
            sz++;
        } while(u != s);
        ans += sz;
        for(int i = 0; i < sz; i++) {
            seen[u] = 2;
            poop[u] = u;
            dis[u] = 0;
            reach[u].push_back(u);
            cys[nc].push_back(u);
            u = to[u];
        }
        goto poop;
    }
}

void solve() {
    cin >> n >> m;
    ans = nc = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            seen[m*i + j] = 0;
            char c;
            cin >> c;
            col[m*i + j] = (c - '0');
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            int &x = to[m*i + j], y = m*i + j;
            if(c == 'L')
                x = y - 1;
            if(c == 'R')
                x = y + 1;
            if(c == 'U')
                x = y - m;
            if(c == 'D')
                x = y + m;
        }
    }
    nc = 0;
    for(int i = 0; i < n * m; i++) {
        if(!seen[i])
            dfs(i);
    }
    cout << ans << " ";
    
    int ans2 = 0;
    for(int kk = 1; kk <= nc; kk++) {
        int sz = cys[kk].size();
        vector<int> owo;
        for(int i = 0; i < sz; i++) {
            int u = cys[kk][i];
            for(auto v : reach[u]) {
                if(col[v] == 0)
                    owo.push_back(((dis[v] - i)%sz + sz)%sz);
            }
        }
        sort(owo.begin(), owo.end());
        owo.erase(unique(owo.begin(), owo.end()), owo.end());
        ans2 += owo.size();
        owo.clear();
    }
    
    for(int i = 0; i < n*m; i++) {
        cys[i].clear();
        reach[i].clear();
        cys[i].shrink_to_fit();
        reach[i].shrink_to_fit();
    }
    
    cout << ans2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}