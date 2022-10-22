#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;

int gcd(int a, int b){
    if(b == 0)return a;
    else return gcd(b, a % b);
}

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    vector<long long> dp(n + 13, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        vector<int> res;
        //res.push_back(1);
        for(int j = 1; j * j <= a[i]; j++)if(a[i] % j == 0){
            res.push_back(j);
            if(j != a[i] / j)res.push_back(a[i] / j);
        }

        sort(res.rbegin(), res.rend());

        for(int j = 0; j < res.size(); j++)if(res[j] <= n){
            dp[res[j]] += dp[res[j] - 1];
            if(dp[res[j]] > M)dp[res[j]] -= M;
        }
    }

    long long ans = 0;
    for(int i = 1; i < dp.size(); i++)ans = (ans + dp[i]) % M;

    cout << ans;
}