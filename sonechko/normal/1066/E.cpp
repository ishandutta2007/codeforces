#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 998244353;
#define mod %MOD

int a[N];

ll step(ll x, ll y)
{
    if (y==0) return 1;
    if (y%2==1) return (x*1ll*step(x,y-1))mod;
    ll p=step(x,y/2);
    return (p*p)mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    string t;
    cin>>t;
    s="."+s;
    t="."+t;
    for (int i=1; i<=m; i++)
    {
        a[i]=a[i-1];
        if (t[i]=='1') a[i]++;
    }
    int l=m;
    ll ans=0;
    for (int i=n; i>=1; i--)
    {
        if (l<=0) break;
        if (s[i]=='1') ans=(ans+1ll*a[l]*1ll*step(2,(n-i)))mod;
        l--;
    }
    cout<<ans<<endl;
}