#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll k0[N],k1[N];
pair<ll,ll> a[N];

void up()
{
    ll n,T,aa,bb;
    cin>>n>>T>>aa>>bb;
    for (int i=1; i<=n; i++)
        cin>>a[i].ss;
    for (int i=1; i<=n; i++)
        cin>>a[i].ff;
    sort(a+1,a+n+1);
    k0[n+1]=0;
    k1[n+1]=0;
    for (int i=n; i>=1; i--)
    {
        k0[i]=k0[i+1]+(a[i].ss==0);
        k1[i]=k1[i+1]+(a[i].ss==1);
    }
    ll kk0=0,kk1=0,ans=0;
    for (int i=1; i<=n; i++)
    {
        ll ttime=min(T,a[i].ff-1);
        ttime-=aa*1ll*kk0;
        ttime-=bb*1ll*kk1;
        ll kol=i-1;
        if (ttime>=0)
        {
            ll p=min(ttime/aa,k0[i]);
            kol+=p;
            ttime-=p*aa;
            p=min(ttime/bb,k1[i]);
            kol+=p;
            ttime-=p*bb;
            ans=max(ans,kol);
        }
        if (a[i].ss==0) kk0++; else kk1++;
    }
    ll ttime=T;
    ttime-=aa*1ll*kk0;
    ttime-=bb*1ll*kk1;
    if (ttime>=0) ans=max(ans,n);
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin>>m;
    while (m--)
        up();
}
/**
1
3 5 1 3
0 0 1
2 1 4
**/