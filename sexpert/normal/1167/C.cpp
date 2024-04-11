#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAXN = 5e5 + 5;
int rep[MAXN], sz[MAXN];
 
void init() {
    fill(rep, rep + MAXN, -1);
    fill(sz, sz + MAXN, 1);
}
 
int find(int u) {
    return rep[u] == -1 ? u : rep[u] = find(rep[u]);
}
 
void join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v])
        swap(u, v);
    rep[v] = u;
    sz[u] += sz[v];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        if(k == 0) continue;
        int x;
        cin >> x;
        for(int j = 0; j < k - 1; j++) {
            int y;
            cin >> y;
            join(x, y);
        }
    }
    for(int i = 1; i <= n; i++)
        cout << sz[find(i)] << " ";
    cout << endl;
}