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
bool ch(vector<vector<int>> table) {
    vector<int> cnt(table.size());
    for (int i = 0; i < table.size(); ++i) {
        for (auto j : table[i])
            cnt[i] += j;
        //cout << cnt[i] << ' ';
        if (i != 0 and cnt[i] > cnt[i-1])
            return 0;
    }
    return 1;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int j = 1; j <= n + 6; ++j) {
        vector<vector<int>> table(j, vector<int>(j));
        int nn = n;
        bool br = false;
        for (int i = 0; i < j; ++i) {
            for (int k = i; k < j; ++k) {
                if (nn == 4 and k != i and k + 1 >= j)
                    break;
                if (k != i)
                    nn--;
                nn--;
                if (nn < 0){
                    nn += 2;
                    if (k == i + 1)
                        br = 1;
                    break;
                }
                table[i][k] = table[k][i] = 1;
                if (nn == 0 and ch(table)) {
                    cout << j << '\n';
                    for (int x = 0; x < j; ++x) {
                        for (int y = 0; y < j; ++y) {
                            if (table[j - x - 1][y])
                                cout << 'o';
                            else
                                cout << '.';
                        }
                        cout << '\n';
                    }
                    return 0;
                }
            }
            if (br)
                break;
        }
    }
    cout << -1;
}