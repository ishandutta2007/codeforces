
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
#define y1 _________
using namespace std;
const int N=300+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
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
struct P{int a,b,s;}p[N*N];
int a[N][N];
bool cmp(P x,P y){return x.a==y.a?x.b<y.b:x.a<y.a;}
bool cmp2(P x,P y){return x.b<y.b;}
struct treearray
{
    int a[N],n;
    void clear(int m){n=m;for (int i=0;i<=n;i++) a[i]=0;}
    void add(int i,int x){for (;i<=n;i+=i&-i) a[i]+=x;}
    int query(int i){int ret=0;for (;i;i^=i&-i) ret+=a[i];return ret;}
    int operator[](int x) {return query(x);}
}T[N];
signed main()
{
    int JYZ;rd(JYZ);while (JYZ--)
    {
        rd(n);rd(m);ans=0;
        for (int i=1;i<=n*m;i++) rd(p[i].a),p[i].b=i;
        sort(p+1,p+n*m+1,cmp);
        for (int i=1;i<=n*m;i++) p[i].s=i;
        for (int i=1;i<=n;i++) T[i].clear(m+1);
        sort(p+1,p+n*m+1,cmp2);
        for (int i=1;i<=n*m;i++) 
        {
            int s=p[i].s;
            int r=(s-1)/m+1,h=(s-1)%m+1;
            a[r][h]=p[i].a;
            ans+=T[r][h];
            T[r].add(h,1);
        }
        for (int i=1;i<=n;i++)
        {
            int la=0,len=0;a[i][m+1]=-1;
            for (int j=1;j<=m+1;j++)
            {
                if (a[i][j]!=la) 
                {
                    ans-=(len-1)*len/2;
                    len=1;la=a[i][j];
                } else len++;
            }
        }
        cout<<ans<<endl;
    }
}