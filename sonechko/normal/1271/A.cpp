#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    ll res=0;
    for (int x=0; x<=min(a,d); x++)
    {
        ll ans=x*1ll*e;
        ans+=f*min(b,min(c,d-x));
        res=max(res,ans);
    }
    cout<<res;
}