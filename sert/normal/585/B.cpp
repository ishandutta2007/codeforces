#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

string s[3];
bool dp[N][3];
int y;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < 3; i++)
            cin >> s[i];
        if (s[0][0] == 's') y = 0;
        else if (s[1][0] == 's') y = 1;
        else y = 2;
        s[y][0] = '.';
        if (s[y][1] != '.') {
            cout << "NO\n";
            continue;
        }
        s[0] += "....";
        s[1] += "....";
        s[2] += "....";
        for (int i = 0; i <= n + 5; i++)
            dp[i][0] = dp[i][1] = dp[i][2] = false;
        dp[1][y] = true;

        for (int i = 3; i <= n + 2; i++)
            for (int j = 0; j < 3; j++)
                for (int ii = 0; ii < 3; ii++) {
                    if (!dp[i - 3][ii] || (j == 0 && ii == 2) || (j == 2 && ii == 0))
                        continue;
                    if (s[j][i - 2] != '.' || s[j][i - 1] != '.' || s[j][i] != '.' || s[j][i - 3] != '.')
                        continue;
                    dp[i][j] = true;
                    //cerr << j << " " << i << "\n";
                }
        bool ok = false;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j <= 3; j++)
                if (dp[n - 1 + j][i])
                    ok = true;
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";

    }


    return 0;
}