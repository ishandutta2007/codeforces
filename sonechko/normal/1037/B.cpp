#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,s;
    cin>>n>>s;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=0;
    if (a[(n+1)/2]<s)
    {
        for (int p=(n+1)/2; p<=n; p++)
            if (a[p]<s) ans+=1ll*(s-a[p]);
    } else
    {
        for (int p=(n+1)/2; p>=1; p--)
            if (a[p]>s) ans+=1ll*(a[p]-s);
    }
    cout<<ans<<"\n";
}