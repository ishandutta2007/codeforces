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
const int N=2e6+5;
const int M=2e5+5;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
void gmin(int &x,int y){x=min(x,y);}
int n,k,ans;
int a[N];
char s[N];
int p[N];
void solve(int t,int s)
{
    if (t>=n+1){ans+=s;return;}
    solve(t+1,s*(a[t]+1));
    if (t+2<=n)
    {
        bool f=a[t+2]>0;
        for (int i=t+4;i<=n;i+=2) f|=a[i]>0;
        if (f)
        {
            a[t+2]--;
            for (int i=t+2;i<=n;i+=2) if (a[i]<0) a[i]+=10,a[i+2]--;else break;
            solve(t+1,s*(9-a[t]));
            a[t+2]++;
            for (int i=t+2;i<=n;i+=2) if (a[i]>9) a[i]-=10,a[i+2]++;else break;
        }
    }
}

void DOIT()
{
    scanf("%s",s+1);n=strlen(s+1);
    reverse(s+1,s+n+1);for (int i=1;i<=n;i++) a[i]=s[i]-'0';
    ans=0;solve(1,1);
    cout<<ans-2<<"\n";
}
signed main()
{
    p[0]=1;for (int i=1;i<=12;i++) p[i]=p[i-1]*10;
    for (int i=1;i<N;i++) s[i]=s[i-1]^i;
    int JYZ;rd(JYZ);while (JYZ--) DOIT();
}