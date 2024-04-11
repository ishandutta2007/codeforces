#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;

const int N = 100 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k,a,b;
    cin>>n>>k>>a>>b;
    ll ans=0;
    if (k==1) {cout<<(n-1)*a<<endl; return 0;}
    while (n>1)
    {
        ll g=n/k*k;
        if (g==0) {ans+=(n-1)*a; break;}
        ans+=(n-g)*a;
        n=g;
        ans+=min((n-n/k)*a,b);
        n/=k;
    }
    cout<<ans<<endl;
}