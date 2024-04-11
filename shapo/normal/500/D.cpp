#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector< int > tree_size;
vector< pair< int, int > > par;
vector< vector< pair< int, int > > > g;
vector< int > used;
vector< double > coeff;
vector< int > len;
double ans = 0.;
int n, q;

void
dfs(int x, int parent, int w)
{
    used[x] = true;
    tree_size[x] = 1;
    par[x] = make_pair(parent, w);
    for (auto edge : g[x]) {
        if (!used[edge.first]) {
            dfs(edge.first, x, edge.second);
            tree_size[x] += tree_size[edge.first];
        }
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    tree_size.resize(n);
    par.resize(n);
    g.clear();
    g.resize(n);
    used.assign(n, 0);
    coeff.assign(n - 1, 0);
    len.assign(n - 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        --a, --b;
        len[i] = l;
        g[a].push_back(make_pair(b, i));
        g[b].push_back(make_pair(a, i));
    }
    dfs(0, -1, -1);
    for (int i = 1; i < n; ++i) {
        int ne = par[i].second;
        int a = tree_size[i], b = n - a;
        //coeff[ne] = 3. * (a + 0.) / (n + 0.) * (b + 0.) / (n - 1.) * (a + b - 2.) / (n - 2.);
        coeff[ne] = 3. * (a + 0.) / (n + 0.) * (b + 0.) / (n - 1.);
        //cout << a << ' ' << b << '\n';
        //cout << coeff[ne] << '\n';
        ans += coeff[ne] * len[ne];
    }
    cin >> q;
    cout << fixed << setprecision(10);
    for (int i = 0; i < q; ++i) {
        int r, w;
        cin >> r >> w;
        r--;
        ans -= coeff[r] * len[r];
        len[r] = w;
        ans += coeff[r] * len[r];
        cout << ans * 2 << '\n';
    }
    return 0;
}