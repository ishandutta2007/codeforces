#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int k_N = 1e6 + 3;
const ll k_Inf = 1e18 + 3;

int n;
ll r1, r2, r3, d;

ll a[k_N], dp[k_N], suffix[k_N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r1 >> r2 >> r3 >> d;

    long long ans = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    ll mn = k_Inf;
    for(int i = n - 1; i >= 0; --i){
        suffix[i] = min(r2 + r1, r1 * a[i] + 2 * r1);
        //cout << suffix[i] << " suffix[i]" << endl;

        dp[i] = dp[i + 1] + r1 * a[i] + r3;
        if(i != n - 1)
            dp[i] += d;

        //cout << dp[i] << " dp[i] " << endl;

        ll curr = dp[i + 1] + suffix[i] + 2 * d;
        if(i != n - 1 && i != n - 2)
            curr += d;

        dp[i] = min(dp[i], curr);

        mn += suffix[i] + 3 * d;
        if(i != n - 1){
            curr = dp[i + 2] + suffix[i] + suffix[i + 1] + 3 * d;
            if(i != n - 2)
                curr += d;
            mn = min(mn, curr);
        }

        dp[i] = min(dp[i], mn);
    
        //cout << "dp[" << i << "] = " << dp[i] << "\n";
    }

    cout << dp[0] << "\n";
}