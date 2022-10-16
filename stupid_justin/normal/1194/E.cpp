#include<bits/stdc++.h>
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
const int N=5005;
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

int n,k,m;
long long ans;
struct seg1{int l,r,h;};
struct seg2{int d,u,x;};
seg1 S1[N];int cnt1;
seg2 S2[N];int cnt2;
int H[N][N];
bitset<N> B[N];
signed main()
{
    rd(n);
    for (int i=1;i<=n;i++)
    {
        int a,b,c,d;
        rd(a);rd(b);rd(c);rd(d);
        if (a>c) swap(a,c);if (b>d) swap(b,d);
        if (b==d) S1[cnt1++]=((seg1){a,c,b});else 
        S2[cnt2++]=((seg2){b,d,a});
    }
    for (int i=0;i<cnt1;i++) for (int j=0;j<cnt2;j++) 
    {
        seg1 a=S1[i];seg2 b=S2[j];
        if (b.d<=a.h && a.h<=b.u && a.l<=b.x && b.x<=a.r) 
        {
            if (cnt1>=cnt2) B[j].set(i);
            else B[i].set(j);
        }
    }
    n=min(cnt1,cnt2);
    for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) 
    {
        int x=(B[i]&B[j]).count();
        //cout<<"i="<<i<<" j="<<j<<" x="<<x<<endl;
        ans+=x*(x-1)/2;
    }
    cout<<ans<<endl;



}
/*
*/