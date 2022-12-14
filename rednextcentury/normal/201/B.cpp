#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
long long a[10000];
long long b[10000];
int main()
{
    fast
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            a[i]+=x;
            b[j]+=x;
        }
    }
    long long mn;
    int bx=-1;
    mn=(1LL<<60);
    for (int x=0;x<=n;x++)
    {
        long long cur=0;
        for (int i=0;i<n;i++)
        {
            if (i<x)
                cur+=a[i]*((x-i-1)*4+2)*((x-i-1)*4+2);
            else
                cur+=a[i]*((i-x)*4+2)*((i-x)*4+2);
        }
        if (cur<mn)
            mn=cur,bx=x;
    }
    long long ans=mn;
    mn=(1LL<<60);
    int by=-1;
    for (int x=0;x<=m;x++)
    {
        long long cur=0;
        for (int i=0;i<m;i++)
        {
            if (i<x)
                cur+=b[i]*((x-i-1)*4+2)*((x-i-1)*4+2);
            else
                cur+=b[i]*((i-x)*4+2)*((i-x)*4+2);
        }
        if (cur<mn)
            mn=cur,by=x;
    }
    ans+=mn;
    cout<<ans<<endl<<bx<<' '<<by<<endl;
}