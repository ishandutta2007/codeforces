#include <bits/stdc++.h>
using namespace std;
int a[1000000];
bool vis[1000000];
int ans[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (vis[a[i]-1]) ans[a[i]]=ans[a[i]-1]+1;
        else ans[a[i]]=1;
        vis[a[i]]=1;
    }
    int mx=0;
    for (int i=1;i<=n;i++)
        mx=max(mx,ans[i]);
    cout<<n-mx<<endl;
}