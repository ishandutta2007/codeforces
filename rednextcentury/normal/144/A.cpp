#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int mn=1000000,mx=0,p1=0,p2=0;
    for (int i=0;i<n;i++)
    {
        if (a[i]<=mn)
            mn=a[i],p2=i;
        if (a[i]>mx)
            mx=a[i],p1=i;
    }
    int ans=0;
    if (p1>p2)ans--;
    ans+=p1+n-1-p2;
    cout<<ans<<endl;
}