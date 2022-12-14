#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int mod=998244353;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++)
        cin>>a[i];
    int ret=0;
    int l=0,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int num=m;
        int cur=0;
        for (int i=mid;i<n;i++)
        {
            if (cur+a[i]>k)
            {
                num--;
                cur=a[i];
            }
            else
                cur+=a[i];
        }
        if (cur)num--;
        if (num>=0)
            ret=mid,r=mid-1;
        else
            l=mid+1;
    }
    cout<<n-ret<<endl;
}