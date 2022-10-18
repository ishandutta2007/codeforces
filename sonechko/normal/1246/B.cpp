#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 4e5 + 11;

ll kk[N],a[N],ks[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        kk[a[i]]++;
    }
    if (k==2)
    {
        ll ans=0;
        for (int i=1; i<=n; i++)
        {
            ll p=a[i],x=1;
            ll d=2;
            while (d*d<=p)
            {
                int kk=0;
                while (p%d==0)
                {
                    kk++;
                    p/=d;
                }
                kk%=2;
                if (kk==1) x*=d;
                d++;
            }
            x*=p;
            ans+=ks[x];
            ks[x]++;
        }
        cout<<ans<<"\n";
        return 0;
    }
    ll p=1,ans=0;
    while (1)
    {
        ll x=1;
        for (int j=1; j<=k; j++)
            x*=p;
        if (x>(long long)(1e10)) break;
        ll c=x/100000;
        for (ll j=max(1ll,c-1); j<=(ll)sqrt(x); j++)
            if (x%j==0)
        {
            if (x/j>100000) continue;
            ll p1=kk[j];
            ll p2=kk[x/j];
            if (j==x/j)
            {
                ans+=p1*(p1-1)/2;
            } else ans+=p1*p2;
        }
        p++;
    }
    cout<<ans;
}