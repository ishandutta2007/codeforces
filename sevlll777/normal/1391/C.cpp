#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define inf 1000000000

ll fact(ll n)
{
    ll i,p=1;
    for(i=1;i<=n;i++)
        p=(p*i)%mod;
    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,i,p,ans;
    cin>>n;
    
    p=1;
    for(i=1;i<=n-1;i++)
        p=(p*2)%mod;
    
    ans=(fact(n)-p+mod)%mod;
    cout<<ans<<endl;
    
    return 0;
}