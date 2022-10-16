#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=2e5+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,l,r,L,R,ans,tmpl,tmpr;
int a[N];
int c[N][2];
bool cmp(int x,int y){return x>y;}

void solve()
{
    ans=0;tmpl=tmpr=0;
    rd(n);rd(l);rd(r);
    for (int i=1;i<=n;i++) c[i][0]=c[i][1]=0;
    for (int i=1;i<=l;i++) rd(a[i]),c[a[i]][0]++;
    for (int i=l+1;i<=n;i++) rd(a[i]),c[a[i]][1]++;
    L=R=0;
    for (int i=1;i<=n;i++)
    {
        int x=min(c[i][0],c[i][1]);
        c[i][0]-=x;c[i][1]-=x;
        tmpl+=c[i][0]/2;tmpr+=c[i][1]/2;
        L+=c[i][0];R+=c[i][1];

    }
    int x=min(L,R);
    ans+=x;L-=x;R-=x;
    if (L) ans+=max(L/2,L-tmpl);
    if (R) ans+=max(R/2,R-tmpr);
    cout<<ans<<"\n";
}
signed main()
{
    int T;cin>>T;while (T--)
    {
	solve();

    }

}