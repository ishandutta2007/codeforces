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
    vector<vector<bool>> table(n, vector<bool>(n));
    vector<int> aa(n), bb(n);
    for (int i = 0; i < n; ++i) {
        cin >> aa[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> bb[i];
    }
    vector<int> sum(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            if ((aa[i] & aa[j]) == aa[i]) {
                table[i][j] = 1;
                sum[i] += 1;
            }
        }
    }
    vector<int> neadd(n);
    queue<int> que;
    for (int k = 0; k < n; ++k) {
        if (sum[k] == 0)
            que.push(k);
    }
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        neadd[v] = 1;
        for (int j = 0; j < n; ++j) {
            if (table[j][v]) {
                sum[j] -= 1;
                if (sum[j] == 0)
                    que.push(j);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (!neadd[i])
            res += bb[i];
    }
    cout << res;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    //cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}