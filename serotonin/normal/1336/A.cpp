#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

vector <int> g[sz], ans;

int dfs(int u = 1, int p = 0, int lvl = 0)
{
    int now = 0;
    for(int v : g[u]) if(v ^ p) {
        now += dfs(v, u, lvl + 1);
    }
    ans.push_back(lvl - now);
    return now + 1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i=1; i<n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs();

    sort(ans.begin(), ans.end(), greater<int>());

    ll res = 0;
    for(int i=0; i<k; i++) res += ans[i];

    cout << res;
}