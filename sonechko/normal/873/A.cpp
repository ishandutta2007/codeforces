#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 2e5 + 11;
int a[N];
int main()
{
    int n,k,x;
    cin>>n>>k>>x;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=0;
    for (int i=1; i<=n-k; i++)
        ans+=a[i];
    for (int i=n-k+1; i<=n; i++)
        ans+=min(x,a[i]);
    cout<<ans<<endl;
}