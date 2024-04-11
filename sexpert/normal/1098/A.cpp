#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 5;
const ll INF = 1e18;
vector<int> children[MAXN];
ll s[MAXN], val[MAXN], minim[MAXN];

ll mins(int u) {
    minim[u] = INF;
    if(s[u] >= 0)
        minim[u] = s[u];
    for(auto v : children[u])
        minim[u] = min(minim[u], mins(v));
    return minim[u];
}

void dfs(int u, ll path = 0) {
    if(s[u] >= 0) {
        if(s[u] < path) {
            cout << -1 << endl;
            exit(0);
        }
        val[u] = s[u] - path;
    }
    else {
        if(minim[u] < INF)
            val[u] = minim[u] - path;
        else
            val[u] = 0;
    }
    for(auto v : children[u])
        dfs(v, path + val[u]);
}

int main() {
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        children[p].push_back(i);
    }
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    mins(1);
    dfs(1);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(val[i] < 0) {
            cout << -1 << endl;
            return 0;
        }
        ans += val[i];
    }
    cout << ans << endl;
}