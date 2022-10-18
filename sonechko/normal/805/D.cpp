#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll MOD = 1e9 + 7;
#define mod %MOD
const int N = 2e5 + 11;
ll step(ll l, ll r)
{
    if (r==0) return 1;
    if (r%2==1) return (l*(step(l,r-1)))mod;
    ll k=step(l,r/2);
    return (k*k)mod;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int kol=0;
    ll ans=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='a') kol++; else
        {
            ans=(ans+step(2,kol))mod;
            ans=(ans+MOD-1)mod;
        }
    cout<<ans<<endl;
}