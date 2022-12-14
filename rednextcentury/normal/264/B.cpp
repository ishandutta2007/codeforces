#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int num[1000000];
int main()
{
    int n;
    cin>>n;
    int ans=1;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        int mx=0;
        for (int j=1;j*j<=x;j++)
        {
            if (x%j) continue;
            if (j!=1)
            mx=max(mx,num[j]+1);
            if (x/j!=1)
            mx=max(mx,num[x/j]+1);
        }
        ans=max(ans,mx);
        for (int j=1;j*j<=x;j++)
        {
            if (x%j) continue;
            num[j]=max(mx,num[j]);
            num[x/j]=max(mx,num[x/j]);
        }
    }
    cout<<ans<<endl;
}