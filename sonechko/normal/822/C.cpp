#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
const int N = 2e5 + 11;
int d[N],a[N],b[N],c[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,x;
    cin>>n>>x;
    vector<pair<int,int> > v;
    for (int i=1; i<=n; i++)
        {
            int l,r,k;
            cin>>l>>r>>k;
            v.pb(mp(l,-i));
            v.pb(mp(r,i));
            a[i]=l;
            b[i]=r;
            c[i]=k;
        }
    sort(v.begin(),v.end());
    int ans=2e9+2;
    for (int i=0; i<v.size(); i++)
    {
        pair<int,int> p=v[i];
        if (p.ss<0)
        {
            p.ss*=-1;
            int ks=b[p.ss]-a[p.ss]+1;
            if (ks<=x&&d[x-ks]!=0) ans=min(ans,c[p.ss]+d[x-ks]);
        } else
        {
            int ks=b[p.ss]-a[p.ss]+1;
            if (ks<=x)
            {
                if (d[ks]==0) d[ks]=c[p.ss]; else d[ks]=min(d[ks],c[p.ss]);
            }
        }
    }
    if (ans==(int)2e9+2) cout<<-1<<endl; else cout<<ans<<endl;
}