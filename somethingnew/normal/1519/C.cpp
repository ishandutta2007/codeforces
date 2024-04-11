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
#include "queue"
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
void solve(){
    int n;
    cin >> n;
    int sum = 0;
    vector<int> u(n), s(n);
    for (auto &i : u)
        cin >> i;
    for (auto &i : s) {
        cin >> i;
    }
    vector<vector<int>> nabori(n + 1);
    for (int i = 0; i < n; ++i) {
        nabori[u[i]-1].push_back(s[i]);
    }
    vector<int> res(n + 1);
    for (int i = 0; i < n; ++i) {
        sort(all(nabori[i]));
        vector<int> prefs(nabori[i].size() + 1);
        for (int j = 0; j < nabori[i].size(); ++j) {
            prefs[j + 1] = prefs[j] + nabori[i][j];
        }
        for (int j = 1; j <= nabori[i].size(); ++j) {
            res[j] += prefs.back() - prefs[nabori[i].size() % j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << ' ';
    }
    cout << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}