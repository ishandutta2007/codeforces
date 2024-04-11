#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
const int N = 3e5 + 11;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=0;
    ll fact=1;
    for (int i=1; i<=n; i++)
    {
        ans=(ans+a[i]*(fact-1))%MOD;
        fact=(fact*2)%MOD;
    }
    fact=1;
    for (int i=n; i>=1; i--)
    {
        ans=(((ans-a[i]*(fact-1)+MOD)%MOD)+MOD)%MOD;
        fact=(fact*2)%MOD;
    }
    cout<<ans<<endl;
}