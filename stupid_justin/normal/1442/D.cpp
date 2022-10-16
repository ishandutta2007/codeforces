
#include<bits/stdc++.h>
#define int long long
#pragma GCC optize("Ofast")
#pragma GCC optize("unroll-loops")
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
#define y1 _________
using namespace std;
const int N=3000+5;
const int M=20;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int n,k,m[N],y,s[N],f[N*4][N];
void solve(int x,int l,int r)
{
    if (l==r) {rd(m[l]);for (int i=1,y;i<=m[l];i++) {rd(y),s[l]+=y;if (i<=k) f[x][i]=s[l];}return;}
    int mid=(l+r)/2;solve(x*2,l,mid);solve(x*2+1,mid+1,r);
    for (int i=mid+1;i<=r;i++) for (int j=k-m[i];j>=0;j--) f[x*2][j+m[i]]=max(f[x*2][j+m[i]],f[x*2][j]+s[i]);
    for (int i=l;i<=mid;i++) for (int j=k-m[i];j>=0;j--)f[x*2+1][j+m[i]]=max(f[x*2+1][j+m[i]],f[x*2+1][j]+s[i]);
    for (int i=0;i<=k;i++)f[x][i]=max(f[x*2][i],f[x*2+1][i]);
}
signed main(){rd(n);rd(k);solve(1,1,n);cout<<f[1][k]<<"\n";}