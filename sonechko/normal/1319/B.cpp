#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 4e5 + 11;

map<ll,ll> mt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        ll x;
        cin>>x;
        mt[i-x]+=x;
        ans=max(ans,mt[i-x]);
    }
    cout<<ans;
}