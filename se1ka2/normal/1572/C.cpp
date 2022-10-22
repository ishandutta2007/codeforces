#include <iostream>
#include <vector>
using namespace std;

vector<int> v[3005];
int dp[3005][3005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) v[i].clear();
        int a[3005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
            v[a[i]].push_back(i);
        }
        for(int k = 1; k < n; k++){
            for(int i = 0; i < n - k; i++){
                int j = i + k;
                dp[i][j] = dp[i + 1][j];
                for(int l = 0; l < (int)v[a[i]].size(); l++){
                    int m = v[a[i]][l];
                    if(m > i && m <= j){
                        dp[i][j] = max(dp[i][j], dp[i + 1][m - 1] + dp[m][j] + 1);
                    }
                }
            }
        }
        cout << n - 1 - dp[0][n - 1] << endl;
    }
}