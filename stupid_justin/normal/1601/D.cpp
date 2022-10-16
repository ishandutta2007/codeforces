
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
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}


int n,d,ans;
struct P{int s,a;}a[N];
bool cmp(P x,P y){return max(x.s,x.a)==max(y.s,y.a)?x.s<y.s:max(x.s,x.a)<max(y.s,y.a);}
signed main()
{
    rd(n);rd(d);for (int i=1;i<=n;i++) rd(a[i].s),rd(a[i].a);
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        if (a[i].s>=d) ans++,d=max(d,a[i].a);
    }
    cout<<ans<<"\n";
}
/*

*/