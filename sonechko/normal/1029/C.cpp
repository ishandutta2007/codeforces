#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 11;

int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int mx1=-2e9,mx2=-2e9,mn1=2e9,mn2=2e9;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        if (a[i]>mx1) {mx2=mx1; mx1=a[i];} else
        if (a[i]>mx2) mx2=a[i];

        if (b[i]<mn1) {mn2=mn1; mn1=b[i];} else
        if (b[i]<mn2) mn2=b[i];
    }
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int p1=mx1,p2=mn1;
        if (a[i]==mx1) p1=mx2;
        if (b[i]==mn1) p2=mn2;
        ans=max(ans,p2-p1);
    }
    cout<<ans<<"\n";
}