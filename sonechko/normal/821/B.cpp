#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define ss second
#define ld long double
#define pb push_back
#define ff first
const int N = 5000 + 11;
const int M = 1e9;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m,b;
    cin>>m>>b;
    ld k=-1/(ld)m;
    ll ans=0;
    ll x=10000000;
    for (ll i=0; i<=10000000; i++)
    {
        for (ll j=x; j>=0; j--)
        {
            ld y=(ld)i*k+b;
            int yy=floor(y);
            if (yy>=j)
            {
                ans=max(ans,1LL*i*(i+1)/2*(j+1)+1LL*j*(j+1)/2*(i+1));
                x=j;
                break;
            }
        }
    }
    cout<<ans<<endl;
}