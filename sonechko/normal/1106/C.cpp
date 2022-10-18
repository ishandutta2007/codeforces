#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll ans=0;
    sort(a+1,a+n+1);
    for (int i=1; i<=n/2; i++)
        ans+=(a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
    cout<<ans<<endl;
}