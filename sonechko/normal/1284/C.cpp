#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 3e5 + 11;

ll fac[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll ans=0;
    fac[0]=1;
    for (int i=1; i<=n; i++)
        fac[i]=(fac[i-1]*1ll*i)%m;
    for (int i=1; i<=n; i++)
    {
        ll p1=fac[n-i+1];
        ll p2=fac[i];
        ll p3=n-i+1;
        ll t=(p1*p2)%m;
        t=(t*p3)%m;
        ans=(ans+t)%m;
    }
    cout<<ans;
}
/**

l..r : (n-(r-l))!*(r-l+1)!

**/