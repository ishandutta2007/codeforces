#include<bits/stdc++.h>
using namespace std;
int a[300009];
int pr[300009];
int dp[300009];
int n;
int S[300009];
set<pair<int,int > > s[300009];
void solve(){
    cin >> n;
    for(int i = 0; i <= n; i++)
        S[i] = 0, s[i].clear();
    for(int i = 1; i <= n; i++){
        dp[i] = 0; pr[i] = 0;
        scanf("%d", &a[i]);
    }
    long long ans = 0;
    int c= 0;
    for(int i = 1; i <= n; i++){

        int x = S[i-1];
        auto it = s[x].lower_bound({a[i], n+1});
        if(it == s[x].begin()) pr[i] = 0;
        else{
            it--;
            if((*it).first != a[i]) pr[i] = 0;
            else pr[i] = (*it).second;
        }
        if(pr[i] == 0) s[++c].insert({a[i], i}), S[i] = c;
        else s[S[pr[i]-1]].insert({a[i], i}), S[i] = S[pr[i]-1];
        if(pr[i]) dp[i] = 1 + dp[pr[i] - 1];
         ans += dp[i];

    }
    printf("%lld\n",ans);
}
main(){
    int q;
    cin >> q;
    while(q--){
        solve();
    }
//.........2         2

}
//323323    3    3   3  3