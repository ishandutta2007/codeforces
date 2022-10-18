#include<bits/stdc++.h>

using namespace std;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
ll a[100000+10],b[100000+10];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,x;
    cin>>n>>x;
    for (ll i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    ll ans=0;
    for (ll i=1; i<=n; i++)
    {
        ll k=(x^a[i]);
        if (k<=100000) ans+=b[k];
        b[a[i]]++;
    }
    cout<<ans<<endl;
}