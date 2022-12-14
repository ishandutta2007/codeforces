#include <bits/stdc++.h>
using namespace std;
long long a[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    long long s=0,mx=0;
    for (int i=0;i<n;i++)
        cin>>a[i],s+=a[i],mx=max(mx,a[i]);
    long long ret=max(mx,(s/(n-1))+(s%(n-1)>0));
    cout<<ret<<endl;
}