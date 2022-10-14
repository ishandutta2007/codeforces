#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

#define pb push_back
using namespace std;


int main() {
    string s;
    cin >> s;
    vector<vector<int>> ans;
    for (int i = 0; i < 10; i++) {
        vector<int> plos;
        for (int j = 0; j < 10; j++) {
            plos.pb(-1);
        }
        ans.pb(plos);
    }
    for (int x = 0; x < 10; x++) {
        for (int y = x; y < 10; y++) {
            vector<int> paths;
            for (int ii = 0; ii < 10; ii++) {
                paths.pb(-1);
            }
            for (int c1 = 0; c1 < 10; c1++) {
                for (int c2 = 0; c2 < 10; c2++) {
                    if (c1 or c2) {
                        if (paths[(c1 * x + c2 * y) % 10] == -1) {
                            paths[(c1 * x + c2 * y) % 10] = c1 + c2 - 1;
                        } else {
                            paths[(c1 * x + c2 * y) % 10] = min(c1 + c2 - 1, paths[(c1 * x + c2 * y) % 10]);
                        }
                    }
                }
            }
            int sab = 0;
            for (int i = 0; i < s.size() - 1; i++) {
                if (paths[(10 + s[i + 1] - s[i]) % 10] == -1) {
                    sab = -1;
                    break;
                }
                sab += paths[(10 + s[i + 1] - s[i]) % 10];
            }
            ans[x][y] = sab;
            ans[y][x] = sab;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}