#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int cnt[MAXN], a[MAXN], ans[MAXN];
vector<int> adj[MAXN], divs;

void dfs1(int s, int p = 0, int h = 1) {
    for(auto d : divs)
        if(a[s] % d == 0)
            cnt[d]++;
    for(auto d : divs) {
        if(cnt[d] >= h - 1) {
            ans[s] = d;
            break;
        }
    }
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs1(v, s, h + 1);
    }
    for(auto d : divs)
        if(a[s] % d == 0)
            cnt[d]--;
}

void dfs2(int s, int p = 0, int g = 0) {
    if(s != 1) {
        g = __gcd(g, a[s]);
        ans[s] = max(ans[s], g);
    }
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs2(v, s, g);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int d = 1; d * d <= a[1]; d++) {
        if(a[1] % d)
            continue;
        divs.push_back(d);
        if(a[1] / d > d)
            divs.push_back(a[1] / d);
    }
    sort(divs.rbegin(), divs.rend());
    dfs1(1);
    dfs2(1);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << '\n';
}