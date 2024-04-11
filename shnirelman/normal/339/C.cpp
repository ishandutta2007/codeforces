#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 17) + 13;

bool dp[1013][20][13];
int p[1013][20][13];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int m;
    cin >> m;

    dp[0][0][0] = true;
    for(int i = 0; i < m; i++) {
        for(int d = 0; d <= 10; d++) {
            for(int x = 0; x <= 10; x++) if(dp[i][d][x]) {
//                cout << i << ' ' << d << ' ' << x << endl;
                for(int y = d + 1; y <= 10; y++) if(s[y - 1] == '1' && x != y) {
                    dp[i + 1][y - d][y] = true;
                    p[i + 1][y - d][y] = x;
                }
            }
        }
    }

    for(int d = 1; d <= 10; d++) {
        for(int x = 1; x <= 10; x++) if(dp[m][d][x]) {
            cout << "YES" << endl;
            vector<int> a(m);
            for(int i = m - 1; i >= 0; i--) {
//                cout << i << ' ' << d << ' ' << x << endl;
                a[i] = x;
                int x1 = x;
                x = p[i + 1][d][x];
                d = x1 - d;
            }

            for(int i = 0; i < m; i++)
                cout << a[i] << ' ';
            cout << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}