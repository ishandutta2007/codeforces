#include<bits/stdc++.h>
using namespace std;
int dp[20009];
void solve(){
    int n;
    cin >> n;
    int m = 0, a = 0;
    vector<int> v;
    for(int i = 1; i <= 2*n; i++){
        int x;
        cin >> x;
        if(x < m){
            a++;
            continue;
        }
        m = x;
        v.push_back(a);
        a = 1;

    }
    for(int i = 1; i <= n; i++)
        dp[i] = 0;
    dp[0] = 1;
    v.push_back(a);
    for(int i = 0; i < v.size(); i++){
        for(int j = n; j >= v[i];j--){
            if(dp[j - v[i]]) dp[j] = 1;
        }
    }
    cout << (dp[n] ? "YES" : "NO") <<endl;
}
main(){
    int t;
    cin >> t;
    while(t--){
       solve();

    }
}