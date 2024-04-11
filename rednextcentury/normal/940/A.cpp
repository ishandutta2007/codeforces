#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    int n,d;
    cin>>n>>d;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ret=1000000;
    sort(a,a+n);
    for (int i=0;i<n;i++)
    {
        for (int j=i;j<n;j++)
        {
            if (a[j]-a[i]<=d)
            {
                ret=min(ret,i+(n-j-1));
            }
        }
    }
    cout<<ret<<endl;
}