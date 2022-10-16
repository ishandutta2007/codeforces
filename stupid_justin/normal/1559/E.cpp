#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rd(x) x=read()
#define write(x) wt(x),putchar(10)
#define pos(x) (((x)-1)/SZ+1)
using namespace std;
const int N=51;
const int M=1e5+5;
const int SZ=550;
const double eps=1e-9;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void wt(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int p[M],v[M],mu[M],tot;
vector<int> P[M];
void Init(int n)
{
    mu[1]=1;
    for (int i=2;i<=n;i++)
    {
        if (!v[i]) {p[++tot]=i;mu[i]=-1;}
        for (int j=1;j<=tot && i*p[j]<=n;j++)
        {
            v[i*p[j]]=p[j];
            if (i%p[j]==0) {mu[i*p[j]]=0;break;}
            mu[i*p[j]]=-mu[i];
        }
    }
    for (int i=1;i<=n;i++) for (int j=i;j<=n;j+=i) P[j].push_back(i);
}
int n,m,ans;
int l[N],r[N];
int s[M],sum[M];
signed main()
{
    rd(n);rd(m);
    Init(m);
    for (int i=1;i<=n;i++) rd(l[i]),rd(r[i]);
    for (int i=1;i<=m;i++)
    {
        int t=m/i;
        int flag=0;
        for (int j=1;j<=n;j++)
        {
            int L=(l[j]+i-1)/i,R=r[j]/i;
            L=max(L,1LL);
            if (R==0 || L>R) {flag=1;break;}
            if (j==1) 
            {
                for (int k=1;k<=t;k++) s[k]=0;
                for (int k=L;k<=R;k++) s[k]=1;
                for (int k=2;k<=t;k++) s[k]=(s[k]+s[k-1])%mod;
            } else 
            {
                for (int k=1;k<=t;k++) sum[k]=s[max(0LL,k-L)]-s[max(0LL,k-R-1)];
                for (int k=1;k<=t;k++) s[k]=0;
                for (int k=1;k<=t;k++) s[k]=(s[k-1]+sum[k])%mod;
            }
        }
        if (flag) continue;
        int x=0;
        for (int j=0;j<=t;j++) x=(x+sum[j])%mod;
        ans=(ans+x*mu[i])%mod;
    }
    cout<<(ans+mod)%mod<<endl;
}
/*
*/