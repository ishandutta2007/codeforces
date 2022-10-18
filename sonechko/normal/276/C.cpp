#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 11;
ll a[N],b[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=m; i++)
    {
        int l,r;
        cin>>l>>r;
        b[l]++;
        b[r+1]--;
    }
    for (int i=1; i<=n; i++)
    b[i]=b[i-1]+b[i];
    sort(b+1,b+n+1);
    ll ans=0;
    for (int i=1; i<=n; i++)
        ans+=a[i]*b[i];
    cout<<ans<<endl;
}