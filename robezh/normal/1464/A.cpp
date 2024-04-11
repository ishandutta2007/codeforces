#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

struct edge {
    int to, id;
};
int n, m;
int h[N][2];
int vis[N];

vector<edge> G[N];

bool is_cyc(int x, int eid) {
    vis[x] = -1;
    int res = 0;
    for(auto e : G[x]) {
        if(vis[e.to] == -1 && e.id != eid) {
            res = 1;
        } else if(vis[e.to] == 0) {
            res |= is_cyc(e.to, e.id);
        }
    }
    vis[x] = 1;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) h[i][0] = h[i][1] = -1;
        rep(i, 0, n) G[i].clear();
        fill(vis, vis + n, false);
        int res = m;
        rep(i, 0, m) {
            int a, b; cin >> a >> b; a--, b--;
            if(a != b) {
                if(h[a][0] == -1) h[a][0] = i;
                else h[a][1] = i;

                if(h[b][0] == -1) h[b][0] = i;
                else h[b][1] = i;
            } else {
                vis[i] = true;
                res--;
            }
        }
        rep(i, 0, n) {
            if(h[i][0] != -1 && h[i][1] != -1) {
                G[h[i][0]].push_back({h[i][1], i});
                G[h[i][1]].push_back({h[i][0], i});
            }
        }
        rep(i, 0, m) {
            if(vis[i] == 0) res += is_cyc(i, -1);
        }
        cout << res << '\n';
    }


}