#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long LL;
typedef pair<int,int> pii;
 
int n, m, a[400010];
string s[400010];
set<int> st[400010];

struct ShrinkedDAG {
    int N;
    vector<vector<int> > e;
    using pii = pair<int, int>;
    set<pii> edge_set;
    ShrinkedDAG(){}
    ShrinkedDAG(int _N) : N(_N) {
        e.assign(N + 1, vector<int>());
        edge_set.clear();
    }
    void add_edge(int u, int v) {
        pii p(u, v);
        if (edge_set.find(p) != edge_set.end()) return;
        edge_set.insert(p);
        e[u].push_back(v);
    }
};

struct SCCGraph {
    int N;
    vector<vector<int> > e;
    vector<int> stk;
    vector<int> in_stack;
    vector<int> dfn, low, scc_id;
    int num_scc;
    SCCGraph(){}
    SCCGraph(int _N) : N(_N) {
        e.assign(N + 1, vector<int>());
        in_stack.assign(N + 1, 0);
        stk.assign(N + 1, 0);
        dfn.assign(N + 1, 0);
        low.assign(N + 1, 0);
        scc_id.assign(N + 1, 0);
    }

    void add_edge(int u, int v) {
        e[u].push_back(v);
    }

    void tarjan(int x, int &time_tag) {
        time_tag++;
        dfn[x] = low[x] = time_tag;
        in_stack[x] = 1;
        stk.push_back(x);
        for (auto &t : e[x]) {
            if (!dfn[t]) {
                tarjan(t, time_tag);
                low[x] = min(low[x], low[t]);
            } else {
                if (in_stack[t]) {
                    low[x] = min(low[x], dfn[t]);
                }
            }
        }
        if (low[x] == dfn[x]) {
            num_scc++;
            int now;
            do {
                now = stk.back();
                stk.pop_back();
                in_stack[now] = false;
                scc_id[now] = num_scc;
            } while(now != x);
        }
    }

    void solve() {
        int time_tag = 0;
        num_scc = 0;
        for (int i = 1; i <= N; i++) {
            if (!dfn[i]) {
                tarjan(i, time_tag);
            }
        }
    }

    ShrinkedDAG GetDAG() {
        ShrinkedDAG DAG(num_scc);
        for (int i = 1; i <= N; i++) {
            for (auto &j : e[i]) {
                if (scc_id[i] == scc_id[j]) continue;
                DAG.add_edge(scc_id[i], scc_id[j]);
            }
        }
        return DAG;
    }
};
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }   
    for (int i = 0; i < m; i++) cin >> a[i];
    vector<vector<int> >id(n, vector<int>(m, 0)); 
    int id_cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                st[j].insert(i);
                id[i][j] = ++id_cnt;
                //printf("id[%d][%d] = %d\n",i,j,id[i][j]);
            }
        }
    }
    SCCGraph G(id_cnt);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '#') continue;
            int ID = id[i][j];
            // down
            auto down_it = st[j].upper_bound(i);
            if (down_it != st[j].end()) {
                int down = (*down_it);
                G.add_edge(ID, id[down][j]);
            }
            // up
            if (i > 0 && s[i - 1][j] == '#') {
                G.add_edge(ID, id[i - 1][j]);
            }
            // left
            if (j > 0) {
                auto left_it = st[j - 1].lower_bound(i);
                if (left_it != st[j - 1].end()) {
                    int left = (*left_it);
                    G.add_edge(ID, id[left][j - 1]);
                    //e[ID].push_back(id[left][j - 1]);
                }
            }
            // right
            if (j < m - 1) {
                auto right_it = st[j + 1].lower_bound(i);
                if (right_it != st[j + 1].end()) {
                    int right = (*right_it);
                    G.add_edge(ID, id[right][j + 1]);
                    //e[ID].push_back(id[right][j + 1]);
                }
            }
        }
    }
    /*
    for (int i = 1; i <= id_cnt; i++) {
        for (auto &t : e[i]) printf("%d-->%d\n",i,t);
    }
    */
    G.solve();
    auto DAG = G.GetDAG();
    int ans = 0;
    vector<int> ind(DAG.N + 1, 0);
    for (int i = 1; i <= DAG.N; i++) {
        for (auto &t : DAG.e[i]) {
            ind[t]++;
        }
    }
    for (int i = 1; i <= DAG.N; i++) {
        if (!ind[i]) ans++;
    }
    cout << ans << endl;
}