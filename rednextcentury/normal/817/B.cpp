#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long i=0,j=0,k=0;
    int l=0;
    int last=a[0];
    while(l<n && a[l]==last)i++,l++;
    last=a[l];
    while(l<n && a[l]==last)j++,l++;
    last=a[l];
    while(l<n && a[l]==last)k++,l++;
    if (i>=3)
        cout<<i*(i-1)*(i-2)/6<<endl;
    else if (i==2)
    {
        cout<<j<<endl;
    }
    else
    {
        if (j==1)
            cout<<k<<endl;
        else
            cout<<j*(j-1)/2<<endl;
    }
}