# include <iostream>
# include <cmath>
# include <stdio.h>
#include <algorithm>
using namespace std;
int a[10000];
int b[10000];
bool is[10000];
/*void print(int n)
{
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}*/
int main ()
{
    int ans=0;
    int n,m;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    for (int i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<m;x++)
        {
            if (is[x]==0 && abs(a[i]-b[x])<=1)
            {
                is[x]=1;
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
}