#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod = 998244353;
int inv[1000009];
int f[1000009];
int C[1000009];
int g[1000009];
main(){
    int n;
    cin >> n;
    f[0] = 1;
    g[0] = 1;
    for(int i = 1; i <= n; i++){
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * (n - i + 1) % mod;
    }
    int ans = 0;
    for(int i = 1; i <= n - 1; i++){
        ans = (ans + f[n] - g[i] + mod)% mod;
    }
    ans = (ans + f[n]) % mod;
    cout<<ans<<endl;
    
}