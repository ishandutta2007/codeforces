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
#include "array"
#include "queue"
#include "map"
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> numspos;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        numspos[c].push_back(i);
    }
    long long res = 0;
    for (auto i : numspos) {
        vector<int> ppos = i.second;
        vector<int> suffval(ppos.size() + 1);
        for (int j = ppos.size() - 1; j >= 0; --j) {
            suffval[j] = suffval[j + 1] + (n - ppos[j]);
        }
        for (int j = 0; j < ppos.size(); ++j) {
            res += suffval[j + 1] * (ppos[j] + 1);
        }
    }
    cout << res << '\n';
}
signed main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
}