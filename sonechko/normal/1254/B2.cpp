#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 1e6 + 11;

ll a[N],b[N],c[N],p[N];
int n;

ll get(ll t)
{
    for (int i=1; i<=n; i++)
    {
        b[i]=(a[i]%t);
        c[i]=0;
        p[i]=0;
    }

    int pos=0;
    ll kk=0;
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        if (kk==0) pos=i;
        kk+=b[i];
        if (kk>=t)
        {
            ll left=kk-t;
            b[i]=b[i]-left;
            int l=pos;
            int r=i;
            ll res=2e18;
            c[l-1]=0;
            p[l-1]=0;
            for (int d=l; d<=r; d++)
            {
                c[d]=c[d-1]+b[d];
                p[d]=p[d-1]+b[d]*1ll*d;
            }
            for (int d=l; d<=r; d++)
            {
                ll res2=d*1ll*(c[d]-c[l-1]) - (p[d]-p[l-1]);
                res2+=(p[r]-p[d]) - d*1ll*(c[r]-c[d]);
                res=min(res,res2);
            }
            ans+=res;
            pos=i;
            kk=left;
            b[i]=left;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    ll k=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        k+=1ll*a[i];
    }
    if (k==1) return cout<<-1, 0;
    ll ans=2e18;
    vector<ll> p;
    ll d=2;
    while (d*d<=k)
    {
        if (k%d==0) p.pb(d);
        while (k%d==0)
            k/=d;
        d++;
    }
    if (k>1) p.pb(k);
    for (int j=0; j<p.size(); j++)
        ans=min(ans,get(p[j]));
    cout<<ans<<"\n";
}

/**
(d-p1) + (d-p2) + (d-p3) + (d-p4)
+
(p5-d) + (p6-d) + (p7-d) + (p8-d)
**/