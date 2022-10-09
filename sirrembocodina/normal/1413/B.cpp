#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> stroki(n);
        for (int i = 0; i < n; i++) {
            stroki[i].resize(m);
            for (int j = 0; j < m; j++) {
                cin >> stroki[i][j];
            }
        }
        vector<vector<int>> stolbcy(m);
        for (int i = 0; i < m; i++) {
            stolbcy[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> stolbcy[i][j];
            }
        }
        int first_stroka = -1, first_stolbec = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (stroki[i][0] == stolbcy[j][0]) {
                    first_stolbec = j;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int cur = stolbcy[first_stolbec][i];
            for (int j = 0; j < n; j++) {
                if (stroki[j][0] != cur) {
                    continue;
                }
                for (int k = 0; k < m; k++) {
                    cout << stroki[j][k] << " ";
                }
                cout << endl;
            }
        }
    }
}