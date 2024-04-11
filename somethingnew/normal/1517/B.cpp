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
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &i : a) {
        for (auto &j : i)
            cin >> j;
        sort(all(i));
    }
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        int ind = 0;
        for (int j = 0; j < n; ++j) {
            if (a[ind][0] > a[j][0])
                ind = j;
        }
        for (int j = 0; j + 1 < a[ind].size(); ++j) {
            swap(a[ind][j], a[ind][j + 1]);
        }
        for (int j = 0; j < n; ++j) {
            ans[j][i] = a[j].back();
            a[j].pop_back();
        }
    }
    for (auto t : ans) {
        for (auto j : t)
            cout << j << ' ';
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}