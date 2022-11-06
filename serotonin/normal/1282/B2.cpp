#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

ll a[sz], ans[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll n,p,k;
        scanf("%lld %lld %lld", &n, &p, &k);
        for(ll i=1; i<=n; i++) scanf("%lld", &a[i]);
        sort(a,a+n+1);

        ll now=0;
        for(ll i=1; i<=n; i++) {
            if(i>=k) ans[i]=a[i]+ans[i-k];
            else ans[i]=a[i]+ans[i-1];
            if(ans[i]<=p) now=i;
        }

        printf("%lld\n", now);
    }
}