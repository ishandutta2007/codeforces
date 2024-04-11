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
#define mod %MOD


const int N = 1e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> v;
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        if (l>=r) v.pb(0); else v.pb(min(l,r-l));
        ans+=(ll)min(l,r);
    }
    sort(v.begin(),v.end());
    for (int i=1; i<=m; i++)
        ans+=(ll)v[v.size()-i];
    cout<<ans<<endl;
}