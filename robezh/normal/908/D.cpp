#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;

ll fp(ll n, int k){
    if(k == 0) return 1;
    ll h = fp(n, k/2);
    return k%2 ? h*h%mod*n%mod : h*h%mod;
}

int k;
ll pa, pb, demon, invpb;
ll dp[1005][1005];

ll get(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];

    if(i + j >= k){
        ll res = ((i + j) + pa * invpb % mod) % mod;
        return res;
    }

    dp[i][j] = (pa * get(i+1,j) + pb * get(i, i+j))%mod * demon % mod;
    return dp[i][j];
}

int main() {
    cin >> k >> pa >> pb;
    for(int i = 0; i < 1005; i++) fill(dp[i], dp[i]+1005, -1);
    demon = fp(pa + pb, mod - 2);
    invpb = fp(pb, mod - 2);
    cout << get(1,0);
}