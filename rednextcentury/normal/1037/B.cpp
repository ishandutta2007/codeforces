#include <bits/stdc++.h>

using namespace std;
int a[1000000];
int main()
{
    int n,s;
    cin>>n>>s;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long ret=0;
    for (int i=0;i<=n/2;i++)
    {
        if (a[i]>s)
            ret+=a[i]-s;
    }
    for (int i=n/2;i<n;i++)
    {
        if (a[i]<s)
            ret+=s-a[i];
    }
    cout<<ret<<endl;
}