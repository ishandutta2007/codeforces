#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    m=240-m;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (m>=i*5)
            m-=i*5,ans++;
    }
    cout<<ans<<endl;
}