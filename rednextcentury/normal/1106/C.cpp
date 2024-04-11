#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long ret=0;
    for (int i=0;i<n/2;i++)
    {
        long long x = a[i]+a[n-i-1];
        ret+=x*x;
    }
    cout<<ret<<endl;
}