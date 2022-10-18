#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll ans=4;
    for (int i=1; i<=n-1; i++)
        ans=(ans*2ll)%998244353;
    for (int i=1; i<=m-1; i++)
        ans=(ans*2ll)%998244353;
    cout<<ans<<endl;
}