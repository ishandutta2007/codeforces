#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

constexpr int MAXN = 20 + 5;

bool yes[MAXN][MAXN];

int main()
{
    int T; cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        memset(yes, 0, sizeof(yes));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 || i == n || j == 1 || j == m) {
                    for (int ii = i - 1; ii <= i + 1; ii++) {
                        for (int jj = j - 1; jj <= j + 1; jj++) {
                            if (ii >= 1 && ii <= n && jj >= 1 && jj <= m && yes[ii][jj] == true) {
                                goto ONE_FALSE;
                            }
                        }
                    }
                    yes[i][j] = true;
                }
            ONE_FALSE:
                cout.put(yes[i][j] ? '1' : '0');
            }
            cout.put('\n');
        }

        if (T != 0) {
            cout.put('\n');
        }
    }

    return 0;
}