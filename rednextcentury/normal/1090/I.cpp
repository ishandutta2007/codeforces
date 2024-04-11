#include <bits/stdc++.h>
long long MOD = ((1LL)<<32);
using namespace std;
unsigned long long b[10000004];
long long a[10000004];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,l,r,x,y,z,b1,b2;
        cin>>n>>l>>r>>x>>y>>z>>b1>>b2;
        b[1]=b1,b[2]=b2;
        bool neg=0,pos=0,zero=0;
        for (int i=3;i<=n;i++)
            b[i]= ((b[i-2]*x)%MOD + ((b[i-1]*y)%MOD+z)%MOD)%MOD;
        for (int i=n;i>=1;i--)
        {
            a[i] = ((b[i]%(r-l+1))+l);
            if (a[i]==0)zero=1;
        }
        long long mn = 2e9+1;
        long long ret=(4e18);
        ret++;
        long long nope = ret;
        for (int i=1;i<=n;i++)
        {
            if (mn<a[i])
                ret=min(ret,a[i]*mn);
            mn=min(mn,a[i]);
        }
        long long mx=-2e9-1;
        for (int i=n;i>=1;i--)
        {
            if (a[i]<mx)
                ret=min(ret,a[i]*mx);
            mx=max(mx,a[i]);
        }
        if (ret==nope)
            cout<<"IMPOSSIBLE"<<endl;
        else cout<<ret<<endl;
    }
}