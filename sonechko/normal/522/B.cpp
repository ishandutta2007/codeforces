#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 11;

int a[N],b[N],c[N],d[N],e[N],f[N];

int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i]>>b[i];
    for (int i=1; i<=n; i++)
    {
        c[i]=c[i-1]+a[i];
        d[i]=max(d[i-1],b[i]);
    }
    for (int i=n; i>=1; i--)
    {
        e[i]=e[i+1]+a[i];
        f[i]=max(f[i+1],b[i]);
    }
    for (int i=1; i<=n; i++)
        cout<<(c[i-1]+e[i+1])*max(d[i-1],f[i+1])<<" ";
    cout<<endl;
}