#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)3e5 + 50, INF = (int)1e9;

int n;
int f[N];
vector<int> G[N];
int leafs = 0;

int dfs(int v) {
    if(G[v].empty()) {
        leafs++;
        return 1;
    }
    int res = f[v] ? INF : 0;
    for(int nxt : G[v]) {
        int cur = dfs(nxt);
        if(f[v]) res = min(res, cur);
        else res += cur;
    }
    return res;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> f[i];
    for(int i = 1; i < n; i++) {
        int a; cin >> a; a--;
        G[a].push_back(i);
    }
    int res = dfs(0);
    cout << leafs - res + 1 << endl;
}