#include<iostream>
using namespace std;
int main()
{
    int n,ans;
    cin>>n;
    int a[100],p=1,q=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>a[p]) p=i;
        if(a[i]<=a[q]) q=i;
    }
    if(p>q) ans=n+p-q-2;
    else ans=n+p-q-1;
    cout<<ans<<endl;
    return 0;
}