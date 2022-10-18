#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ss second
#define ff first
const ll N = 5000000 + 11;
map<ll,ll> mt1,mt2;
int a[N];
int  main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        if (a[i]%m==0) ans+=mt2[a[i]/m];
        if (a[i]%m==0) mt2[a[i]]+=mt1[a[i]/m];
        mt1[a[i]]++;
    }
    cout<<ans<<endl;
}