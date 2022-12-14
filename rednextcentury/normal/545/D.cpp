#include <bits/stdc++.h>
using namespace std;
long long a[100001];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long sum=0;
    int ans=0;
    for (int i=0;i<n;i++)
    {
        if (sum>a[i])
            ans++;
        else
        sum+=a[i];
    }
    cout<<n-ans<<endl;
}