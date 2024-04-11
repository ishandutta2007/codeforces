#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define pb push_back

const int N = 2e5 + 11;
vector<ll> vv;
ll a,m;
ll ans;

ll get(ll x)
{
    return (a+m-1)/x-(a-1)/x;
}

void rec(ll t, int pos, int kol)
{
    if (pos==(int)vv.size())
    {
        if (kol%2==0) ans+=get(t); else ans-=get(t);
        ///if (kol%2==0) cout<<"+"<<t<<" +"<<get(t)<<endl; else cout<<"-"<<t<<" -"<<get(t)<<endl;
        return;
    }
    rec(t*vv[pos],pos+1,kol+1);
    rec(t,pos+1,kol);
}

void up()
{
    cin>>a>>m;
    vv.clear();
    ll t=__gcd(a,m);
    ll mm=m/t;
    ll d=2;
    while (d*d<=mm)
    {
        if (mm%d==0) vv.pb(d);
        while (mm%d==0)
            mm/=d;
        d++;
    }
    if (mm>1) vv.pb(mm);
    ans=0;
    rec(t,0,0);
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}