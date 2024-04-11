#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll ans=0;
        if (a+c<b) ans=max(ans,a+c); else ans=max(ans,(a+b+c)/2);
        if (a+b<c) ans=max(ans,a+b); else ans=max(ans,(a+b+c)/2);
        if (b+c<a) ans=max(ans,b+c); else ans=max(ans,(a+b+c)/2);
        cout<<ans<<"\n";
    }
}
/**
8
1 1 1 1 210 140 84 60
**/