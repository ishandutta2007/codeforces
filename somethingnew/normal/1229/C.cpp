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
#include "unordered_set"
#define all(x) (x).begin(), (x).end()
using namespace std;
vector<vector<int>> in;
vector<int> outsz;
long long res = 0;
void upd(int v) {
    res -= in[v].size() * (long long)outsz[v];
    for (auto i : in[v]) {
        res -= in[i].size();
        outsz[i] -= 1;
        in[i].push_back(v);
        res += outsz[i];
        outsz[v]++;
    }
    in[v].clear();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    in.assign(n, {});
    outsz.assign(n, {});
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        if (a > b)
            swap(a, b);
        in[a].push_back(b);
        outsz[b]++;
    }
    for (int i = 0; i < n; ++i) {
        res += in[i].size() * (long long)outsz[i];
    }
    cout << res << '\n';
    int q;
    cin >> q;
    while (q--) {
        int v;
        cin >> v;
        v--;
        upd(v);
        cout << res << '\n';
    }
}