#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    int ans=0;
    for (ll i=1; i<=(ll)sqrt(n); i++)
        if (n%i==0)
    {
        ll c=n/i;
        ll d=i;
        if (c!=d) ans+=2; else ans++;
    }
    cout<<ans<<endl;
}