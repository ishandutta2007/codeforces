#include<bits/stdc++.h>

using namespace std;
int a[20000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    if (n%2==0 || n==1)
        cout<<-1<<endl;
    else
    {
    int ans=0;
    for (int i=n;i>=1;i-=2)
    {
        a[i]=max(a[i],0);
        ans+=max(a[i],a[i-1]);
        a[i/2]-=max(a[i],a[i-1]);
        a[i]=a[i-1]=0;
    }
        ans+=a[0];
        cout<<ans<<endl;
    }
}