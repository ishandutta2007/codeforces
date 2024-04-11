#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define endl "\n"
#define int long long
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define y1 _
#define pii pair<int,int> 
#define mp make_pair
using namespace std;
const int N=1e6+5;
const int M=25;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
const double eps=1e-10;
const double pi=acos(-1);
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,m;
double len[N],t[N];
struct seg{double l,r;}S[N];
int x[N],y[N];
int f[N][M];
double L,R=1e9;
bool cmp(seg a,seg b){return a.l<b.l;}
bool chk(double x)
{
    if (x<1e-9) return 1;
    for (int i=1;i<=n;i++) 
    {
        S[i].l=t[i]-acos(x/len[i]);
        S[i].r=t[i]+acos(x/len[i]);
        if (S[i].l<0) S[i].l+=2*pi,S[i].r+=2*pi;
        S[i+n].l=S[i].l+2*pi;S[i+n].r=S[i].r+2*pi;
    }

    sort(S+1,S+2*n+1,cmp);
    f[2*n+1][0]=2*n+1;int r=2*n;
    for (int i=2*n;i>=1;i--) {while (S[r].l>S[i].r) r--;f[i][0]=r+1;}
    for (int i=1;i<M;i++) for (int j=1;j<=2*n+1;j++) f[j][i]=f[f[j][i-1]][i-1];
    for (int i=1;i<=n;i++) 
    {
        int pos=i;
        for (int j=0;j<M;j++) if (m>>j&1) pos=f[pos][j];
        if (pos>=i+n) return 1;
    }
    return 0;
    

}
bool v[N];
int tot;

signed main()
{
    rd(n);rd(m);for (int i=1;i<=n;i++) rd(x[i]),rd(y[i]),len[i]=sqrt(x[i]*x[i]+y[i]*y[i]),R=min(R,len[i]);
    for (int i=1;i<=n;i++) {if (x[i]==0 && y[i]==0) {puts("0");return 0;}}
    for (int i=1;i<=n;i++)
    {
        if (x[i]==0 && y[i]>0) t[i]=pi/2;
        if (x[i]==0 && y[i]<0) t[i]=pi*3/2;
        if (y[i]==0 && x[i]>0) t[i]=0;
        if (y[i]==0 && x[i]<0) t[i]=pi;
        if (x[i]>0 && y[i]>0) t[i]=acos(x[i]/len[i]);
        if (x[i]<0 && y[i]>0) t[i]=pi-acos(-x[i]/len[i]);
        if (x[i]<0 && y[i]<0) t[i]=pi+acos(-x[i]/len[i]);
        if (x[i]>0 && y[i]<0) t[i]=pi*2-acos(x[i]/len[i]);
    }
    L=0;
    while (R-L>=eps)
    {
        double mid=(R+L)/2;
        if (chk(mid)) L=mid;else R=mid;
    }
    printf("%.8lf\n",L);

    
}
/*


*/