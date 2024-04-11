
#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define p(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 _________
using namespace std;
const int N=85;
const int M=70;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int f[N][N*N][N];
int n,ans,m;
int x[N],c[2],p[N];
void gmin(int &x,int y){x=min(x,y);}
signed main()
{
    rd(n);m=n*(n-1)/2;for(int i=1;i<=n;i++) {rd(x[i]),c[x[i]]++;if (x[i])p[c[1]]=i;}
    ans=c[0]*(c[0]-1)/2;for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) for (int k=0;k<=n;k++) f[i][j][k]=inf;
    if(!c[0]) {for(int i=0;i<=m;i++) cout<<"0 ";return 0;}
    for (int i=1;i<=n;i++) f[i][abs(p[1]-i)][1]=(i-1)*(i-2)/2;
    for(int i=1;i<=n;i++) for(int j=0;j<=m;j++) for(int k=1;k<=i && k<c[1];k++) for(int t=i+1;t<=n-c[1]+k+1;t++)
    if(j+abs(p[k+1]-t)<=m) gmin(f[t][j+abs(p[k+1]-t)][k+1],f[i][j][k]+(t-i-1)*(t-i-2)/2); 
    for(int j=0;j<=n*(n-1)/2;j++){for(int i=c[1];i<=n;i++) gmin(ans,f[i][j][c[1]]+(n-i)*(n-i-1)/2);cout<<c[0]*(c[0]-1)/2-ans<<" ";}
}