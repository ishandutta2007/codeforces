#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,q;
    cin>>n>>q;
    for (int i=1; i<=q; i++)
    {
        ll l,r;
        cin>>l>>r;
        if ((l+r)%2==0)
        {
            if (n%2==0) cout<<(l-1)*(n/2)+(r+1)/2<<"\n"; else
            if (r%2==1) cout<<(l-1)/2*n+(r+1)/2<<"\n"; else
            cout<<(l-2)/2*n+(n+1)/2+(r+1)/2<<"\n";
        } else
        {
            ll kol=(n*n+1)/2;
            if (n%2==0) cout<<kol+(l-1)*(n/2)+(r+1)/2<<"\n"; else
            if (r%2==0) cout<<kol+(l-1)/2*n+(r+1)/2<<"\n"; else
            cout<<kol+(l-2)/2*n+n/2+(r+1)/2<<"\n";
        }
    }
}