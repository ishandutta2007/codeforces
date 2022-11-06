#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5,inf=1e9;

ll a[sz];

int main()
{
    ll n;
    cin >> n;
    for(ll i=0; i<n; i++) scanf("%lld", &a[i]);
    sort(a,a+n);

    ll tot=0;
    for(ll i=0; i<n-1; i++) tot+=a[i];
    if(tot>=a[n-1] && (tot+a[n-1])%2==0) puts("YES");
    else puts("NO");
}