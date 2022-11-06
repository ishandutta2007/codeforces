#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

ll a[sz];

int main()
{
    ll n,m,k;
    cin >> n >> m >> k;
    for(ll i=0; i<m; i++) scanf("%lld", &a[i]);

    ll ans=0;
    for(ll i=0; i<m; i++, ans++) {
        ll page=(a[i]-i+k-1)/k, d=i;
        while(i<m-1 && a[i+1]<=page*k+d) i++;
    }

    cout << ans << endl;
}