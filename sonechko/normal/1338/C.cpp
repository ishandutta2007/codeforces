#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;

ll get(ll x, ll n)
{
    ll l=x*2;
    ll r=l+x-1;
    while (l<r)
    {
        ll kol=r-l+1;
        if (n<=kol/4)
        {
            r=l+kol/4-1;
        } else
        if (n<=(kol/4)*2)
        {
            l+=(kol/4)*2;
            r=l+kol/4-1;
            n-=(kol/4);
        } else
        if (n<=(kol/4)*3)
        {
            l+=(kol/4)*3;
            r=l+kol/4-1;
            n-=(kol/4)*2;
        } else
        {
            l+=(kol/4);
            r=l+kol/4-1;
            n-=(kol/4)*3;
        }
    }
    return l;
}


void up()
{
    ll n;
    cin>>n;
    ll k=(n+2)/3;
    ll x=1;
    ll p1=0,p2=0,p3=0;
    while (1)
    {
        if (k<=x) {p1=x+k-1; p2=get(x,k); p3=(p1^p2); break;}
        k-=x;
        x*=4ll;
    }
    if (n%3==1) cout<<p1<<"\n"; else
    if (n%3==2) cout<<p2<<"\n"; else cout<<p3<<"\n";

}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
        up();
}
/**
1  - 1
4 5 6 7 - 4
16 17 .. 31 - 16
64 65 .. 127 - 64
256 257 ..
**/