#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

tuple<int, vi, vi, vi> strongly_connected_components(const int N, const int D, const vvi& graph, const vs& open) {
    int C = 0, V = 0, top = 0;
    vi comp(N * D, -1), inx(N * D, -1), stack(N * D + 1, -1);

    vi incl(N, -1), score, seq;

    auto tarjan = [&](auto&& self, int loc) -> int {
        stack[top++] = loc;
        int low = inx[loc] = V++;
        for (int _nbr : graph[loc / D]) {
            int nbr = _nbr * D + ((loc % D == D - 1) ? 0 : (loc % D + 1));
            if (inx[nbr] == -1) low = min(low, self(self, nbr));
            else if (comp[nbr] == -1) low = min(low, inx[nbr]);
        }
        if (low == inx[loc]) {
            score.push_back(0);
            while (stack[top] != loc) {
                const int add = stack[--top];
                comp[add] = C;
                if (open[add / D][add % D] == '1' && incl[add / D] != C) {
                    score.back()++;
                    incl[add / D] = C;
                }
                seq.push_back(add);
            }
            C++;
        }
        return low;
    };

    for (int i = 0; i < N * D; i++) {
        if (inx[i] == -1)
            tarjan(tarjan, i);
    }
    return { C, comp, score, seq };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, D;
    cin >> N >> M >> D;

    vvi adj(N);
    for (int e = 0; e < M; e++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
    }

    vs open(N);
    for (int i = 0; i < N; i++) {
        cin >> open[i];
    }

    int SCC;
    vi scc, score, seq;
    tie(SCC, scc, score, seq) = strongly_connected_components(N, D, adj, open);

    vi dp = score;
    for (int loc : seq) {
        for (int _nbr : adj[loc / D]) {
            int nbr = _nbr * D + ((loc % D == D - 1) ? 0 : (loc % D + 1));
            if (scc[nbr] != scc[loc])
                dp[scc[loc]] = max(dp[scc[loc]], score[scc[loc]] + dp[scc[nbr]]);
        }
    }
    cout << dp[scc[0]] << endl;

    return 0;
}