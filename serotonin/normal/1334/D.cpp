#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll n, l, r;
        scanf("%lld %lld %lld", &n, &l, &r);

        ll tot = 1;
        for(ll i=1; i<n; i++) {
            ll x = n - i;
            x <<= 1;
            tot += x;
            if(tot >= l) {
                tot -= x;
                for(ll j=tot, k=i, g=k; j<=r; j++) {
                    if(j & 1) {
                         if(j >= l) printf("%lld ", k);
                    }
                    else {
                        ++g;
                        if(j >= l) printf("%lld ", g);
                        if(g == n) g = ++k;
                        if(g == n) k = 1;
                    }
//                    printf("\n fuck %lld\n", j);
                }
                puts("");
                break;
            }
        }
    }
}