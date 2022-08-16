#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 200005;
int n, m;
int p[SZ];

int find(int u) {
    return u == p[u] ? u : (p[u] = find(p[u]));
}

void merge(int u, int v) {
    int pu = find(u);
    int pv = find(v);
    p[pu] = p[pv] = max(pu, pv);
}

int main() {
    setIO();
    cin>>n>>m;
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin>>u>>v;
        merge(u-1, v-1);
    }

    int ans = 0;
    int u = 0;
    while (u < n) {
        int mx = find(u);
        for (int i = u; i <= mx; i++)
            mx = max(mx, find(i));
        set<int> sets;
        for (int i = u; i <= mx; i++)
            sets.insert(find(i));
        ans += sets.size() - 1;
        u = mx + 1;
    }

    cout<<ans<<endl;
    
    return 0;
}