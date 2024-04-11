#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll m=n;
    vector<ll> p;
    ll d=2;
    while (d*d<=n)
    {
        if (n%d==0) {n/=d;p.pb(d);} else d++;
    }
    if (n>1) p.pb(n);
    ll ans=m;
    for (int j=0; j<p.size(); j++)
    {
        m/=p[j];
        ans+=m;
    }
    cout<<ans<<endl;
}