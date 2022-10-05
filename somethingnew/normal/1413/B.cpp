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

using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<pair<int,int>> nums(n * m, {0, 0});
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int a;
            cin >> a;
            a--;
            nums[a].second = j;
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            a--;
            nums[a].first = i;
        }
    }
    for (int i = 0; i < n * m; ++i) {
        ans[nums[i].first][nums[i].second] = i + 1;
    }
    for (auto i : ans) {
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
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