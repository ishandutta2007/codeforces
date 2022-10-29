#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;

int n;
vvi g;
vi sh, ma;
vi cnt;

void
calc_ans(int x, int par, int bit)
{
    cnt[x] = 0;
    bool is_leaf = true;
    for (auto to : g[x]) {
        if (to != par) {
            calc_ans(to, x, bit ^ 1);
            is_leaf = false;
            cnt[x] += cnt[to];
        }
    }
    if (is_leaf) {
        cnt[x]++;
        sh[x] = ma[x] = 1;
    } else {
        { // calc sh
            int val = 1;
            for (auto to : g[x]) {
                if (to != par) {
                    if (bit == 0) {
                        val = max(val, cnt[x] - cnt[to] + sh[to]);
                    } else {
                        val += sh[to] - 1;
                    }
                }
            }
            sh[x] = val;
        }
        { // calc ma
            int val = cnt[x];
            for (auto to : g[x]) {
                if (to != par) {
                    if (bit == 1) {
                        val = min(val, ma[to]);
                    } else {
                        val -= cnt[to] - ma[to];
                    }
                }
            }
            ma[x] = val;
        }
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    sh.assign(n, -1);
    ma.assign(n, -1);
    g.assign(n, vi());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cnt.assign(n, 0);
    calc_ans(0, -1, 0);
    cout << sh[0] << ' ' << ma[0] << '\n';
    return 0;
}