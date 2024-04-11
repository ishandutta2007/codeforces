#include<bits/stdc++.h>
using namespace std;
long long mod = 998244353 ;
long long inv[300009], f[2009];
main(){
    long long n, m, k;
    cin >> n>> m >> k;
    inv[0] = 1;
    inv[1] = 1;
    for(long long i =2; i <= 2000; i++)
        inv[i] = inv[mod%i] *(mod - mod / i) % mod;

    long long ans = m;
    for(long long i = k + 1; i <= n-1;  i++)
        ans = ans * i % mod* inv[i - k] % mod;
    for(long long i = 0; i < k; i++)
        ans = ans * (m-1) % mod;
    cout<<ans<<endl;
    //C(n-1,k);
}