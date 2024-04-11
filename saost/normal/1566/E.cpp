#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int t, n, m, res;
vector<int> S[N];

int DFS(int u, int pa) {
    int cnt = 0;
    for(int v : S[u]) if (v != pa)
    cnt += DFS(v, u);
    if (cnt) {
        res += --cnt;
        return 0;
    }
    else return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for(int i=1; i<=n; ++i) S[i].clear();
        for(int i=1; i<n; ++i) {
            int u, v;
            cin >> u >> v;
            S[u].push_back(v);
            S[v].push_back(u);
        }
        res = 1;
        DFS(1, 0);
        cout << res << '\n';
    }
}