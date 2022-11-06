#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5,p=1e9+7;

ll sum(ll n)
{
    return (n*(n+1))/2;
}

ll oddsum(ll n)
{
    n=(n+1)/2;
    return n*n;
}

int main()
{
    ll q;
    cin >> q;
    while(q--)
    {
        ll l,r;
        scanf("%I64d %I64d", &l, &r);
        l--;
        ll ans=sum(r)-sum(l);
        ll mns=oddsum(r)-oddsum(l);
        cout << ans-2*mns << endl;
    }
}