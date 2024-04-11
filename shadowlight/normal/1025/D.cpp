#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int N = 707;

int n;
vector <int> a;

bool can[N][N][2];

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
    cin >> n;
    a.resize(n);
    bool g[n][n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = (bool) (__gcd(a[i], a[j]) > 1);
        }
    }
    for (int i = 0; i < n; i++) {
        can[i][i][0] = true;
        can[i][i][1] = true;
        if (i && g[i - 1][i]) {
            can[i][i + 1][0] = true;
        }
        if (i < n - 1 && g[i][i + 1]) {
            can[i][i + 1][1] = true;
        }
    }
    can[n][n][0] = true;
    can[n][n][1] = true;
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l < n; l++) {
            if (l + len > n) break;
            for (int pos = l; pos < l + len; pos++) {
                if (l && g[l - 1][pos] && can[l][pos][1] && can[pos + 1][l + len][0]) {
                    can[l][l + len][0] = true;
                }
                if (l + len < n && g[pos][l + len] && can[l][pos][1] && can[pos + 1][l + len][0]) {
                    can[l][l + len][1] = true;
                }
            }
            //cout << l << " " << l + len << " " << can[l][l + len][0] << " " << can[l][l + len][1] << "\n";
        }
    }
    for (int pos = 0; pos < n; pos++) {
        if (can[0][pos][1] && can[pos + 1][n][0]) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}