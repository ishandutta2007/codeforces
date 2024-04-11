#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e6 + 11;


int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,q;
    cin>>n>>q;
    for (int i=1; i<=q; i++)
    {
        ll x;
        cin>>x;
        ll ans=x;
        if (x%2==0)
        {
            ll y=1;
            ll dr=0;
            while (1==1)
            {
                y=x/2;
                dr=n-y;
                dr--;
                if (n*2-x-1==dr*2) {ans=x; break;}
                x+=dr;
                x++;
            }
        }
        cout<<ans/2+ans%2<<"\n";
    }
}