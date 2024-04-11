#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define wt(x) write(x)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=1e6+5;
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
int n,m,k,ans;
int a[N],b[N];
bool v[N];
vector<int> tmp;
void DOIT()
{
    memset(v,0,sizeof(v));tmp.clear();
    rd(n);rd(k);
    for (int i=1;i<=k;i++) rd(a[i]),rd(b[i]),v[a[i]]=v[b[i]]=1;
    for (int i=1;i<=2*n;i++) if (!v[i]) tmp.push_back(i);
    m=tmp.size();
    for (int i=0,j=m/2;i<m/2;i++,j++) a[++k]=tmp[i],b[k]=tmp[j];
    for (int i=1;i<=k;i++) if (a[i]>b[i]) swap(a[i],b[i]);
    ans=0;
    for (int i=1;i<=k;i++) for(int j=1;j<=k;j++) if (i!=j && a[i]<a[j] && a[j]<b[i] && !(a[i]<b[j] && b[j]<b[i])) ans++;
    cout<<ans<<endl;
}
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}
/*

*/