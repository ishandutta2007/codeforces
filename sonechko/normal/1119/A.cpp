#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 11;

int a[N],last[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        last[a[i]]=i;
    }
    int ans=0;
    for (int i=1; i<=n; i++)
        if (a[i]!=a[1]) ans=max(ans,i-1);
    for (int i=1; i<=n; i++)
        if (a[i]!=a[n]) ans=max(ans,n-i);
    cout<<ans<<endl;
}