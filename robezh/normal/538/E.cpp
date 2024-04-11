#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50, INF = (int)1e9;

int n;
vector<int> G[N];
bool lf[N];
int l_cnt = 0;

int dfs(int v, int p, int turn, int man) {
    if(lf[v]) return 1;
    int res = (turn ^ man) ? INF : 0;
    for(int nxt : G[v]) {
        if(nxt == p) continue;
        if((turn ^ man)) res = min(res, dfs(nxt, v, !turn, man));
        else res += dfs(nxt, v, !turn, man);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 1; i < n; i++) if(G[i].size() == 1) {
        lf[i] = true;
        l_cnt ++;
    }
    if(n == 1) lf[0] = true, l_cnt++;
    int a = dfs(0, -1, 0, 1);
    int b = dfs(0, -1, 0, 0);
    cout << l_cnt - a + 1 << " " << b << endl;




}