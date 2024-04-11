#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        a[n+i]=a[i];
        a[n+n+i]=a[i];
    }
    int kol=0,ans=0;
    for (int i=1; i<=n*3; i++)
    {
        if (a[i]==1) kol++; else kol=0;
        ans=max(ans,kol);
    }
    cout<<ans<<endl;
}