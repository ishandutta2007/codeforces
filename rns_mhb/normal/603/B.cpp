#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int k, p, d, x, ans;
    scanf("%d%d", &p, &k);
    if(k == 0) d = p - 1;
    else if(k == 1) d = p;
    else {
        x = k, d = 1;
        while(x != 1) {
            x = 1ll * x * k % p;
            d ++;
        }
        d = (p - 1) / d;
    }
    ans = 1;
    while(d) {
        if(d & 1) ans = 1ll * ans * p % mod;
        p = 1ll * p * p % mod;
        d >>= 1;
    }
    printf("%d\n", ans);
}