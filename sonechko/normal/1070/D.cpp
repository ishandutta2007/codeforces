#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll ans=0,ost=0;
    for (int i=1; i<=n; i++)
    {
        ll l;
        cin>>l;
        //cout<<ans<<" "<<ost<<endl;
        if (ost!=0)
        {
            ll p=min(l,ost);
            l-=p;
            ost=0;
        }
        ans+=l/k;
        if (l%k!=0)
        {
            ost=k-(l%k);
            ans++;
        }
    }
    cout<<ans<<endl;
}