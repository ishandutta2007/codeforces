#include <bits/stdc++.h>

using namespace std;

#define pb push_back

using VI = vector<int>;
const int NN = 100011;

VI adj[NN];
int c[NN];
queue<int> q;
VI vec, tmp;
int n, m;
int vst[NN];

int solve() {
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u,v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = -1;
    for(int i=1; i<=n; i++) vec.pb(i);

    for(int i=1; i<=n; i++) {
        if(q.empty()) {
            ans++;

            int u = vec.back();
            vec.pop_back();
            q.push(u);
            i--;
            continue;
        }
        int u = q.front();
        q.pop();
        tmp.clear();
        vst[u] = 1;
        for(int v : adj[u]) {
            c[v]++;
            if(vst[v] == 0 and c[v] == i) tmp.pb(v);
        }
        for(int v : vec) {
            if(vst[v] == 0 and c[v] != i) q.push(v);
        }
        swap(tmp, vec);
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("b.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif // ONLINE_JUDGE
    solve();
}