#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=2e5+5, inf=2e9;

ll a[sz];

int main()
{
    ll n,k;
    cin >> n >> k;
    for(ll i=0; i<n; i++) scanf("%lld", &a[i]);
    sort(a,a+n,greater<ll>());

    ll l=0, h=inf, m=(l+h+1)/2;
    while(l<h) {
        ll tot=0;
        for(ll i=0; i<=n/2; i++) {
            if(a[i]<m) tot+=m-a[i];
        }
        if(tot<=k) l=m;
        else h=m-1;
        m=(l+h+1)/2;
    }

    cout << m;
}