#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        int t=n/k;
        n%=k;
        int ans=t*k;
        ans+=min(k/2,n);
        cout<<ans<<"\n";
    }
}