#include<bits/stdc++.h>
using namespace std;
main(){
    int n;
    cin >> n;
    while(n--){
        long long p,q,b;
        scanf("%lld%lld%lld", &p, &q, &b);
        long long d = __gcd(p, q);
        p /= d; q /= d;
        while(1){
            long long x = __gcd(q, b);
            if(x==1) break;
            while(q % x == 0) q /= x;
        }
        if( q == 1) {
            printf("Finite\n");
        }
        else{
            printf("Infinite\n");
        }
    }

}