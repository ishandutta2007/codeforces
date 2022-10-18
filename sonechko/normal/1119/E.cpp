#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 3e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll ans=0;
    ll kol=0;
    for (int i=1; i<=n; i++)
    {
        ll l;
        cin>>l;
        ll p=min(kol,l/2);
        ans+=p;
        kol-=p;
        l-=p*2;
        ans+=l/3;
        l%=3;
        kol+=l;
    }
    cout<<ans<<endl;
}