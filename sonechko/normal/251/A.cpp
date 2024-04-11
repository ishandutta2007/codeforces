#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N = 1e5 + 11;

int a[N];

int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int k=1;
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        while (k<n&&a[k+1]-a[i]<=m)
            k++;
        ll p=k-i-1;
        ans+=p*(p+1)/2;
    }
    cout<<ans<<endl;
}