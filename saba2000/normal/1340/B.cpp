#include<bits/stdc++.h>
using namespace std;
string f[11] = {
 "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int dp[2009][2009],ch[2009][11];
int F(string a, string b){
    int x = 0;
    for(int i= 0; i < a.size(); i++){
        if(a[i] > b[i]) return 2001;
        if(a[i] < b[i]) x++;
    }
    return x;

}
main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 0; j <= 9; j++){
            ch[i][j] = F(s, f[j]);
        }
    }
    dp[n+1][0] = 1;
    for(int i = n; i >=1; i--){
        for(int K = 0; K <= k; K++){
            for(int j = 0; j <= 9; j++)
                if(ch[i][j] <= K && dp[i+1][K-ch[i][j]]) dp[i][K] = 1;


        }
    }
    int rem = k;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        for(int j = 9; j >= 0; j--)
            if(ch[i][j] <= rem && dp[i+1][rem - ch[i][j]]){
                ans.push_back(j);
                rem -=ch[i][j];
                break;
            }
    }
    if(ans.size() != n){
        cout<<-1<<endl;
        return 0;

    }
    for(int i= 1; i <= n; i++)
        cout<<ans[i-1];
    cout<<endl;

}