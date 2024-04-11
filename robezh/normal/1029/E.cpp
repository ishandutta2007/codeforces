#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50, INF = (int)1e9;

int n;
vector<int> G[N];
int res = 0;

int dfs(int v, int p, int d) {
    int t = 0;
    int cnt[3] = {0, 0, 0};
    for(int nxt : G[v]) {
        if(nxt != p) {
            t++;
            cnt[dfs(nxt, v, d + 1)]++;
        }
    }
    if(cnt[0] > 0 && d >= 2) {
        res ++; return 1;
    }
    if(cnt[1] > 0) return 2;
    return 0;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(0, -1, 0);
    cout << res << endl;
}