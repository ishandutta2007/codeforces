    #include <bits/stdc++.h>
    using namespace std;
     
    bool sint[45];
    map<string, int> mp;
    typedef bitset<64> B;
    vector<B> adj(64);
    int mx;
     
    template<class F>
    void cliques(vector<B>& eds, F f, B P = ~B(), B X = {}, B R = {}) {
        if(!P.any()) {
            if(!X.any())
                f(R);
            return;
        }
        auto q = (P | X)._Find_first();
        auto cands = P & ~eds[q];
        for(int i = 0; i < eds.size(); i++) {
            if(cands[i]) {
                R[i] = 1;
                cliques(eds, f, P & eds[i], X & eds[i], R);
                R[i] = P[i] = 0; X[i] = 1;
            }
        }
    }
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int cur = 0, n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(i != j)
                    adj[i].set(j);
            }
        }
        for(int i = 0; i < n; i++) {
            int t;
            cin >> t;
            if(t == 1) {
                memset(sint, false, sizeof sint);
                continue;
            }
            else {
                string s;
                cin >> s;
                if(!mp.count(s))
                    mp[s] = cur++;
                int u = mp[s];
                if(sint[u])
                    continue;
                sint[u] = true;
                for(int v = 0; v < 45; v++) {
                    if(v != u && sint[v]) {
                        adj[u].reset(v);
                        adj[v].reset(u);
                    }
                }
            }
        }
        /*for(int i = 0; i < 64; i++) {
            for(int j = 0; j < 64; j++) {
                cout << adj[i][j];
            }
            cout << endl;
        }*/
        cliques(adj, [](B x){ mx = max(mx, (int)x.count()); });
        cout << mx << endl;
    }