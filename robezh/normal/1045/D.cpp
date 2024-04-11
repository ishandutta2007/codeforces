#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int n,q;
vector<int> G[N];
int par[N];
double pro[N], sum[N];
double res = 0;

void dfs(int v, int p = 0) {
    par[v] = p;
    sum[p] += pro[v];
    for(int nxt : G[v]) {
        if(nxt != p) dfs(nxt, v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> pro[i], pro[i] = 1 - pro[i];
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b; a++, b++;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    for(int i = 0; i <= n; i++) res += (1 - pro[i]) * sum[i];
    cin >> q;
    while(q--) {
        int v; double val;
        cin >> v >> val; v++; val = 1 - val;
        double delta = val - pro[v];
        res -= delta * sum[v];
        res += (1 - pro[par[v]]) * delta;
        sum[par[v]] += delta;
        pro[v] += delta;
        cout << fixed << setprecision(4) << res << "\n";
    }

}