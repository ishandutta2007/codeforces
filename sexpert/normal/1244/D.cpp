#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
ll c[3][MAXN];
vector<int> adj[MAXN], vts;
int deg[MAXN], col[MAXN];

void dfs(int s, int p = -1) {
    vts.push_back(s);
    for(auto v : adj[s])
        if(v != p)
            dfs(v, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int k = 0; k < 3; k++)
        for(int i = 0; i < n; i++)
            cin >> c[k][i];
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        deg[x]++;
        deg[y]++;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 0; i < n; i++) {
        if(deg[i] >= 3) {
            cout << "-1\n";
            return 0;
        }
    }
    for(int i = 0; i < n; i++) {
        if(deg[i] == 1) {
            dfs(i);
            break;
        }
    }
    vector<int> p = {0, 1, 2}, be;
    ll ans = LLONG_MAX;
    do {
        ll cur = 0;
        for(int i = 0; i < n; i++)
            cur += c[p[i % 3]][vts[i]];
        if(cur < ans) {
            ans = cur;
            be = p;
        }
    } while(next_permutation(p.begin(), p.end()));
    cout << ans << '\n';
    for(int i = 0; i < n; i++)
        col[vts[i]] = be[i % 3];
    for(int i = 0; i < n; i++)
        cout << col[i] + 1 << " ";
    cout << '\n';
}