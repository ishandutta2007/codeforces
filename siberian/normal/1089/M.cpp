#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) (x).begin(),(x).end()

const int N = 20;
int n;
vector<int> g[N];
vector<int> rg[N];
bool used[N];
int color[N];
vector<int> comp[N];
vector<int> order;
int c;

void dfsOrder(int v) {
    used[v] = true;
    for (auto i : g[v]) {
        if (used[i]) continue;
        dfsOrder(i);
    }
    order.push_back(v);
}

void dfsColor(int v) {
    used[v] = true;
    color[v] = c;
    comp[c].push_back(v);
    for (auto i : rg[v]) {
        if (used[i]) continue;
        dfsColor(i);
    }
}

vector<pair<int, int>> edges;

void scc() {
    fill(used, used + n, false);
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        dfsOrder(i);
    }
    reverse(all(order));
    fill(used, used + n, false);
    c = 0;
    for (auto i : order) {
        if (used[i]) continue;
        dfsColor(i);
        c++;    
    }
    for (int i = 0; i < n; ++i) {
        for (auto j : g[i]) {
            int u = color[i];
            int v = color[j];
            if (u == v) continue;
            assert(u < v);
            edges.push_back({u, v});
        }
    }
    sort(all(edges));
    edges.resize(unique(all(edges)) - edges.begin());

    /*cout << "comps = " << endl;
    for (int i = 0; i < c; ++i) {
        for (auto v : comp[i]) {
            cout << v << " ";
        }
        cout << endl;
    }*/
}

const int A = 1000;

char ans[2 * N][3][A];

void buildAns() {
    for (int i = 0; i < 2 * N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < A; ++k) {
                ans[i][j][k] = '.';
                if (i & 1) {
                    ans[i][j][k] = '#';
                }
            }
        }
    }
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < comp[i].size(); ++j) {
            ans[(i + 1) * 2][0][j] = '1' + comp[i][j];
        }
    }
    for (int i = 0; i < edges.size(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        for (int x = u; x < v; ++x) {
            ans[(x + 1) * 2 + 1][2][i * 3 + 2] = '.';
        }
        for (int x = u + 1; x < v; ++x) {
            ans[(x + 1) * 2][2][i * 3 + 2 - 1] = '#';
            ans[(x + 1) * 2][2][i * 3 + 2 + 1] = '#';    
            ans[(x + 1) * 2][2 - 1][i * 3 + 2] = '#';    
        }
    }
}

void printAns() {
    cout << A << " " << 3 << " " << 2 * N << "\n";
    for (int i = 0; i < 2 * N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < A; ++k) {
                cout << ans[i][j][k];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x == 1) {
                g[i].push_back(j);
                rg[j].push_back(i);
            }
        }
    } 
    scc();
    buildAns();
    printAns();
	return 0;
}