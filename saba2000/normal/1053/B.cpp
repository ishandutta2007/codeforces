#include<bits/stdc++.h>
using namespace std;
long long b[300009];
long long s[300009];
main(){
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++){
        long long a;
        scanf("%lld", &a);
        while(a){
            if(a&1) b[i]++;
            a/=2;
        }
    }
    for(long long i = 1; i <= n; i++){
        s[i] = b[i] + s[i-1];
    }
    long long x = 0, y = 0;
    for(long long i = 0; i <= n; i++){
        if(s[i] &1) x++;
        else y++;
    }

    long long ans = x * (x - 1) / 2 + y * (y - 1)/2;
    for(long long i = 1; i <= n; i++){
        long long M = b[i], S = 0;
        for(long long j = i ; j <= min(n,i + 64); j++){
            M = max(M, b[j]);
            S+=b[j];
            if(2 * M > S && S % 2 == 0) ans --;
        }
    }
    cout << ans << endl;
}