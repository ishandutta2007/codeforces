#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kn, km;
ll n, m, k;

int main(){
    cin >> n >> m >> k;
    kn = n, km = m;
    ll t = n * m, g = __gcd(t, k);
    t /= g, k /= g;

    if(k >= 3) return !printf("NO");
    ll gn = __gcd(g, n), gm = g / gn;
    n /= gn, m /= gm;
    printf("YES\n");
    if(k == 2) printf("0 0\n%I64d 0\n0 %I64d", n, m);
    else{
        if(2 * n <= kn) printf("0 0\n%I64d 0\n0 %I64d", 2 * n, m);
        else printf("0 0\n%I64d 0\n0 %I64d", n, 2*m);
    }
}