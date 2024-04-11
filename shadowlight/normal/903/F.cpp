#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int N = (1 << 12);

string f(int mask) {
    string res = "";
    while (mask > 0) {
        res += (char) ('0' + mask % 2);
        mask /= 2;
    }
    while (res.size() < 12) {
        res += "0";
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n;
    cin >> n;
    vector <vector <char> > table(4, vector <char> (n + 5, '.'));
    vector <int> a(5, 0);
    a[0] = 0;
    for (int i = 1; i <= 4; i++) {
        cin >> a[i];
    }
    vector <vector <vector <int> > > dp(4, vector <vector <int> > (n + 5, vector <int> (N, INF)));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j][0] = 0;
        }
    }
    vector <int> masks(4, 0);
    masks[0] = 0;
    for (int i = 1; i <= 3; i++) {
        int mask = 0;
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                mask |= 1 << (j + k * 4);
            }
        }
        masks[i] = mask;
        //cout << f(masks[i]) << "\n";
    }
    for (int j = 0; j < n + 4; j++) {
        for (int i = 0; i < 4; i++) {
            for (int mask = 0; mask < N; mask++) {
                if (dp[i][j][mask] == INF) continue;
                int x = i + 1, y = j;
                if (x == 4) {
                    x = 0;
                    y++;
                }
                if (i == 3) {
                    dp[i][j + 1][N - 1] = min(dp[i][j + 1][N - 1], dp[i][j][mask] + a[4]);
                }
                //cout << i << " " << j << " " << f(mask) << " " << dp[i][j][mask] << "\n";
                for (int k = 0; k <= min(3, i + 1); k++) {
                    int nm = mask | masks[k];
                    if (((nm >> 11) & 1) == 0 && y - 3 >= 0 && table[x][y - 3] == '*') continue;
                    nm <<= 1;
                    nm %= N;
                    dp[x][y][nm] = min(dp[x][y][nm], dp[i][j][mask] + a[k]);
                }
            }
        }
    }
    cout << dp[0][n + 4][0];
}