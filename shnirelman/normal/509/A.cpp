#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int> > dp(n, vector<int>(n, 1));
    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

    cout << dp[n - 1][n - 1] << endl;
}