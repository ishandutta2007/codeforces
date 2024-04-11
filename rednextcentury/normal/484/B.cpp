#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[1000000];
int b[1000000];
int cur[3000000];
int main()
{
    int m;
    cin>>m;
    for (int i=0;i<m;i++)
        cin>>b[i];
    sort(b,b+m);
    int n=1;
    a[0]=b[0];
    for (int i=1;i<m;i++)
    {
        if (b[i]!=b[i-1])
            a[n++]=b[i];
    }
    int j=0;
    for (int i=1;i<=2000000;i++)
    {
        while(j<n && a[j]<i)
            j++;
        if (j==n)
            j--;
        if (a[j]>=i && j>0)
            j--;
        if (a[j]<i)
            cur[i]=a[j];
        else
            cur[i]=-1;
    }
    int ans=0;
    for (int i=0;i<n;i++)
    {
        int j=1;
        int o=2*a[i];
        while(o<=2000000)
        {
            j++;
            ans=max(ans,cur[o]%a[i]);
            o+=a[i];
        }
    }
    cout<<ans<<endl;
}