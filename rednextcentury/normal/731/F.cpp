#include <bits/stdc++.h>
using namespace std;
int a[1000000];
long long b[2000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i],b[a[i]]++;
    for (int i=200000-1;i>=1;i--)
        b[i]+=b[i+1];
    long long ret=0;
    sort(a,a+n);
    for (int i=0;i<n;i++)
    {
        if (i==0 || (i>0 && a[i-1]!=a[i]))
        {
            long long cur=0;
            for (int j=a[i];j<=200000;j+=a[i])
                cur+=j*(b[j]-b[j+a[i]]);
            ret=max(ret,cur);
        }
    }
    cout<<ret<<endl;
}