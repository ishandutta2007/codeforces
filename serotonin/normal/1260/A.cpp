#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll c,sum;
        scanf("%lld %lld", &c, &sum);
        ll x=sum/c;
        ll ans=0;
        for(ll i=0; i<c; i++) {
            if(i<sum%c) ans+=(x+1)*(x+1);
            else ans+=x*x;
        }
        printf("%lld\n", ans);
    }
}