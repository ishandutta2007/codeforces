#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<vector<int>> g;
int val = 0;
int dfspoc(int v, int p) {
    int poc = 0;
    for (auto i : g[v]) {
        if (i == p)
            continue;
        int k = dfspoc(i, v);
        if (k == 1 and poc == 0)
            poc = 1;
        if (k == 2)
            poc = 2;
    }
    if (poc == 0) {
        val++;
        return 1;
    }
    if (v == 0)
        return 2;
    if (poc == 1) {
        val--;
        return 0;
    }
    return 2;
}
void solve(){
    val = 0;
    g.clear();
    int n;
    cin >> n;
    g.assign(n, {});
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfspoc(0, -1);
    cout << val << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}