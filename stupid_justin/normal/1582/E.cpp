#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
int read(){int x=0,f=1;char c=getchar();while (c<'0' || c>'9') {if (c=='-') f=-1;c=getchar();}while (c>='0' && c<='9') x=x*10+c-'0',c=getchar();return x*f;}
const int N=1e5+5;
const int M=455;
int a[N],n,l,r;
int b[N];
int ans;
int s[N];
int f[N][M];//f[i][j]  i  j 
bool chk(int k)
{
    for (int i=0;i<=n;i++) for (int j=1;j<=k;j++) f[i][j]=1e18;
    for (int i=0;i<=n;i++) f[i][k+1]=0;
    for (int i=1;i<=n;i++) for (int j=1;j<=k;j++)
    {
        f[i][j]=f[i-1][j];
        if (i>=j && s[i]-s[i-j]>f[i-j][j+1]) f[i][j]=min(f[i][j],s[i]-s[i-j]);
    }
    //for (int i=1;i<=n;i++) for (int j=1;j<=k;j++) printf("f[%lld][%lld]=%lld\n",i,j,f[i][j]);
    return f[n][1]!=(1e18);
}
void DOIT()
{
    rd(n);for (int i=1;i<=n;i++) rd(a[i]);
    for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=1;ans=1;
    while ((r+1)*(r+2)/2<=n) r++;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (chk(mid)) ans=mid,l=mid+1;else r=mid-1;
    }
    cout<<ans<<"\n";
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
/*

*/