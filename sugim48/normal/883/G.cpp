#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

struct E {
    int to;
    int id;
};
VV<E> g;

int vc;
V<bool> vis;
V<bool> ans;
void dfs(int p, bool x) {
    vc++;
    vis[p] = true;
    for (E e: g[p]) {
        int d = e.to;
        if (vis[d]) continue;
        if (e.id == -1) {
            dfs(d, x);
            continue;
        }
        ans[e.id % TEN(8)] = e.id < TEN(8);
        if (x == true) {
            dfs(d, x);
        } else {
            ans[e.id % TEN(8)] = !ans[e.id % TEN(8)];
        }
    }
}
int main() {
    int n, m, s;
    cin >> n >> m >> s; s--;
    g = VV<E>(n);
    int c = 0;
    for (int i = 0; i < m; i++) {
        int t, a, b;
        cin >> t >> a >> b; a--; b--;
        if (t == 1) {
            //directed
            g[a].push_back(E{b, -1});
        } else {
            g[a].push_back(E{b, c});
            g[b].push_back(E{a, int(TEN(8))+c});
            c++;
        }
    }

    vc = 0;
    vis = V<bool>(n);
    ans = V<bool>(c);
    dfs(s, true);
    cout << vc << endl;
    for (bool f: ans) {
        if (f) {
            cout << "+";
        } else {
            cout << "-";
        }
    }
    cout << endl;

    vc = 0;
    vis = V<bool>(n);
    ans = V<bool>(c);
    dfs(s, false);
    cout << vc << endl;
    for (bool f: ans) {
        if (f) {
            cout << "+";
        } else {
            cout << "-";
        }
    }
    cout << endl;
    return 0;
}