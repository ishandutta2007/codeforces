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
void solve() {
    int n;
    cin >> n;
    vector<int> lst(n, 0);
    int sum = 0;
    for (auto &i : lst) {
        cin >> i;
        sum += i;
    }
    if(sum % n){
        cout << "-1\n";
        return;
    }
    int k = sum / n;
    vector<vector<int>> operations;
    for (int i = 1; i < n; ++i) {
        operations.push_back({1, i + 1, (i + 1 - lst[i] % (i + 1)) % (i + 1)});
        lst[i] += (i + 1 - lst[i] % (i + 1)) % (i + 1);
        operations.push_back({i + 1, 1, lst[i] / (i + 1)});
    }
    for (int i = 1; i < n; ++i) {
        operations.push_back({1, i + 1, k});
    }
    cout << operations.size() << '\n';
    for(const auto &i : operations){
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
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