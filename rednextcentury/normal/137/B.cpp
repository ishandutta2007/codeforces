# include <algorithm>
# include <iostream>
using namespace std;
int a[10000];
int main ()
{
    long long n,ans=0;
    cin>>n;
    for (int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    
    for (int i=1;i<=n;i++)
    {
        bool p=0;
        for (int x=0;x<n;x++)
        {
        if (a[x]==i)
        {
        p=1;
        break;
        }
        
        
        }
        if (p==0)
            ans++;
    
    }
    cout<<ans<<endl;
}