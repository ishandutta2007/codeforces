#include <bits/stdc++.h>
using namespace std;

const int N = (int)8e6, INF = (int)1e9;
typedef pair<int, int> P;
typedef long long ll;

int n, m;

struct SCC {
    vector<int> G[N], rG[N], vs;
    bool used[N];
    int cmp[N];
    int n;

    void init() {
        for(int i = 0; i < n; i++) {
            G[i].clear();
            rG[i].clear();
            vs.clear();
        }
    }

    void add_edge(int from, int to){
        G[from].push_back(to);
        rG[to].push_back(from);
    }

    void dfs(int v){
        used[v] = true;
        for(int nxt : G[v]){
            if(!used[nxt]) dfs(nxt);
        }
        vs.push_back(v);
    }

    void rdfs(int v, int k){
        used[v] = true;
        cmp[v] = k;
        for(int nxt : rG[v]){
            if(!used[nxt]) rdfs(nxt, k);
        }
    }

    int scc(){
        fill(used, used + n, false);
        vs.clear();
        for(int v = 0; v < n; v++){
            if(!used[v]) dfs(v);
        }
        fill(used, used + n, false);
        int k = 0;
        reverse(vs.begin(), vs.end());
        for(int v : vs){
            if(!used[v]) rdfs(v, k++);
        }
        return k;
    }
} scc;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        scc.n = n;
        scc.init();
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b; a--, b--;
            scc.add_edge(a, b);
        }
        int k = scc.scc();
        if(k == 1) {
            cout << "No" << '\n';
        }
        else {
            vector<int> r0, r1;
            for(int i = 0; i < n; i++) {
                if(scc.cmp[i] == k - 1) r0.push_back(i);
                else r1.push_back(i);
            }
            cout << "Yes\n";
            cout << r0.size() << " " << r1.size() << '\n';
            for(int x : r0) cout << x + 1 << " ";
            cout << "\n";
            for(int x : r1) cout << x + 1 << " ";
            cout << "\n";
        }

    }

}