#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

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
    string s;
    cin >> s;
    map <char, int> num;
    num['R'] = 0;
    num['G'] = 1;
    num['B'] = 2;
    string t = "RGB";
    vector <vector <int> > dp(n, vector <int> (3, INF));
    vector <vector <int> > pr(n, vector <int> (3, -1));
    for (int i = 0; i < 3; i++) {
        if (num[s[0]] != i) {
            dp[0][i] = 1;
        } else {
            dp[0][i] = 0;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                int add = (int) (num[s[i]] != k);
                if (dp[i][k] > dp[i - 1][j] + add) {
                    dp[i][k] = dp[i - 1][j] + add;
                    pr[i][k] = j;
                }
            }
        }
    }
    string res = "";
    int mink = INF;
    int last = -1;
    for (int i = 0; i < 3; i++) {
        if (mink > dp[n - 1][i]) {
            mink = dp[n - 1][i];
            last = i;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        res += t[last];
        last = pr[i][last];
    }
    reverse(res.begin(), res.end());
    cout << mink << "\n" << res << "\n";
}