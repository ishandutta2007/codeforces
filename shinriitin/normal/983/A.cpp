#include <bits/stdc++.h>

int main(){
    using ll = long long;
    int n; scanf("%d", &n);
    while(n --){
        ll p, q, b, g;
        scanf("%lld%lld%lld", &p, &q, &b);
        g = std::__gcd(p, q);
        p /= g, q /= g;
        while((g = std::__gcd(q, b))>1){
            while(!(q%g)) q /= g;
            b = g;
        } 
        puts(q==1?"Finite":"Infinite"); 
    }
    return 0;
}