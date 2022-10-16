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
const int N=(1<<16)+5;
const int M=2.2e6+5;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
const double pi=acos(-1);
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,m,cnt;
int p[N],ans[N];
vector<int> id[N];
pii S[M];
map<pii,int> Map[N];
void init(int rt,int l,int r)
{
    for (int i=l;i<=r;i++) id[rt].push_back(p[i]);
    sort(id[rt].begin(),id[rt].end());
    if (l==r) return;int mid=(l+r)/2;
    init(ls,l,mid);init(rs,mid+1,r);
}
int query(int rt,int L,int R)
{
    int l=lower_bound(id[rt].begin(),id[rt].end(),L)-id[rt].begin();
    int r=upper_bound(id[rt].begin(),id[rt].end(),R)-id[rt].begin()-1;
    if (l>r) return 0;if (l==r) return id[rt][l];
    int &ret=Map[rt][mp(l,r)];if (ret) return ret;
    int x=query(ls,L,R),y=query(rs,L,R);
    if (x==0 || y==0) return ret=x+y;
    S[++cnt]=mp(x,y);return ret=cnt;
}
signed main()
{
    rd(n);rd(m);cnt=n;for (int i=1,x;i<=n;i++) rd(x),p[x]=i;init(1,1,n);
    for (int i=1,l,r;i<=m;i++) rd(l),rd(r),ans[i]=query(1,l,r);
    cout<<cnt<<"\n";for (int i=n+1;i<=cnt;i++) cout<<S[i].fi<<" "<<S[i].se<<"\n";
    for (int i=1;i<=m;i++) cout<<ans[i]<<" ";cout<<"\n";


}
/*
*/