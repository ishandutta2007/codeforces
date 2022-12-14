#include <bits/stdc++.h>
using namespace std;
int suf[1000000];
long long p[1000000];
int mod=998244353;
int main()
{
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for (int i=m-1;i>=0;i--)
        suf[i]=(b[i]=='1')+suf[i+1];
    long long ret=0;
    p[0]=1;
    for (int i=1;i<=n;i++)p[i]=(p[i-1]*2)%mod;
    for (int i=0;i<n;i++)
    {
        if (a[i]=='1')
            ret+=(p[i]*suf[i])%mod;
        ret%=mod;
    }
    cout<<ret<<endl;
}