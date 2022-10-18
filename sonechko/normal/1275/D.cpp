#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll ans=3e9;
        for (ll x=a-1; x<=a+1; x++)
        for (ll y=b-1; y<=b+1; y++)
        for (ll z=c-1; z<=c+1; z++)
        ans=min(ans,abs(x-y)+abs(x-z)+abs(y-z));
        cout<<ans<<"\n";
    }
}