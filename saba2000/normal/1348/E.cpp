#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[509][509];
ll a[509],b[509];
main(){
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll Sa = 0, Sb = 0;
    for(ll i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        Sa += a[i];
        Sb += b[i];
    }
    dp[0][0] = 1;
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j < k; j++){
            if(!dp[i-1][j]) continue;
            dp[i][j] = 1;
            for(ll x = 0; x <= k; x++){
                if(x <= a[i] && k - x <= b[i])
                    dp[i][(j + x) % k] = 1;

            }

        }
    }

    for(ll i = 1; i < k; i++){
        if(!dp[n][i]) continue;
        if((Sa - i) / k + (Sb - (k - i)) / k + 1 > Sa / k + Sb / k){
            cout<<Sa/k + Sb / k + 1 << endl;
            return 0;
        }
    }
    cout<<Sa/k + Sb/k<<endl;
}
//X Y
//A B
//