#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,c,ans;
    cin>>n>>a>>b;
    c=0;
    ans=0;
    for (int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        if (k==1)
        {
            if (a!=0) a--; else
            if (b!=0) {b--; c++;} else
            if (c!=0) c--; else ans++;
        } else
        if (k==2)
        {
            if (b!=0) b--; else ans+=2;
        }
    }
    cout<<ans<<endl;
}