#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
#define endl "\n"
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ls (rt<<1)
#define rs (rt<<1|1)
#define y1 ______________________________
using namespace std;
const int N=4e5+5;
const int M=70;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (int i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m<0 || m>n) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
void add(int &x,int y) {x+=y;if (x>=mod) x-=mod;}


int n,m,pos,ans;
char s[N],str[N];
int a[N],L[N],R[N],f[N];
int p(int x,int y){return x*m-m+y;}
void dfs1(int x,int y,int k)
{
	if(L[p(x,y)]!=-1) return;L[p(x,y)]=k;
	if(x<n) dfs1(x+1,y,k);
	if(x>1 && s[p(x-1,y)]=='#') dfs1(x-1,y,k);
	if(y>1 && s[p(x,y-1)]=='#') dfs1(x,y-1,k);
	if(y<m && s[p(x,y+1)]=='#') dfs1(x,y+1,k);
}
void dfs2(int x,int y,int k)
{
	if(R[p(x,y)]!=-1) return;R[p(x,y)]=k;
	if(x<n) dfs2(x+1,y,k);
	if(x>1 && s[p(x-1,y)]=='#') dfs2(x-1,y,k);
	if(y>1 && s[p(x,y-1)]=='#') dfs2(x,y-1,k);
	if(y<m && s[p(x,y+1)]=='#') dfs2(x,y+1,k);
}
signed main()
{
    rd(n);rd(m);
    for (int i=1;i<=n;i++) {scanf("%s",str+1);for (int j=1;j<=m;j++) s[p(i,j)]=str[j];}
    for (int i=1;i<=m;i++) rd(a[i]);
    memset(L,-1,sizeof(L));memset(R,-1,sizeof(R));
    for (int j=1;j<=m;j++) for (int i=1;i<=n;i++) if (s[p(i,j)]=='#') dfs1(i,j,j);
    for (int j=m;j>=1;j--) for (int i=1;i<=n;i++) if (s[p(i,j)]=='#') dfs2(i,j,j);
    for (int i=1;i<=m+2;i++) f[i]=m+2;
    for (int j=1;j<=m;j++) if (a[j]) for (int i=n;i>=1;i--) if (s[p(i,j)]=='#')
    {
        a[j]--;if (a[j]==0) {f[L[p(i,j)]]=min(f[L[p(i,j)]],R[p(i,j)]+1);break;}
    }
    for (int i=m+1;i>=1;i--) f[i]=min(f[i],f[i+1]);pos=1;
    //for (int i=1;i<=m+1;i++) cout<<f[i]<<" ";cout<<endl;
    while (pos<m+2) pos=f[pos],ans++;
    cout<<ans-1<<endl;
    
}
/*
*/