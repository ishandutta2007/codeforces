#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
long long b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n/2;i++)
    {
        cin>>b[i];
        if (i==1)
            a[i]=0,a[n-i+1]=b[i];
        else
        {
            if (a[n-i+2]>=b[i]-a[i-1])
                a[i]=a[i-1],a[n-i+1]=b[i]-a[i];
            else
                a[n-i+1]=a[n-i+2],a[i]=b[i]-a[n-i+1];
        }

    }
    for (int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
}