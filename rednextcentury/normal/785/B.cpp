#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int mn1=1000000000,mx1=-1;
    int mn2=1000000000,mx2=-1;
    for (int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        mn1=min(r,mn1);
        mx1=max(mx1,l);
    }
    int m;
    cin>>m;
    for (int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        mn2=min(mn2,r);
        mx2=max(mx2,l);
    }
    int ans=0;
    ans=max(ans,max(mx2-mn1,mx1-mn2));
    cout<<ans<<endl;
}