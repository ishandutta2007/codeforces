#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
vector<int> adj[MAXN];
int done[MAXN], val[MAXN], par[MAXN], g = MAXN, last;

void dfs(int s, int m, int p) {
    par[s] = p;
    int mi = min(s, m);
    val[s] = mi;
    for(auto v : adj[s])
        if(v != p)
            dfs(v, mi, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int t, z;
    cin >> t >> z;
    z = (z + last) % n + 1;
    dfs(z, z, 0);
    g = z;
    done[z] = 1;
    for(int i = 0; i < q - 1; i++) {
        cin >> t >> z;
        z = (z + last) % n + 1;
        if(t == 2) {
            last = min(g, val[z]);
            cout << last << '\n';
        }
        else {
            while(!done[z]) {
                done[z] = 1;
                g = min(g, z);
                z = par[z];
            }
        }
    }
}