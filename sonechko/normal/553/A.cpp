#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double

const int N = 1e6 + 11;
const ll MOD = 1e9 + 7;
#define mod %MOD

ll f[N],a[N];
ll step(ll p, ll d)
{
    if (d==0) return 1;
    if (d%2==1) return (p*step(p,d-1))mod;
    ll k=step(p,d/2);
    return (k*k)mod;
}
ll c(ll n, ll k)
{
    ll p=f[n];
    p=(p*step(f[k],MOD-2))mod;
    p=(p*step(f[n-k],MOD-2))mod;
    return p;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    f[0]=1;
    for (ll i=1; i<=1000000; i++)
    {
        f[i]=(f[i-1]*i)mod;
    }
    ll b=1,kol=a[1];
    for (int i=2; i<=n; i++)
    {
        kol+=a[i];
        b=(b*c(kol-1,a[i]-1))mod;
    }
    cout<<b<<endl;
}