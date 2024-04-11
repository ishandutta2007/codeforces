#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
    int n;
    cin>>n;
    if (n%2)
    {
        int l=1,r=2*(n/2);
        for (int i=2;i<=n;i+=2)
            a[l]=a[r]=i,l++,r--;
        l=2*(n/2)+1,r=l+2*(n/2);
        for (int i=1;i<=n;i+=2)
            a[l]=a[r]=i,l++,r--;
        a[2*n]=n;
    }
    else
    {
        int l=1,r=2*(n/2);
        for (int i=1;i<=n;i+=2)
            a[l]=a[r]=i,l++,r--;
        l=2*(n/2)+1,r=l+2*(n/2)-2;
        for (int i=2;i<=n;i+=2)
            a[l]=a[r]=i,l++,r--;
        a[2*n]=n;
    }
    for (int i=1;i<=n*2;i++)
        printf("%d ",a[i]);
    cout<<endl;
}