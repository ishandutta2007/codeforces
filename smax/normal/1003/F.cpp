
// Problem : F. Abbreviation
// Contest : Codeforces Round #494 (Div. 3)
// URL : https://codeforces.com/contest/1003/problem/F
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

bool eq[300][300];
int dp[300][300];
string w[300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    int tot = 0;
    for (int i=0; i<n; i++) {
        cin >> w[i];
        tot += w[i].length() + (i > 0);
    }
    
    for (int i=0; i<n; i++)
        for (int j=i; j<n; j++)
            eq[i][j] = eq[j][i] = (w[i] == w[j]);
    
    for (int i=n-1; i>=0; i--)
        for (int j=n-1; j>=0; j--)
            dp[i][j] = (eq[i][j] ? (i < n - 1 && j < n - 1 ? dp[i+1][j+1] : 0) + 1 : 0);
    
    int ret = tot;
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=0; i+j<n; j++) {
            sum += w[i+j].length() + (j > 0);
            int cnt = 1;
            for (int k=i+j+1; k<n; k++)
                if (dp[i][k] > j) {
                    cnt++;
                    k += j;
                }
            int cur = tot - sum * cnt + (j + 1) * cnt;
            if (cnt > 1 && cur < ret)
                ret = cur;
        }
    }
    
    cout << ret << "\n";

    return 0;
}