#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
const int N = 2e5 + 11;

bool good(ll x, ll y, ll xx, ll yy)
{
    if (x>xx) return false; else
    if (y>yy) return false; else
    if (yy-y>=xx-x) return true; else return false;
}

int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        ll x,y,p,q;
        cin>>x>>y>>p>>q;
        if (p==0) {if (x==0) cout<<0<<"\n"; else cout<<-1<<"\n";} else
        if (q==1) {if (x==y) cout<<0<<"\n"; else cout<<-1<<"\n";} else
        {
            ll l=1,r=1e9;
            while (r-l>1)
            {
                ll mid=(l+r)/2;
                if (good(x,y,p*mid,q*mid)) r=mid; else l=mid;
            }
            if (good(x,y,p*l,q*l)) cout<<q*l-y<<"\n"; else
            if (good(x,y,p*r,q*r)) cout<<q*r-y<<"\n"; else cout<<-1<<"\n";
        }
    }
}