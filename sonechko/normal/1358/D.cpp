#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 4e5 + 11;

ll a[N];

ll sum(ll x)
{
    return x*(x+1)/2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ll x;
    cin>>n>>x;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=n+1; i<=2*n; i++)
        a[i]=a[i-n];
    n*=2;
    ll ans=0;
    ll l=n+1;
    ll s1=0,s2=0;
    for (int i=n; i>=1; i--)
    {
        if (l>i)
        {
            l=i;
            s1=a[i];
            s2=sum(a[i]);
        }
        while (l>1&&s1+a[l-1]<=x)
        {
            l--;
            s1+=a[l];
            s2+=sum(a[l]);
        }
        if (a[i]>=x) ans=max(ans,sum(a[i])-sum(a[i]-x));
        else
        {
            ans=max(ans,s2);
            if (l>1)
            {
                ll kol=x-s1;
                ans=max(ans,s2+sum(a[l-1])-sum(a[l-1]-kol));
            }
        }
        s1-=a[i];
        s2-=sum(a[i]);
    }
    cout<<ans;
}