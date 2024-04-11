#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,aa,bb;
    cin>>n>>aa>>bb;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int ans=0;
    for (int i=1; i<=n; i++)
        if (i==n-i+1)
    {
        if (a[i]==2) ans+=min(aa,bb);
    } else
        if (a[i]==2&&a[n-i+1]==2)
    {
        ans+=min(aa,bb)*2;
        a[i]=1;
        a[n-i+1]=1;
    } else
        if (a[i]==2)
        {
            if (a[n-i+1]==0) ans+=aa; else ans+=bb;
            a[i]=a[n-i+1];
        } else
        if (a[n-i+1]==2)
        {
            if (a[i]==0) ans+=aa; else ans+=bb;
            a[n-i+1]=a[i];
        } else
        if (a[i]!=a[n-i+1]) {cout<<-1; return 0;}
    cout<<ans;
}