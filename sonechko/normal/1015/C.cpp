#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;

ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ll m;
    cin>>n>>m;
    vector<pair<ll,ll> > vv;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        vv.pb(mp(a[i]-b[i],i));
        m-=a[i];
    }
    sort(vv.begin(),vv.end());
    reverse(vv.begin(),vv.end());
    for (int j=0; j<vv.size(); j++)
    {
        if (m>=0) {cout<<j; return 0;}
        m+=vv[j].ff;
    }
    if (m>=0) {cout<<vv.size()<<endl; return 0;}
    cout<<-1;
}