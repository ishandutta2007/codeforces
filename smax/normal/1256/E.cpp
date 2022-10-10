#include <bits/stdc++.h>
using namespace std;

int numTeams[200000], teamSize[200000], teamID[200000];
long long dp[200000];
pair<int, int> a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    dp[0] = dp[1] = INT_MAX;
    dp[2] = a[2].first - a[0].first;
    dp[3] = a[3].first - a[0].first;
    dp[4] = a[4].first - a[0].first;
    numTeams[2] = numTeams[3] = numTeams[4] = 1;
    teamSize[2] = 3;
    teamSize[3] = 4;
    teamSize[4] = 5;
    for (int i=5; i<n; i++) {
        dp[i] = a[i].first - a[0].first;
        numTeams[i] = 1;
        teamSize[i] = i + 1;
        for (int j=3; j<=5; j++)
            if (dp[i-j] + a[i].first - a[i-j+1].first < dp[i])
                dp[i] = dp[i-j] + a[i].first - a[i-j+1].first, numTeams[i] = numTeams[i-j] + 1, teamSize[i] = j;
    }

    int i = n - 1, k = numTeams[n-1];
    while (k > 0) {
        for (int j=i; j>i-teamSize[i]; j--)
            teamID[a[j].second] = k;
        k--;
        i -= teamSize[i];
    }

    cout << dp[n-1] << " " << numTeams[n-1] << "\n";
    for (int i=0; i<n; i++)
        cout << teamID[i] << " ";
    cout << "\n";

    return 0;
}