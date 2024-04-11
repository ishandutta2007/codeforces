#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll M = 998244353;

ll pw(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b&1){
            ret=ret*a%M;
        }
        b>>=1;
        a=a*a%M;
    }
    return ret;
}

ll dp[505][505];
ll dpC[505][505];

ll C(ll n, ll k){
    if(k == 0 || n == k)return 1;
    if(dpC[n][k] != -1)return dpC[n][k];
    return dpC[n][k] = (C(n-1,k-1) + C(n-1,k))%M;
}

ll fin(int n, int k){
    if(n == 0)return 1;
    if(n == 1)return 0;
    if(k <= 0)return 0;
    if(dp[n][k] != -1)return dp[n][k];
    ll ret = 0;
    for(int i = 0; i <= n; ++i){
        ret+=pw(min(n-1,k),i)*fin(n-i,k-n+1)%M*C(n,i);
        ret%=M;
    }
    return dp[n][k] = ret;
}

int main(){
    int n, k; cin >> n >> k;
    for(int i = 0; i < 505; ++i)for(int j = 0; j < 505; ++j)dp[i][j] = -1;
    for(int i = 0; i < 505; ++i)for(int j = 0; j < 505; ++j)dpC[i][j] = -1;
    cout << fin(n,k);
}