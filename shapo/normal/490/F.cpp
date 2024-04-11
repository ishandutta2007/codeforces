#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair< short, short > pss;

int n;
vector< int > population;
vector< vector< int > > g;
vector< int > used;
// for dfs and parent-child relationships
vector< int > l, r, par, inc_seq, dec_seq;
vector< int > traversal;
int res = 0;

void
dfs(int v, int parent)
{
    static int _timer = 0;
    used[v] = true;
    par[v] = parent;
    l[v] = _timer++;
    traversal.push_back(v);
    for (auto x : g[v]) {
        if (!used[x]) {
            dfs(x, v);
        }
    }
    r[v] = _timer;
    int p = population[v];
    for (int i = l[v] + 1; i < r[v]; ++i) {
        int x = traversal[i], px = population[x];
        if (p < px) {
            dec_seq[v] = max(dec_seq[v], dec_seq[x] + 1);
        } else if (p > px) {
            inc_seq[v] = max(inc_seq[v], inc_seq[x] + 1);
        }
    }
    res = max(res, max(inc_seq[v], dec_seq[v]));
}

void
check_update(int iv, int dv, int parv)
{
    if (population[iv] >= population[dv]) {
        return;
    }
    int ans = inc_seq[iv] + dec_seq[dv];
    if (population[iv] < population[parv] && population[parv] < population[dv]) {
        ans++;
    }
    res = max(res, ans);
}


int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    population.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> population[i];
    }
    g.clear();
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    used.assign(n, 0);
    l.assign(n, -1);
    r = par = l;
    inc_seq.assign(n, 1);
    dec_seq.assign(n, 1);
    dfs(0, -1);
    for (int v = 0; v < n; ++v) {
        // vertex to increase
        int parv = par[v];
        int lv = l[v], rv = r[v];
        while (parv != -1) {
            for (int ind = l[parv] + 1; ind < lv; ++ind) {
                int dec_v = traversal[ind];
                check_update(v, dec_v, parv);
            }
            for (int ind = rv; ind < r[parv]; ++ind) {
                int dec_v = traversal[ind];
                check_update(v, dec_v, parv);
            }
            lv = l[parv], rv = r[parv];
            parv = par[parv];
        }
    }
    cout << res << '\n';
    return 0;
}