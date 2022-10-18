#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
const int N = 2e5 + 11;
ll a[N],b[N];
int n;
ll good(int k)
{
    for (ll i=1; i<=n; i++)
        b[i]=a[i]+i*k;
    sort(b+1,b+n+1);
    ll ds=0;
    for (int i=1; i<=k; i++)
        ds+=b[i];
    return ds;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int l=0,r=n;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)<=m) l=mid; else r=mid;
    }
    if (good(r)<=m) cout<<r<<" "<<good(r)<<endl; else
        cout<<l<<" "<<good(l)<<endl;

}