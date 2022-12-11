#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
const int N = 2e4 + 34;
const long double EPS = 1e-12;
const int INF = 1e9 + 34;
const int md = 1e8;

int n2, n1, k1, k2, nb;
int ans;
int d[111][111][21];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n1 >> n2 >> k1 >> k2;
    d[0][0][10] = 1;
    for (int i = 0; i <= n1; i++)
        for (int j = 0; j <= n2; j++) 
            for (int b = -k1; b <= k2; b++) {
                if (d[i][j][b + 10] == 0)
                    continue;
                if (b > -k1) {
                    nb = min(-1, b - 1);
                    d[i + 1][j][nb + 10] = (d[i + 1][j][nb + 10] + d[i][j][b + 10]) % md;
                }
                if (b < k2) {
                    nb = max(1, b + 1);
                    d[i][j + 1][nb + 10] = (d[i][j + 1][nb + 10] + d[i][j][b + 10]) % md;
                }
            }

    int ans = 0;
    for (int b = -k1; b <= k2; b++)
        ans = (ans + d[n1][n2][b + 10]) % md;
    cout << ans;

    return 0;
}