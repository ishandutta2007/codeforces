#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 2e5 + 11;

ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,w;
    cin>>n>>w;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll xx=0;
    ll mini=0,maxi=0;
    for (int i=1; i<=n; i++)
    {
        xx+=a[i];
        mini=min(mini,xx);
        maxi=max(maxi,xx);
    }
    ll p_min=-mini;
    ll p_max=w-maxi;
    cout<<max(0ll,p_max-p_min+1)<<endl;
}