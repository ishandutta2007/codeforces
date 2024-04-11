#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 3e5 + 11;

ll a[N];
map<ll,ll> mt[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        ll d=a[i];
        ll c=0,p=1;
        while (d>0)
        {
            d/=10;
            p*=10;
            p%=k;
            c++;
        }
        d=a[i];
        d%=k;
        mt[c][d%k]++;
        if ((d*p+d)%k==0) ans--;
    }
    for (int i=1; i<=n; i++)
    {
        ll d=a[i]%k;
        ll c=1;
        for (int kk=1; kk<=10; kk++)
        {
            c=(c*10)%k;
            ll t=(d*c)%k;
            t=(k-t)%k;
            ans+=mt[kk][t];
        }
    }
    cout<<ans<<"\n";
}
/**


**/