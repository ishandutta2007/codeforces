#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1e6 + 11;
ll a[N];
ll dp1[N],dp2[N],dp3[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ll x,y,z;
    cin>>n>>x>>y>>z;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    dp1[1]=a[1]*x;
    for (int i=2; i<=n; i++)
        dp1[i]=max(dp1[i-1],a[i]*x);
    dp2[1]=a[1]*x+a[1]*y;
    for (int i=2; i<=n; i++)
        dp2[i]=max(dp2[i-1],a[i]*y+dp1[i]);
    dp3[1]=a[1]*x+a[1]*y+a[1]*z;
    for (int i=2; i<=n; i++)
        dp3[i]=max(dp3[i-1],a[i]*z+dp2[i]);
    cout<<dp3[n]<<endl;
}