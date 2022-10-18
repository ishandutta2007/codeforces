#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 1e6 + 11;

ll a[N],ss[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        ss[i]=ss[i-1]+a[i];
    }
    int pos=1;
    ll kol=0;
    for (int i=1; i<=q; i++)
    {
        ll k;
        cin>>k;
        int l=pos,r=n;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (ss[mid]-ss[pos-1]-kol<=k) l=mid; else r=mid;
        }
        if (ss[r]-ss[pos-1]-kol<=k)
        {
            kol=k-(ss[r]-ss[pos-1]-kol);
            pos=r+1;
        } else
        if (ss[l]-ss[pos-1]-kol<=k)
        {
            kol=k-(ss[l]-ss[pos-1]-kol);
            pos=l+1;
        } else kol+=k;
        if (pos==n+1)
        {
            pos=1;
            kol=0;
        }
        cout<<n-pos+1<<"\n";
    }
}