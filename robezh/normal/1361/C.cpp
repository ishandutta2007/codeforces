#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct edge {
    int to, id, u, v;
};

const int N = (int)5e5 + 50;
int n, a[N], b[N];
int vis[N];
vector<edge> G[(1 << 20) + 5 ];
vector<pii> res;

void dfs(int v, pii be){
    while(G[v].size()){
        auto e = G[v].back(); G[v].pop_back();
        if(vis[e.id]) continue;
        vis[e.id] = true;
        dfs(e.to, {e.u, e.v});
    }
    if(be != pii{-1, -1}) res.push_back(be);
}

int get(int i) {
    return i % 2 == 0 ? a[i / 2] : b[i / 2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for(int bt = 20; bt >= 0; bt--) {
        res.clear();
        fill(vis, vis + n, 0);
        int mask = (1 << bt) - 1;
        for(int i = 0; i <= mask; i++) {
            G[i].clear();
        }
        for(int i = 0; i < n; i++) {
            int va = a[i] & mask, vb = b[i] & mask;
            G[va].push_back({vb, i, 2 * i, 2 * i + 1});
            G[vb].push_back({va, i, 2 * i + 1, 2 * i});
//            cout << va << " " << vb << endl;
        }
        int st = -1;
//        cout << bt << ":\n ";
        int good = 1;
        for(int i = 0; i < (1 << bt); i++) {
            if(G[i].size() % 2 != 0) {
                good = 0;
                break;
            }
        }
        if(!good) {
            continue;;
        }
        for(int i = 0; i < (1 << bt); i++) {
            if(G[i].size()) {
                dfs(i, {-1, -1});
                break;
            }
        }
//        cout << res.size() << endl;
        int fres = 0;
        if(res.size() == n) {
            cout << bt << "\n";
            for(int i = 0; i < n; i++) {
                cout << res[i].second + 1 << " " << res[i].first + 1 << " ";
            }
            cout << '\n';
//            cout << "beauties: ";
//            for(int i = 0; i < n; i++) {
//                cout << (get(res[i].first) ^ get(res[(i + 1) % n].second)) << ' ';
//            }
//            cout << endl;
            return 0;
        }
    }

}