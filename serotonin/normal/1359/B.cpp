#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 5e5+5;

char s[sz];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll n, m, x, y, ans = 0;
        scanf("%lld %lld %lld %lld", &n, &m, &x, &y);
        for(ll i=0; i<n; i++) {
            scanf("%s", s);
            for(ll j=0, k=-1; ; j++) {
                if(s[j] != '.') {
                    ll len = j - k - 1;
                    ans += min(len * x, (len / 2) * y + (len & 1) * x);
                    k = j;
                }
                if(!s[j]) break;
            }
        }
        printf("%lld\n", ans);
    }
}