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
vector<int> numtok(int x, int k) {
    vector<int> res;
    while (x != 0) {
        res.push_back(x % k);
        x /= k;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> numiki(n);
    for (int i = 0; i < n; ++i) {
        numiki[i] = numtok(i, k);
    }
    int ans = numiki.back().size();
    for (int i = 0; i < n; ++i) {
        while (numiki[i].size() != ans)
            numiki[i].push_back(0);
        reverse(all(numiki[i]));
    }
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int l = 0; l < ans; ++l) {
                if (numiki[i][l] != numiki[j][l]) {
                    //cerr << i << ' ' << j << ' ' << l + 1 << endl;
                    cout << l + 1 << ' ';
                    break;
                }
            }
        }
    }
}