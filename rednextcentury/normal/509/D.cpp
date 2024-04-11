#include<bits/stdc++.h>
using namespace std;
long long a[1001][1001];
long long b[1001][1001];
long long r[1001];
long long c[1001];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    r[0]=0;
    for (int i=0;i<m;i++)
        c[i]=a[0][i];
    for (int i=1;i<n;i++)
        r[i] = a[i][0]-c[0];
    long long g = -1;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            b[i][j] = abs(a[i][j]-r[i]-c[j]);
            if (b[i][j]!=0)
            {
                if (g==-1)
                    g=b[i][j];
                else
                    g = __gcd(g,b[i][j]);
            }
        }
    }
    long long mod;
    if (g==-1)
        mod = 1000000000000000000LL;
    else
    {
        mod = g;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if (a[i][j]>=mod)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        while(r[i]<0)
            r[i]+=mod;
    }
    cout<<"YES"<<endl;
    cout<<mod<<endl;
    for (int i=0;i<n;i++)
        cout<<r[i]<<' ';
    cout<<endl;
    for (int i=0;i<m;i++)
        cout<<c[i]<<' ';
}