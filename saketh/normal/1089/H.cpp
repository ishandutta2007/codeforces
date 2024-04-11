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

tuple<int, vi> strongly_connected_components(const vvi& graph) {
    const int N = graph.size();
    int C = 0, V = 0, top = 0;
    vi comp(N, -1), inx(N, -1), stack(N + 1, -1);

    function<int(int)> tarjan = [&](int loc) {
        stack[top++] = loc;
        int low = inx[loc] = V++;
        for (int nbr : graph[loc]) {
            if (inx[nbr] == -1) low = min(low, tarjan(nbr));
            else if (comp[nbr] == -1) low = min(low, inx[nbr]);
        }
        if (low == inx[loc]) {
            while (stack[top] != loc)
                comp[stack[--top]] = C;
            C++;
        }
        return low;
    };

    for (int i = 0; i < graph.size(); i++) {
        if (inx[i] == -1)
            tarjan(i);
    }
    return { C, comp };
}

bool solve() {
    int N, M;
    string quant;
    cin >> N >> M >> quant;

    vvi graph(2 * N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        int x1 = (2 * (abs(u) - 1)) ^ (u < 0);
        int x2 = (2 * (abs(v) - 1)) ^ (v < 0);
        graph[x1^1].push_back(x2);
        graph[x2^1].push_back(x1);
    }

    int C;
    vi comp;
    tie(C, comp) = strongly_connected_components(graph);

    for (int i = 0; i < N; i++) {
        if (comp[2 * i] == comp[2 * i + 1])
            return false;
    }

    vvi elts(C);
    for (int i = 0; i < 2 * N; i++) {
        elts[comp[i]].push_back(i);
    }

    vb has_univ(C);
    for (int c = 0; c < C; c++) {
        bool exist = false;
        for (int i : elts[c]) {
            if (quant[i/2] == 'E') exist = true;
            else {
                if (has_univ[c] || exist) return false;
                has_univ[c] = true;
            }
        }
    }

    vvi reach(C);
    vi added(C, -1);
    vi in_deg(C);
    for (int c = 0; c < C; c++) {
        for (int i : elts[c]) {
            for (int j : graph[i]) {
                if (comp[j] != c && added[comp[j]] < c) {
                    added[comp[j]] = c;
                    reach[c].push_back(comp[j]);
                    in_deg[comp[j]]++;
                }
            }
        }
    }

    vi topo;
    for (int c = 0; c < C; c++) {
        if (!in_deg[c])
            topo.push_back(c);
    }
    for (int i = 0; i < topo.size(); i++) {
        for (int j : reach[topo[i]]) {
            if (--in_deg[j] == 0)
                topo.push_back(j);
        }
    }

    for (int _i = topo.size() - 1; _i >= 0; _i--) {
        int i = topo[_i];
        bool has_succ = false;
        for (int j : reach[i]) {
            if (has_univ[j])
                has_succ = true;
        }
        if (has_succ) {
            if (has_univ[i]) return false;
            has_univ[i] = true;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cout << (solve() ? "TRUE" : "FALSE") << "\n";
    }

    return 0;
}