#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e18 + 41;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> es(n);
    vector<pair<int, pair<int, int>>> e(m);
    for (int i = 0; i < m; i++) {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        e[i] = {c, {v1 - 1, v2 - 1}};
    }
    sort(e.begin(), e.end());
    vector<int> zip(n, -1);
    vector<int> v;
    
    vector<vector<ll>> d(2 * k, vector<ll>(2 * k, INF));
    
    for (int i = 0; i < min(m, k); i++) {
        int v1 = e[i].second.first;
        int v2 = e[i].second.second;
        int c = e[i].first;
        if (zip[v1] == -1) {
            zip[v1] = v.size();
            v.push_back(v1);
        }
        if (zip[v2] == -1) {
            zip[v2] = v.size();
            v.push_back(v2);
        }
        
        d[zip[v1]][zip[v2]] = c;
        d[zip[v2]][zip[v1]] = c;
    }
    
    for (int it = 0; it < k; it++)
    for (int i = 0; i < min(m, k); i++)
    for (int st : v) {
        int v1 = e[i].second.first;
        int v2 = e[i].second.second;
        int c = e[i].first;
        d[zip[st]][zip[v2]] = min(d[zip[st]][zip[v2]], d[zip[st]][zip[v1]] + c);
        d[zip[st]][zip[v1]] = min(d[zip[st]][zip[v1]], d[zip[st]][zip[v2]] + c);
    }
    
    vector<ll> dist;
    for (int i = 0; i < (int)v.size(); i++)
    for (int j = i + 1; j < (int)v.size(); j++)
    dist.push_back(d[i][j]);
    sort(dist.begin(), dist.end());
    cout << dist[k - 1] << "\n";
}

int main() {
    //freopen("a.in", "r", stdin);
    solve();
    return 0;   
}