#include<bits/stdc++.h>
using namespace std;
main(){
    long long n, k, a, b;
    cin >> n >> k >> a >> b;
    long long A[10];
     A[0] = (b - a + k + k) % k;
     A[1] = (b + a + k + k) % k;
     A[2] = (a - b + k + k) % k;
     A[3] = (-a - b + k + k) % k;
    long long x = 1, y = n*k;
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < 4; j++){
            long long l = (A[j] + i * k) % (n * k);
            long long c = n * k / __gcd(l, n*k);
            x = max(x, c);
            y = min(y, c);
        }

    }
    cout <<y<<" "<<x<<endl;
}