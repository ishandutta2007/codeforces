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
#define y1 ______________________________
using namespace std;
const int N=2000+5;
const int M=70;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
const double pi=acos(-1);
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,vis[N],cir[N],cnt,id,P[N];
struct Point{int x,y,a,id;}p[N];
double theta(Point a){return atan2(a.y-p[1].y,a.x-p[1].x);}// p[1] 
bool cmp(Point a,Point b){return theta(a)<theta(b);}
int fa[N];int getfa(int x){if (x==fa[x]) return x;return fa[x]=getfa(fa[x]);}
vector<pii> ans;
void SWAP(Point &a,Point &b){swap(a.a,b.a);ans.push_back(mp(a.id,b.id));}
signed main()
{
    rd(n);for (int i=1;i<=n;i++) rd(p[i].x),rd(p[i].y),rd(p[i].a),p[i].id=i;
    for (int i=1;i<=n;i++) if (p[i].a!=i) {id=i;break;}
    if (id==0) {puts("0");return 0;}if (id!=1) swap(p[id],p[1]);
    stable_sort(p+2,p+n+1,cmp);
    for (int i=1;i<=n;i++) P[p[i].id]=i;
    for (int i=1;i<=n;i++) if (!vis[i]){int x=i;cnt++;while (!vis[x]) {vis[x]=1;cir[x]=cnt;x=P[p[x].a];}}
    for (int i=1;i<=cnt;i++) fa[i]=i;
    for (int i=2;i<=n;i++){int j=i+1;if (j==n+1) j=2;if (theta(p[j])-theta(p[i])<pi) {int u=getfa(cir[i]),v=getfa(cir[j]);if (u!=v) SWAP(p[i],p[j]),fa[u]=v;}}
    for (int i=1;i<=n;i++) P[p[i].id]=i;
    for (int i=1;i<n;i++) SWAP(p[1],p[P[p[1].a]]);
    cout<<ans.size()<<"\n";for (pii x:ans) cout<<x.fi<<" "<<x.se<<"\n";


}
/*
*/