#include <bits/stdc++.h>
#include <ext/numeric>
using namespace std;
using namespace __gnu_cxx;

const int MAX = 1010;
int n, m;
long long arr[MAX];
long long dp[MAX][MAX][2];

int subset(int idx, long long sum, bool cnt) {

    //if (sum % m == 0 && cnt != 0)
        //return 1;
    if (idx == n)
        return (cnt > 0 && sum % m == 0);

    if (dp[idx][sum % m][cnt] != -1)
        return dp[idx][sum % m][cnt];

    dp[idx][sum % m][cnt] = ((subset(idx + 1, sum % m, cnt)
            + subset(idx + 1, (sum + arr[idx]) % m,  1)));

    return dp[idx][sum % m][cnt];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
//  freopen("o.txt", "wt", stdout);
#endif
    cin >> n >> m;
    if (n > m) {
        cout << "YES";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 0) {
            cout << "YES";
            return 0;
        }
    }
    memset(dp, -1, sizeof dp);
    if (subset(0, 0, 0))
        cout << "YES";
    else
        cout << "NO";
}