#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi cost(N);
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    vvi adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    ll tot_cost = 0;
    vi floater(N);
    vvi choices(N);
    vb can_use(N);

    auto comb = [](vi& a, vi& b) {
        if (a.size() < b.size()) swap(a, b);
        copy(all(b), back_inserter(a));
    };

    function<void(int, int)> solve = [&](int loc, int par) {
        vi ch;
        for (int nbr : adj[loc]) if (nbr != par) {
            ch.push_back(nbr);
            solve(nbr, loc);
        }

        floater[loc] = cost[loc];
        choices[loc] = { loc };
        if (!ch.size()) return;

        vector<array<int, 2>> costs;
        for (int c : ch) {
            costs.push_back({ floater[c], c });
        }
        sort(all(costs));

        int mark_used = -1;
        for (int i = 0; i < costs.size() - 1; i++) {
            tot_cost += costs[i][0];
            mark_used = max(mark_used, costs[i][0]);
        }

        for (int i = 0; i < costs.size(); i++) {
            if (costs[i][0] <= mark_used)
                for (int v : choices[costs[i][1]])
                    can_use[v] = true;
        }

        if (floater[loc] == costs.back()[0]) {
            swap(choices[loc], choices[costs.back()[1]]);
            choices[loc].push_back(loc);
        } else if (floater[loc] > costs.back()[0]) {
            floater[loc] = costs.back()[0];
            swap(choices[loc], choices[costs.back()[1]]);
        }
    };


    int ROOT = 0;
    solve(ROOT, ROOT);
    tot_cost += floater[ROOT];
    for (int v : choices[ROOT])
        can_use[v] = true;

    int usable = 0;
    for (bool b : can_use)
        usable += b;

    cout << tot_cost << " " << usable << "\n";
    for (int i = 0; i < N; i++) {
        if (can_use[i])
            cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}