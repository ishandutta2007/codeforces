#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 1e5 + 11;
const ll MOD = 1e9 + 7;
#define mod %MOD

ll a[N],ans;
int n;
void g(ll p, ll d)
{
    ll u=0;
    map<ll,ll> mt;
    for (int i=1; i<=n; i++)
    {
        if (a[i]==d) ans+=u;
        if (p%a[i]==0)
        {
            u+=mt[p/a[i]];
            mt[a[i]]++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    a[0]=LONG_LONG_MAX;
    int k1=0;
    for (int i=1; i<=n; i++)
        if (a[i]<a[k1]) k1=i;
    int k2=0;
    for (int i=1; i<=n; i++)
        if (a[i]<a[k2]&&i!=k1) k2=i;
    int k3=0;
    for (int i=1; i<=n; i++)
        if (a[i]<a[k3]&&i!=k2&&i!=k1) k3=i;
    g(a[k2]*a[k3],a[k1]);
    if (a[k2]!=a[k1]) g(a[k1]*a[k3],a[k2]);
    if (a[k3]!=a[k2]&&a[k3]!=a[k2]) g(a[k1]*a[k2],a[k3]);
    cout<<ans<<endl;
}