#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int centroid(int N, auto &tree, vi &size, int loc, int par) {
    size[loc] = 1;
    int ret = loc;
    for (auto [ch, w] : tree[loc]) {
        if (ch == par) continue;
        int res = centroid(N, tree, size, ch, loc);
        size[loc] += size[ch];
        if (size[ch] * 2 > N)
            ret = res;
    }
    return ret;
}

void calc_dist(auto &tree, vll &dist, int loc, int par) {
    for (auto [ch, w] : tree[loc]) {
        if (ch == par) continue;
        dist[ch] = dist[loc] + w;
        calc_dist(tree, dist, ch, loc);
    }
}

void assign_labels(auto &tree, vi &label, int &cur, int loc, int par){
    label[loc] = cur;
    for (auto [ch, w] : tree[loc]) {
        if (ch == par) continue;
        if (loc == par) cur++;
        assign_labels(tree, label, cur, ch, loc);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vector<vector<array<int, 2>>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].push_back({ v-1, w });
        adj[v-1].push_back({ u-1, w });
    }

    vi size(N);
    int root = centroid(N, adj, size, 0, 0);

    vll dist(N);
    calc_dist(adj, dist, root, root);

    ll total = 0;
    for (ll v : dist) total += 2 * v;
    cout << total << "\n";

    vi label(N);
    int L = 0;
    assign_labels(adj, label, L, root, root);
    L++;

    vi left(L);
    vector<priority_queue<int, vi, greater<int>>> avail(L);
    for (int i = 0; i < N; i++) {
        left[label[i]]++;
        avail[label[i]].push(i);
    }
    vi right = left;
    right[label[root]]--;

    set<pair<int, int>> elct;
    for (int i = 0; i < L; i++)
        elct.insert({ left[i] + right[i], i });

    set<pair<int, int>> elow;
    for (int i = 0; i < L; i++)
        elow.insert({ avail[i].top(), i });

    for (int i = 0; i < N; i++) {
        int par;
        auto force = *elct.rbegin();
        if (force.first == (N - i) && label[i] != force.second) {
            par = force.second;
        } else {
            auto it = elow.begin();
            if (i != root && it ->second == label[i])
                it = next(it);
            par = it->second;
        }

        if (i) cout << " ";
        cout << avail[par].top() + 1;

        elct.erase({ left[label[i]] + right[label[i]], label[i] });
        left[label[i]]--;
        elct.insert({ left[label[i]] + right[label[i]], label[i] });

        elow.erase({ avail[par].top(), par });
        avail[par].pop();
        if (!avail[par].empty()) {
            elow.insert({ avail[par].top(), par });
        }
        elct.erase({ left[par] + right[par], par });
        right[par]--;
        elct.insert({ left[par] + right[par], par });
    }

    cout << endl;
    return 0;
}