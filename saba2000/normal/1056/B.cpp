#include<bits/stdc++.h>
using namespace std;
long long f[1009];
main(){
    long long n, m;
    cin >> n>> m;
    long long ans = 0;
    for(long long i = 1; i <= m; i++){
        for(long long j = 1; j <= m; j++){
            if((i*i + j * j) % m == 0){
                long long A = (n + m - i) / m;
                long long B = (n + m - j) / m;
                ans += A * B;
            }
        }
    }
    cout<<ans<<endl;
}