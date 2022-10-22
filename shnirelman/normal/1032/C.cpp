#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    vector<vector<int> > dp(n, vector<int> (5, -1));
    dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < 5; j++){
            if(dp[i][j] != -1){
                if(a[i] == a[i + 1])
                    {for(int l = 0; l < 5; l++)if(l != j)dp[i + 1][l] = j;}
                else if(a[i] < a[i + 1]){
                    for(int l = j + 1; l < 5; l++)
                            //cout << "dsgf";
                        dp[i + 1][l] = j;
                        //cout << dp[i + 1][l] << ' ' << i + 1 << ' ' << l << " dg"<< endl;
                    }
                else for(int l = 0; l < j; l++)dp[i + 1][l] = j;
                //cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << (a[i] < a[i + 1]) << endl;
            }
            //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }

    for(int i = 0; i < 5; i++)if(dp[n - 1][i] != -1){
        vector<int> ans;
        int j = i;
        int l = n - 1;
        //cout << i << endl;
        while(l >= 0){
                //cout << "dsg";
            ans.push_back(j);//cout << l << ' ' << j;
            j = dp[l][j];//cout << "dsg";
            l--;
            //cout << l << ' ' << j << endl;

        }
        for(int i = n - 1; i >= 0; i--)cout << ans[i] + 1 << ' ';

        return 0;
    }
    cout << -1;
}