#include<bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll unsigned long long
const int N = 1e3 + 10;
ll next1[N],a[N],ans[N];
ll nsd(ll l, ll r)
{
    while (l>0&&r>0)
        if (l>r) l%=r; else r%=l;
    return l+r;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    for (ll i=1; i<=n; i++)
        {
            cin>>a[i];
            next1[i]=i;
        }
    for (ll i=1; i<=n*n; i++)
    {
        for (ll j=1; j<=n; j++)
            next1[j]=a[next1[j]];
        for (ll j=1; j<=n; j++)
        {
            ll k=next1[j];
            if (next1[k]==j&&ans[k]==0) ans[k]=i;
        }
    }
    ll k=1;
    for (ll i=1; i<=n; i++)
    if (ans[i]==0) {cout<<-1<<endl; return 0;}
    for (ll i=1; i<=n; i++)
    {
        k=ans[i]/nsd(ans[i],k)*k;
    }
    cout<<endl;
    cout<<k<<endl;
}