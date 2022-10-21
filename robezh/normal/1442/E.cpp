#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)2e5 + 50;

int n;
int vis[N];
int c[N];
vector<int> G[N];
int deg[N];

int solve(int color) {
    queue<int> que[2];
    fill(deg, deg + n, 0);
    fill(vis, vis + n, 0);
    for(int i = 0; i < n; i++) {
        deg[i] = sz(G[i]);
        if(deg[i] == 1) {
            if(c[i] == -1 || c[i] == color) que[color].push(i);
            else que[!color].push(i);
            vis[i] = 1;
        }
    }
    int res = 0, cc = color;
    while(!que[cc].empty() || res == 0) {
        res++;
        while(!que[cc].empty()) {
            int v = que[cc].front(); que[cc].pop();
            for(int nxt : G[v]) {
                if(!vis[nxt]) {
                    deg[nxt]--;
                    if(deg[nxt] == 1) {
                        if(c[nxt] == -1 || c[nxt] == cc) que[cc].push(nxt);
                        else que[!cc].push(nxt);
                        vis[nxt] = 1;
                    }
                }
            }
        }
        cc = !cc;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        rep(i, 0, n) G[i].clear();
        cin >> n;
        rep(i, 0, n) cin >> c[i], c[i]--;
        rep(i, 0, n - 1) {
            int a, b; cin >> a >> b; a--, b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        if(n == 1) cout << 1 << endl;
        else cout << min(solve(0), solve(1)) << '\n';
    }

}