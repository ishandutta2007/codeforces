#include<bits/stdc++.h>
using namespace std;
int a[200020];
int n,r=1,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        while(a[r]-a[i]<=5&&r<=n)
            r++;
        ans=max(ans,r-i);
    }
    cout<<ans<<endl;
    return 0;

}