#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double

const int N = 2e5 + 11;
const int MAX = -2e18;

ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n*2; i++)
        cin>>a[i];
    sort(a+1,a+n*2+1);
    ll ans=(a[n]-a[1])*(a[n*2]-a[n+1]);
    for (int i=1; i<=n; i++)
        ans=min(ans,(a[n+i-1]-a[i])*1ll*(a[n*2]-a[1]));
    cout<<ans<<endl;
}
/**

**/