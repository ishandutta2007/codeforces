#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

typedef vector<vector<pair<int, char>>> tree;

void dfs1(int loc, tree &adj, int mask, vi &masks, vi &size) {
    WATCH(loc);

    masks[loc] = mask;
    size[loc] = 1;

    for (auto ch : adj[loc]) {
        dfs1(ch.first, adj, mask ^ (1 << (ch.second - 'a')), masks, size);
        size[loc] += size[ch.first];
    }

    sort(all(adj[loc]), [&](const pair<int, char> &p1, const pair<int, char> &p2) {
        return size[p1.first] > size[p2.first];
    });
}

void pm(int &v, int u) {
    v = max(v, u);
}

const int MAXN = 5e5 + 5;
int dep[25][MAXN];

vector<int> solve(int loc, tree &adj, int depth, int store, vi &index, vvi &compat, vi &res) {
    // leaf case
    if (adj[loc].size() == 0) {
        pm(dep[store][index[loc]], depth);
        res[loc] = 0;
        return { loc } ;
    }

    // non leaf case, do the heavy child first in place
    vi elts = solve(adj[loc][0].first, adj, depth + 1, store, index, compat, res);
    res[loc] = max(res[loc], res[adj[loc][0].first]);

    // now combine with the results for the light children
    for (int ch = 1; ch < adj[loc].size(); ch++) {
        vi chelts = solve(adj[loc][ch].first, adj, depth + 1, store + 1, index, compat, res);
        res[loc] = max(res[loc], res[adj[loc][ch].first]);

        for (int blw : chelts) {
            for (int comb : compat[index[blw]])
                if (dep[store][comb] > 0 && dep[store + 1][index[blw]] > 0)
                    res[loc] = max(res[loc], dep[store][comb] + dep[store + 1][index[blw]] - 2 * depth);
        }

        for (int blw : chelts) {
            pm(dep[store][index[blw]], dep[store+1][index[blw]]);
            dep[store + 1][index[blw]] = 0;
            elts.push_back(blw);
        }
    }

    // check if the best path ends in the current root
    for (int comb : compat[index[loc]])
        res[loc] = max(res[loc], dep[store][comb] - depth);

    pm(dep[store][index[loc]], depth);
    elts.push_back(loc);

    WATCH(loc);
    WATCHC(elts);

    return elts;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    scanf("%d", &N);

    tree adj(N);

    for (int i = 0; i < N - 1; i++) {
        int par;
        char let;

        scanf("%d %c", &par, &let);
        adj[par-1].emplace_back(i + 1, let);
    }

    vi mask(N);
    vi size(N);

    dfs1(0, adj, 0, mask, size);

    vi all_masks = mask;
    sort(all(all_masks));
    all_masks.erase(unique(all(all_masks)), all_masks.end());

    WATCHC(all_masks);

    const int M = all_masks.size();

    vvi compat(M);
    for (int i = 0; i < M; i++) {
        compat[i].push_back(i);
        for (int j = 0; j < 26; j++) {
            int k = all_masks[i] ^ (1 << j);
            auto it = lower_bound(all(all_masks), k);
            if (it != all_masks.end() && *it == k)
                compat[i].push_back(it - all_masks.begin());
        }
    }

    vi index(N);
    for (int i = 0; i < N; i++) {
        auto it = lower_bound(all(all_masks), mask[i]);
        index[i] = it - all_masks.begin();
    }

    vi res(N);
    solve(0, adj, 1, 0, index, compat, res);

    for (int v : res)
        printf("%d ", v);
    printf("\n");

    return 0;
}