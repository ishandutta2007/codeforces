#include<bits/stdc++.h>
using namespace std;
long long dp[1000009],ans,mod =998244353;
int F[1000009], f[209][209];
vector<int> v[209];
main(){
    int n, m;
    cin >> n >> m;
    int x = 1, y = 2;
    for(int i =0 ;i < m; i++){
       int a,b; cin >>a>>b;
       f[a-1][b-1] = 1;
    }
    for(int j = 0; j < (1 << n); j++){
        for(int a = 0; a < n; a++)
            for(int b =0; b < n; b++)
                if(((1<<a) & j) && ((1<<b)&j) && f[a][b]) F[j]  =1;
    }
    dp[0] = 1;
    for(int b = 1; b < (1 << n); b++){
        for(int x = b; x; x = (x - 1) & b){
            int k = __builtin_popcount(x)&1;
            if(!F[x]) dp[b] += dp[b - x] * (2*k-1);
        }
    }
    cout << dp[(1<<n)-1] % mod * m % mod *((mod + 1)/2)  % mod  << endl;
}