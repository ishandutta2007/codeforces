#include<bits/stdc++.h>
#define ll long long
using namespace std;
int f[509],g[509], l[2009];
int dp[2009][2009];
void solve(){
    int n;
    string s,t,cs,ct;
    cin>>n>>s>>t;
    cs = s, ct = t;
    sort(cs.begin(), cs.end()); sort(ct.begin(),ct.end());
    if(cs != ct){
        cout<<-1<<endl;
        return;
    }for(int c = 'a';  c <= 'z'; c++)
            f[c] = 0;
    s = '#' + s;
    t = '#' + t;
    for(int i = 1; i <= n; i++){
        for(int c = 'a';  c <= 'z'; c++)
            g[c] = 0;
        f[t[i]]++;
        int k = 1;
        while(k <= n){
            int x = s[k];
            g[x] ++;
            if(g[x] > f[x]) break;
            else k++;
        }
        l[i] = k - 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){

            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            if(s[i] == t[j] && i <= l[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    cout<<n - dp[n][n] << endl;

}
main(){
    int t;
    cin >> t;
    while(t--)
        solve();


}