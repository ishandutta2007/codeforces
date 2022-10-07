#include<bits/stdc++.h>
using namespace std;
string s[509];
int d[509][509];
int dp[509][509];
int n,m,k;
main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        vector<int> v;
        for (int i = 0; i < s.size(); i++){
            if(s[i] == '1')
                v.push_back(i);
        }
        if(v.size() == 0){
            continue;
        }
        for (int j = 0; j < v.size(); j++){
            d[i][j] = 1000000000;
            for (int k = 0; k <= j; k++){
                d[i][j] = min(d[i][j], v[v.size() - 1 - j + k] - v[k] + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            dp[i][j] = 1000000000;
            for(int p = 0; p <= j; p++){
                dp[i][j] = min(dp[i][j], dp[i-1][p] + d[i][j-p]);
            }
        }
    }
    cout << dp[n][k] << endl;

}