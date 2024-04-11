#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 1e5 + 11;
ll v[N],a,b,c,d,n;
ll use[N];
bool good(int k)
{
    vector<ll> vv;
    for (int p=n; p>=n-k+1; p--)
    {
        vv.pb(v[p]);
    }
    if (a<=c)
    {
        ll x=d;
        for (int i=0; i<vv.size(); i++)
        {
            x*=vv[i];
            if (x>=b) return true;
        }
        if (x>=b) return true;
        return false;
    }
    if (b<=d)
    {
        ll x=c;
        for (int i=0; i<vv.size(); i++)
        {
            x*=vv[i];
            if (x>=a) return true;
        }
        if (x>=a) return true;
        return false;
    }



    for (int i=1; i<=100000; i++)
        use[i]=0;
    use[1]=1;
    ll krols=1e18;
    ll kk=krols;
    for (int i=0; i<vv.size(); i++)
    for (ll j=100000; j>=1; j--)
    if (use[j]==1)
    {
        if (j*vv[i]<=100000) use[vv[i]*j]=1; else krols=min(krols,vv[i]*j);
    }
    ll t=0;
    for (ll j=1; j<=100000; j++)
        if (use[j]==1&&j*c>=a) {t=j; break;}
    if (t==0&&krols!=kk) t=krols;
    if (t==0) return false;
    ll x=d;
    for (int i=0; i<vv.size(); i++)
    {
        x*=vv[i];
        ll nsd=__gcd(t,x);
        x/=nsd;
        t/=nsd;
        if (x>=b) return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>a>>b>>c>>d>>n;
    for (int i=1; i<=n; i++)
        cin>>v[i];
    sort(v+1,v+n+1);

    int l=0,r=min((int)n,40);
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    int ans1=n+1;
    if (good(l)) ans1=l; else
    if (good(r)) ans1=r;

    swap(a,b);
    l=0;
    r=min((int)n,40);
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    if (good(l)) ans1=min(ans1,l); else
    if (good(r)) ans1=min(ans1,r);
    if (ans1==n+1) cout<<-1<<endl; else cout<<ans1<<endl;
}