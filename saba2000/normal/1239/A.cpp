#include<bits/stdc++.h>
using namespace std;
long long dp[200009];
long long mod = 1e9+7;
main(){
    long long n, m;
    cin >> n >> m;
    dp[0] = 1;
    dp[1] = 1;
    for(long long i = 2; i <= max(n, m); i++){
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    cout<< 2*((dp[n] +dp[m])% mod+mod  -1)% mod<<endl;

}
/*
YY
XXY
YYX
XXYX
YYX
*/