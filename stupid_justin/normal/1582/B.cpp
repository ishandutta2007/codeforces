#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
int read(){int x=0,f=1;char c=getchar();while (c<'0' || c>'9') {if (c=='-') f=-1;c=getchar();}while (c>='0' && c<='9') x=x*10+c-'0',c=getchar();return x*f;}
const int N=1e6+5;
int a[N],n;
int one,zero;
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--)
    {
        rd(n);for (int i=1;i<=n;i++) rd(a[i]);zero=one=0;
        for (int i=1;i<=n;i++) if (a[i]==0) zero++;else if (a[i]==1) one++;
        cout<<one*(1LL<<zero)<<"\n";
    }

}
/*

*/