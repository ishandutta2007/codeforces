#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5+5;

ll a[sz];
pair <ll,ll> p[sz];

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll n,s;
        scanf("%lld %lld", &n, &s);
        for(ll i=0; i<n; i++) scanf("%lld %lld", &p[i].first, &p[i].second);
        sort(p,p+n);

        ll low=0, high=s;
        while(low<high) {
            ll b=s, m=(low+high+1)/2, k=n/2+1;
            for(ll i=n-1; i>=0; i--) {
                if(k && p[i].second>=m) {
                    b-=max(m,p[i].first);
                    k--;
                }
                else b-=p[i].first;
            }
            if(b>=0 && !k) low=m;
            else high=m-1;
        }

        printf("%lld\n", low);
    }
}