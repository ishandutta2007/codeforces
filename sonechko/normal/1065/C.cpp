#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    sort(a+1,a+n+1);
    ll pp=0,kol=0,h=2e9,ans=0;
    for (int i=n; i>=1; i--)
    {
        if (kol!=0)
        {
            ll c=h-a[i];
            if (pp+c*kol<=k) pp+=c*kol; else
            {
                ll t=(k-pp)/kol;
                c-=t;
                pp+=t*kol;
                if (pp>0) ans++;
                pp=0;
                if (c>0)
                {
                    ll d=k/kol;
                    ans+=c/d;
                    pp=(c%d)*kol;
                }
            }
        }
        kol++;
        h=a[i];
    }
    if (pp>0) ans++;
    cout<<ans<<endl;
}