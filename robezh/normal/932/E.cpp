#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7, N = 5005;

int n,k;
ll dp[N][N];

ll fp(int x, int k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf*hf%mod*x%mod : hf*hf%mod;
}

ll get(int t, int b){
    if(dp[t][b] != -1) return dp[t][b];
    if(t == 0) return dp[t][b] = fp(2, n-b);
    if(b == 0) return dp[t][b] = n * get(t-1, b+1) % mod;
    if(b == n) return dp[t][b] = n * get(t-1, b) % mod;

    return dp[t][b] = (b * get(t-1, b) + (n - b) * get(t-1, b+1)) % mod;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < N; i++){fill(dp[i], dp[i]+N, -1);}
    cout << get(k, 0);
}