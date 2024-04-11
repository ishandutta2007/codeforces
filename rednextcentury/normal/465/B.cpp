#include <iostream>
# include <vector>
# include<algorithm>
# include <string>
using namespace std;
int a[10000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int ans=0;
    int i=0;
    while(a[i]==0 && i<n)
        i++;
    if (i<n)
        ans++;
    i++;
    for (;i<n;i++)
    {
        if (a[i]==1)
        {
        if (a[i-1]==0)
            ans+=2;
        else
            ans++;
        }
    }
    cout<<ans<<endl;
}