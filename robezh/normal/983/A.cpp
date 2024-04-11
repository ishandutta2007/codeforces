#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return a == 0 ? b : gcd(b % a, a);
}

ll n,p,q,b;

int main() {
    scanf("%I64d", &n);
    while(n--){
        scanf("%I64d%I64d%I64d", &p, &q, &b);
        ll d = gcd(p,q);
        q /= d;
        int res = 1;
        while(true){
            if(q == 1) break;
            ll now = gcd(q,b);
            if(now == 1){res = 0; break;}
            q /= now; b = now;
        }
        if(res) printf("Finite\n");
        else printf("Infinite\n");
    }
}