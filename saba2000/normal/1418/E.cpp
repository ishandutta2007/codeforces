#include<bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long d[200009],s[200009],inv[2000009];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    inv[0] = 1;
    inv[1]  =1;
    for(long long i = 1; i <= n; i++){
        cin >> d[i];
    }
    for(long long i = 2; i <= n+1; i++){
        inv[i] = inv[mod % i] * (mod - mod / i) % mod;
    }
    sort(d+1, d+n+1);
    for(long long i = 1; i <= n; i++){
        s[i] = s[i-1] + d[i];
    }
    for(long long i = 1; i <= m; i++){
        long long a, b;
        cin >> a >> b;
        long long lo = 0, hi = n;
        while(lo < hi){
            long long mid = (lo + hi+1)/2;
            if(d[mid] < b) lo = mid;
            else hi = mid - 1;
        }
        long long s2 = s[lo] % mod, s1 = (s[n] - s[lo])% mod;
        long long u = n - lo;
        if(u < a) {
            cout << 0 << endl;
            continue;
        }
        cout << (s1 % mod * inv[u] % mod * (u - a) % mod +
                 s2% mod * (u-a+1) % mod * inv[u + 1] % mod) % mod << endl;
    }



}