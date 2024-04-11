#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;
const ll MOD = 1e9 + 7;

pair<ll,ll> a[N];
ll s[N];

void up()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
        cin>>a[i].ff>>a[i].ss;
    sort(a+1,a+m+1);
    reverse(a+1,a+m+1);
    for (int i=1; i<=m; i++)
        s[i]=s[i-1]+a[i].ff;
    ll ans=0;
    for (int i=1; i<=m; i++)
    {
        int l=0,r=m;
        while (r-l>1)
        {
            int mid=(l+r)/2;
            if (a[mid].ff>a[i].ss) l=mid; else r=mid;
        }
        int ks=0;
        if (a[r].ff>a[i].ss) ks=r; else ks=l;
        ks=min(ks,n-1);
        if (ks<i)
        ans=max(ans,s[ks]+a[i].ff+a[i].ss*1ll*(n-ks-1));
        else ans=max(ans,s[ks]+a[i].ss*1ll*(n-ks));
        ///cout<<i<<": "<<ks<<endl;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}
/**
5 3
5 2
4 2
3 1
**/