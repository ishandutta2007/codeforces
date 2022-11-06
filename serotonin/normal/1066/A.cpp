#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

ll a[sz];

int main()
{
    ll t;
    cin >> t;
    while(t--) {
        ll L,v,l,r;
        scanf("%I64d %I64d %I64d %I64d", &L, &v, &l, &r);
        ll ans=(L/v)-((r/v)-(l-1)/v);
        printf("%I64d\n", ans);
    }
}