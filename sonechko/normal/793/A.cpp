#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define ld long double
const int N = 2e5 + 11;

ll a[N];


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll k=INT_MAX;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]<k) k=a[i];
    }
    ll ans=0;
    for (int i=1; i<=n; i++)
    if ((a[i]-k)%m!=0) {cout<<"-1"<<endl; return 0;} else
        ans+=(a[i]-k)/m;
    cout<<ans<<endl;
}