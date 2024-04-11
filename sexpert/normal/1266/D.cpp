#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
 
const int MAXN = 1e5 + 5;
ll bal[MAXN];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        bal[u] -= w;
        bal[v] += w;
    }
    vector<int> gain, loss;
    for(int u = 1; u <= n; u++) {
        if(bal[u] > 0)
            gain.push_back(u);
        if(bal[u] < 0)
            loss.push_back(u);
    }
    vector<array<ll, 3>> ans;
    while(gain.size()) {
        int u = loss.back(), v = gain.back();
        loss.pop_back(); gain.pop_back();
        ll w = min(-bal[u], bal[v]);
        ans.push_back({u, v, w});
        bal[u] += w;
        bal[v] -= w;
        if(bal[u] != 0)
            loss.push_back(u);
        if(bal[v] != 0)
            gain.push_back(v);
    }
    cout << ans.size() << '\n';
    for(auto t : ans)
        cout << t[0] << " " << t[1] << " " << t[2] << '\n';
}