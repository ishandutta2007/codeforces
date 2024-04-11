#include<bits/stdc++.h>
using namespace std;
long long p[300009],f[300009];
main(){
    long long n, k;
    cin >> n>> k;
    for(long long i = 1; i <= n; i++){
        cin >> p[i];
    }
    long long ans = 0;
    for(long long i = n; i >= n-k+1; i--){
        ans += i;

    }
    for(long long i = 1; i<= n; i++)
        if(p[i] >= n-k+1) f[i]=1;
    cout<<ans<<" ";
    long long ans1 = -1, mod  = 998244353;
    long long K = 0;
    for(long long i = 1; i <= n; i++){
        if(f[i] == 0) K++;
        else if(ans1 == -1) {ans1=1, K=0; continue;}
        else ans1 = ans1 * (K+1)% mod, K =0;
    }
    cout<<ans1<<endl;
}