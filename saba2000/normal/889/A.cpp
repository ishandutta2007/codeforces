#include<bits/stdc++.h>
using namespace std;
int f[1000009];
main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {int a;
        cin>>a;
        f[a]=1;
    }
    int ans=0;
    for (int i=0; i<=n; i++)
        if(f[i]==0) ans++;
    cout<<ans<<endl;
}