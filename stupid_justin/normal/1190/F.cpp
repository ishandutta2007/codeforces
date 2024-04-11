#include<bits/stdc++.h>
#define int __int128
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=3e6+5;
const int M=5e7+5;
const int SZ=550;
const double eps=1e-9;
const int mod=19491001;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)wt(x/10);putchar(x%10+'0');}
int ksm(__int128 x,int y=mod-2,int z=mod){x%=z;__int128 ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int p[N],v[N],tot;
void Init(int n)
{
    for (int i=2;i<=n;i++) 
    {
        if (!v[i]) p[++tot]=i,v[i]=i;
        for (int j=1;j<=tot && i*p[j]<=n;j++) 
        {
            v[i*p[j]]=p[j];
            if (i%p[j]==0) break;
        }
    }
}
bool MR(int n)//
{
    if (n<N) return v[n]!=n;
    int m=n-1,x,y,r=m,t=0;
    while ((r&1)^1) r>>=1,t++;
    for (int i=1;i<=10;i++)
    {
        x=ksm(p[i],r,n);
        for (int j=0;j<t && x>1;j++)
        {
            y=x*x%n;
            if (y==1 && x!=m) return 1;
            x=y;
        }
        if (x!=1) return 1;
    }
    return 0;
}
int PR(int n)
{
    int s=0,t=0,c=rand()%(n-1)+1,w=1;
    for (int i=1;;i<<=1,s=t,w=1)
    {
        for (int j=0;j<i;j++)
        {
            t=(t*t+c)%n;
            if (t-s>0) w=w*(t-s)%n;else w=w*(s-t)%n;
            if (!(j&127))
            {
                int g=__gcd(w,n);
                if (g>1) return g; 
            }
        }
        int g=__gcd(w,n);
        if (g>1) return g;
    }
}
int n,k,m,P,t,cnt,flag,g,phi,order;
void getP(int x)
{
    for (int i=1;i<=tot;i++) if (x%p[i]==0)
    {
        P=p[i];
        while (x!=1){x/=P;t++;}
        return;
    }
    P=sqrt(x*1.0);if (P*P==x) {t=2;return;}
    P++;if (P*P==x) {t=2;return;}
    P-=2;if (P*P==x) {t=2;return;}
    P=x;t=1;
}
bitset<M> vis;
int Prim[N],sz;
set<int> S;
void solve(int x)
{
    //
    if (x==1) return;
    if (x<=N) {while (x!=1) S.insert(v[x]),x/=v[x];return;}
    if (!MR(x)) {S.insert(x);return;}
    int y=PR(x);solve(y);solve(x/y);
}
int ord(int x)
{
    for (int i=1;i<=sz;i++) 
    {
        if (ksm(x,phi/Prim[i],m)==1)
        {
            return phi/Prim[i];
        }
    }
    return phi;
}
signed main()
{
    unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 rand(seed);
    Init(N-1);
    rd(n);rd(m);rd(k);getP(m);
    phi=m/P*(P-1);
    if (phi<n) {puts("-1");return 0;}
    if (k%P==0 && phi-1<n) {puts("-1");return 0;}
    if (k%P==0) for (int i=2;i<m;i++) {if (i%P!=0) {cnt++;wt(i);putchar(' ');if (cnt==n) return 0;}}
    if (m<=5e7) 
    {
        int x=1;
        while (!vis[x]) vis[x]=1,x=x*k%m;
        for (int i=0;i<m;i+=P) vis[i]=1;
        for (int i=0;i<m;i++) if (!vis[i]) cnt++;
        if (cnt<n) {puts("-1");return 0;}
        cnt=0;
        for (int i=0;i<m;i++) if (!vis[i]) {wt(i);putchar(' ');cnt++;if (cnt==n) return 0;}
    }
    solve(phi);
    for (int x:S) Prim[++sz]=x;
    order=ord(k);
    if (order==phi) {puts("-1");return 0;}
    if (P>2) 
    {
        while (1) {g=rand()%m;if (ord(g)==phi) break;}
        int v=phi/order,x=1;
        for (int i=1;i<m;i++)
        {
            x=x*g%m;
            if (i%v!=0 && x%P!=0) {wt(x);putchar(' ');cnt++;if (cnt==n) return 0;}
        }
    } else 
    {
        g=5;
        if (k%4==1) {for (int i=3;i<m;i+=4) {wt(i);putchar(' ');cnt++;if (cnt==n) return 0;}}
        k=k*k%m;
        int v=phi/ord(k),x=1;
        for (int i=1;i<m;i++)
        {
            x=x*g%m;
            if (i%v!=0 && x%P!=0) {wt(x);putchar(' ');cnt++;if (cnt==n) return 0;}
        }

    }
    
}
/*
*/