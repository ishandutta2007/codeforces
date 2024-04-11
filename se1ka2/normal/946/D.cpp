#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1000000009;

int dp[505][505];
int w[505][505];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s[505];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) for(int j = 0; j <= k; j++) w[i][j] = INF;
    for(int i = 0; i < n; i++){
        vector<int> v;
        for(int j = 0; j < m; j++) if(s[i][j] == '1') v.push_back(j);
        for(int l = 0; l <= k; l++){
            if(l >= (int)v.size()){
                w[i][l] = 0;
                continue;
            }
            int r = (int)v.size() - l - 1;
            for(int j = 0; j + r < (int)v.size(); j++){
                w[i][l] = min(w[i][l], v[j + r] - (v[j] - 1));
            }
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 0; j <= k; j++) dp[i][j] = INF;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(j) dp[i][j] = dp[i][j - 1];
            for(int l = 0; l <= j; l++) dp[i][j] = min(dp[i][j], dp[i - 1][j - l] + w[i - 1][l]);
        }
    }
    cout << dp[n][k] << endl;
}