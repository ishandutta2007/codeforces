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

bool sl2(vector<pair<int, int>> a, int m) {
    int cnt = 0;
    for (auto [r, l] : a) {
        if (cnt <= l and cnt + r + 1 >= m) {
            cnt++;
        }
    }
    return cnt >= m;
}
void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (auto &i : p)
        cin >> i.first >> i.second;
    int l = 0;
    int r = n + 1;
    while (l + 1 < r) {
        int m = l + r >> 1;
        if (sl2(p, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}