#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int mn=2000000000,num=0;
    for (int i=1;i<n;i++)
    {
        if (a[i]-a[i-1]<mn)mn=a[i]-a[i-1],num=1;
        else if (a[i]-a[i-1]==mn)num++;
    }
    cout<<mn<<' '<<num<<endl;
}