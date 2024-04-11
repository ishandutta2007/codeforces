
#include<bits/stdc++.h>
#define rd(x) x=read()
#define wt(x) write(x)
using namespace std;
const int N=3e3+5;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int n,m;
int a[N],b[N];
int f[N][N];
int la[N],nxt[N];
void DOIT()
{
    rd(n);for (int i=1;i<=n;i++) rd(a[i]);
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) f[i][j]=0;
    for (int i=1;i<=n;i++) la[i]=n+1;
    for (int i=n;i>=1;i--) nxt[i]=la[a[i]],la[a[i]]=i;
    for (int len=2;len<=n;len++) for (int l=1;l+len-1<=n;l++)
    {
        int r=l+len-1;
        f[l][r]=f[l+1][r];
        for (int i=nxt[l];i<=r;i=nxt[i]) f[l][r]=max(f[l][r],f[l+1][i-1]+f[i][r]+1);
    }
    cout<<n-1-f[1][n]<<endl;
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
/*

*/