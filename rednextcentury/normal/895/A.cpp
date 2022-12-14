#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<2*n;i++)
    {
        if (i<n)
            cin>>a[i];
        else
            a[i]=a[i-n];
    }
    int ret=360;
    for (int i=0;i<n;i++)
    {
        int cur=0;
        for (int j=i;j<i+n;j++)
        {
            cur+=a[j];
            ret=min(ret,abs(cur-(360-cur)));
        }
    }
    cout<<ret<<endl;
}