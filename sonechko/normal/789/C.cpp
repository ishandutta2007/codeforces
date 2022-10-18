#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ld long double
const int N = 2e5 + 11;
ll a[N],b[N],c[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=2; i<=n; i++)
    if (i%2==1) {b[i]=b[i-1]+abs(a[i]-a[i-1]); c[i]=c[i-1]-abs(a[i]-a[i-1]);} else
        {
            b[i]=b[i-1]-abs(a[i]-a[i-1]); c[i]=c[i-1]+abs(a[i]-a[i-1]);
        }
    ll INF=100000000000000000;
    ll ans=-INF,k1=0,k2=INF;
    for (int i=2; i<=n; i++)
    {
        ans=max(ans,c[i]-k1);
        ans=max(ans,b[i]-k2);
        if (i%2==1) k1=min(k1,c[i]);
        if (i%2==0) k2=min(k2,b[i]);
    }
    cout<<ans<<endl;
}