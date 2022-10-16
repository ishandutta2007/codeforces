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

int n,x,m,tot;
int b[N];
bool cmp(int x,int y){return x>y;}
struct Node
{
    int id,x;
    bool operator<(const Node &o) const{return x==o.x?id<o.id:x<o.x;}
}a[N];
set<Node> S;
void solve()
{
    S.clear();
    rd(n);rd(m);rd(x);
    for (int i=1;i<=n;i++) rd(a[i].x),a[i].id=i;
    sort(a+1,a+n+1);
    for (int i=1;i<=m;i++) S.insert((Node){i,0});
    for (int i=n;i>=1;i--)
    {
        Node u=*S.begin();
        S.erase(u);
        u.x+=a[i].x;
        b[a[i].id]=u.id;
        S.insert(u);
    }
    Node u=*S.begin();Node v=*S.rbegin();
    if (v.x-u.x<=x)
    {
        puts("YES");
        for (int i=1;i<=n;i++) cout<<b[i]<<" ";
        cout<<"\n";
    }
    else puts("NO");
}
signed main()
{
    int T;cin>>T;while (T--)
    {
	solve();

    }

}