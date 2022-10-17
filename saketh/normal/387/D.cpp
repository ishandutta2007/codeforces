#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct bipartite_graph {
    int A, B;
    vector<vector<int>> adj;

    bipartite_graph(int _A, int _B) {
        A = _A, B = _B;
        adj.resize(A + B); 
    }

    void edge(int i, int j) {
        adj[i].push_back(A + j);
        adj[A+j].push_back(i);
    }

    vector<int> visit, match;

    bool augment(int loc, int run) {
        if(visit[loc] == run) return false;
        visit[loc] = run;

        for (int nbr : adj[loc]) {
            if (match[nbr] == -1 || augment(match[nbr], run)) {
                match[loc] = nbr, match[nbr] = loc;
                return true;
            }
        }

        return false;
    }

    int matching() {
        visit = vector<int>(A+B, -1);
        match = vector<int>(A+B, -1); 

        int ans = 0;
        for (int i = 0; i < A; i++) 
            ans += augment(i, i);
        return ans;
    }
};

const int MAXN = 512;

int N, M;
vector<pair<int, int>> edges;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u-1, v-1);
    }

    int ans = 1e9;

    for (int root = 0; root < N; root++) {
        int got = 0;
        int oth = 0;

        bipartite_graph g(N, N);

        for (auto p : edges) {
            if(p.first == root || p.second == root) got++;
            else {
                g.edge(p.first, p.second);
                oth++;
            }
        }

        int use = g.matching();

        int cand = 2 * (N - 1) + 1 - got;
        cand += oth - use;
        cand += N - 1 - use;

        ans = min(ans, cand);
    }

    cout << ans << endl;
}