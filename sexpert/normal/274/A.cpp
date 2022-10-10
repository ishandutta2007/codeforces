#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 10;
map<ll, int> pos;
int rep[MAX], sz[MAX], cc;

int find(int u) {
    return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    cc--;
    rep[v] = u;
    sz[u] += sz[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    memset(rep, -1, sizeof rep);
    fill(sz, sz + MAX, 1);
    for(int i = 0; i < n; i++) {
        ll x = v[i];
        x *= k;
        if(pos.count(x))
            join(i, pos[x]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int u = find(i);
        ans += (sz[u] + 1)/2;
        sz[u] = 0;
    }
    cout << ans << '\n';
}