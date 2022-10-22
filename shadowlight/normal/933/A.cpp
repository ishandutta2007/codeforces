#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector <vector <vector <int> > > dp(n + 1, vector <vector <int> > (n + 1, vector <int> (2, 0)));
    vector <vector <int> > cnt1(n + 1, vector <int> (n + 1, 0));
    vector <vector <int> > cnt2(n + 1, vector <int> (n + 1, 0));
    for (int i = 0; i < n; i++) {
        int sum1 = 0, sum2 = 0;
        for (int j = i; j < n; j++) {
            if (a[j]) {
                sum2++;
            } else {
                sum1++;
            }
            cnt1[i][j] = sum1;
            cnt2[i][j] = sum2;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        int sum1 = 0, sum2 = 0;
        for (int j = i; j >= 0; j--) {
            if (!a[j]) {
                sum1++;
            } else {
                sum2++;
            }
            sum2 = max(sum2, sum1);
            dp[j][i][0] = sum1;
            dp[j][i][1] = sum2;
        }
    }
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            sum2++;
        } else {
            sum1++;
        }
        sum2 = max(sum2, sum1);
    }
    int maxk = sum2;
    for (int l = 0; l < n; l++) {
        int sum1 = (l ? cnt1[0][l - 1] : 0);
        for (int r = l; r < n; r++) {
            maxk = max(maxk, sum1 + dp[l][r][1] + cnt2[r + 1][n - 1]);
        }
    }
    cout << maxk;
}