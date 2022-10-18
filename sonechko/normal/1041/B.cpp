#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

ll gcd(ll a, ll b)
{
    while (a>0&&b>0)
        if (a>b) a%=b; else b%=a;
    return a+b;
}
ll n,m,x,y;

bool good(ll d)
{
    if (n/d+2<=x) return false;
    if (m/d+2<=y) return false;
    //cout<<d<<" - "<<x*d<<"<="<<n<<" "<<y*d<<"<="<<m<<endl;
    if (x*d<=n&&y*d<=m) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>x>>y;
    ll d=gcd(x,y);
    x/=d;
    y/=d;
    ll l=0,r=1e18;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        if (good(mid)) l=mid; else r=mid;
    }
    if (good(r)) cout<<r<<endl; else cout<<l<<endl;
}