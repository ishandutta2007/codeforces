#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;
int n;
set<int> G[N];
int spc[N];
int dp[N];
int par[N];
int btm = -1;

void dfs(int v) {
    dp[v] = 0;
    for(int nxt : G[v]) {
        dfs(nxt);
        dp[v] = max(dp[v], dp[nxt] + 1);
    }
}

void cut(int v) {
    spc[v] = 1;
    for(int nxt : G[v]) {
        if(dp[v] == dp[nxt] + 1) {
            cut(nxt);
            G[v].erase(nxt);
            return ;
        }
    }
    btm = v;

}

queue<int> que;
vector<int> bamb, res;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    par[0] = -1;
    for(int i = 1; i <= n - 1; i++) {
        cin >> par[i];
        G[par[i]].insert(i);
    }
    dfs(0);
    cut(0);
//    for(int i = 0; i < n; i++) {
//        cout << i << ": ";
//        for(int nxt : G[i]) cout << nxt << " ";
//        cout << endl;
//    }
    for(int i = 1; i < n; i++) {
        if(spc[i]) que.push(i);
    }
    while(!que.empty()) {
        int v = que.front(); que.pop();
        if(par[v] != -1 && !G[par[v]].empty()) {
            int p = par[v];
            int nxt = *G[par[v]].begin();
            par[v] = nxt;
            G[p].erase(nxt);
            spc[nxt] = 1;
            que.push(nxt);
            que.push(v);
            res.push_back(v);
        }
    }
    int cur = btm;
    while(cur != -1) {
        bamb.push_back(cur);
        cur = par[cur];
    }
    reverse(res.begin(), res.end());
    reverse(bamb.begin(), bamb.end());
    for(int x : bamb) cout << x << " ";
    cout << "\n";
    cout << res.size() << '\n';
    for(int x : res) cout << x << " ";
    cout << '\n';

}