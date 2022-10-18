#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 3e5 + 11;

ll a[N],c[N],p[N];
int n;

ll get(int t)
{
    int pos=0,kk=0;
    ll ans=0;
    for (int i=1; i<=n; i++)
    if (a[i]==1&&pos==0) {kk=1; pos=i;} else
    if (a[i]==1)
    {
        kk++;
        if (kk==t)
        {
            int l=pos;
            int r=i;
            ll res=2e18;
            for (int d=l; d<=r; d++)
            {
                ll res2=d*1ll*(c[d]-c[l-1]) - (p[d]-p[l-1]);
                res2+=(p[r]-p[d]) - d*1ll*(c[r]-c[d]);
                res=min(res,res2);
            }
            ans+=res;
            pos=0;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    int k=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        k+=a[i];
        c[i]=c[i-1]+a[i];
        p[i]=p[i-1];
        if (a[i]==1) p[i]+=1ll*i;
    }
    int t=0;
    ll ans=2e18;
    for (int i=2; i<=k; i++)
    if (k%i==0)
    {
        t=1;
        ans=min(ans,get(i));
    }
    if (t==0) return cout<<-1, 0;
    cout<<ans<<"\n";
}

/**
(d-p1) + (d-p2) + (d-p3) + (d-p4)
+
(p5-d) + (p6-d) + (p7-d) + (p8-d)
**/