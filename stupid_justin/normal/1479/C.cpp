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
const int N=50+5;
const int M=70;
const int SZ=450;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int L,R,n;
struct edge{int u,v,w;};
vector<edge> ans;
int E[N][N];
void add(int u,int v,int w=1)
{
    if (w==0) w=1;
    if (!E[u][v]) E[u][v]=w,ans.push_back({u,v,w});
}
void solve()
{
    if (R<=10)
    {
        n=R+1;
        for (int i=2;i<=R;i++) ans.push_back({1,i,i-1});
        for (int i=2;i<=R;i++) ans.push_back({i,n,1});
        ans.push_back({1,n,1});return;
    } else 
    {
        int t=1,k=0;
        R-=2;while (t<=R/2) t*=2,k++;
        for (int i=2;i<=k+3;i++) for (int j=2;j<i;j++) add(j,i,t>>i-2);
        n=k+3;int tmp=0;
        for (int i=2;i<=k+2;i++)
        {
            if ((R+1)>>(k+2-i)&1)
            {
                add(1,i,tmp+1);
                tmp+=(1<<(k-i+2));
            }
        }
        add(1,n,1);
    }
}
signed main()
{
    rd(L);rd(R);R=R-L+1;
    solve();
    if (L!=1) n++,ans.push_back({n-1,n,L-1});
    puts("YES");
    cout<<n<<" "<<ans.size()<<"\n";
    for (edge e:ans) cout<<e.u<<" "<<e.v<<" "<<e.w<<"\n";
}
/*

*/