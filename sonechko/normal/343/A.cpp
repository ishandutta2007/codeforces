#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    while (n>0&&m>0)
    {
        if (n<m) {ans+=m/n; m%=n;} else {ans+=n/m; n%=m;}
    }
    cout<<ans<<endl;
}