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
#define int long long
signed main() {
    ios_base::sync_with_stdio(0);
    int m, k;
    cin >> m >> k;
    vector<int> sum;
    vector<int> sumsq(k);
    vector<vector<int>> nums(k);
    for (int i = 0; i < k; ++i) {
        int s = 0, ssq = 0;
        for (int j = 0; j < m; ++j) {
            int x;cin >> x;
            nums[i].push_back(x);
            s += x;
            ssq += x * x;
        }
        sum.push_back(s);
        sumsq[i] = ssq;
    }
    int d = 0;
    if (sum[1] - sum[0] == sum[2] - sum[1])
        d = sum[1] - sum[0];
    else
        d = sum[4] - sum[3];
    int bd = -1;
    for (int i = 0; i + 1 < k; ++i) {
        if (sum[i] + d != sum[i + 1]) {
            bd = i + 1;
            break;
        }
    }
    int sqv = 0;
    if (bd >= 3) {
        sqv = (sumsq[2] - 2 * sumsq[1] + sumsq[0]) / 2;
    } else {
        sqv = (sumsq[5] - 2 * sumsq[4] + sumsq[3]) / 2;
    }
    //cerr << sqv << endl;
    int d1 = sum[bd - 1] + d - sum[bd];
    int corssq = (sumsq[bd - 1] + sumsq[bd + 1]) / 2 - sqv;
   // cout << corssq << endl;
    int d2 = corssq - sumsq[bd];
    cout << bd << ' ';
    //cerr << d1 << ' ' << d2;
    for (auto i : nums[bd]) {
        if (2 * i * d1 + d1 * d1 == d2) {
            cout << i + d1;
            return 0;
        }
    }
}