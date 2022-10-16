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
const int N=2e5+5;
const int M=2e5+5;
const int SZ=450;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
void write(int x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
void gmin(int &x,int y){x=min(x,y);}
int n,q,k,ans,s;
int a[N];
struct SegT{int l,r,w,sz,L,R,Llen,Rlen;}T[N*4];
vector<int> tmp;
bool cmp(int a,int b){return T[a].l<T[b].l;}
void pushup(int rt)
{
    T[rt].w=(T[ls].w+T[rs].w+(T[ls].R<=T[rs].L)*T[ls].Rlen*T[rs].Llen);
    T[rt].L=T[ls].L;T[rt].R=T[rs].R;
    if (T[rs].Rlen==T[rs].sz && T[ls].R<=T[rs].L) T[rt].Rlen=T[rs].Rlen+T[ls].Rlen;else T[rt].Rlen=T[rs].Rlen;
    if (T[ls].Llen==T[ls].sz && T[ls].R<=T[rs].L) T[rt].Llen=T[ls].Llen+T[rs].Llen;else T[rt].Llen=T[ls].Llen;
}
void update(int rt,int x,int y)
{
    if (x<=T[rt].l && T[rt].r<=x)
    {
        T[rt].L=T[rt].R=y;
        return;
    }
    int mid=(T[rt].l+T[rt].r)>>1;
    if (x<=mid) update(ls,x,y);
    if (x>mid) update(rs,x,y);
    pushup(rt);
}
void query(int rt,int L,int R)
{
    int ans=0;
    if (L<=T[rt].l && T[rt].r<=R) {tmp.push_back(rt);return;}
    int mid=(T[rt].l+T[rt].r)>>1;
    if (L<=mid) query(ls,L,R);
    if (R>mid) query(rs,L,R);
}
void build(int rt,int L,int R)
{
    T[rt].l=L;T[rt].r=R;
    T[rt].sz=R-L+1;
    T[rt].L=T[rt].R=0;
    T[rt].w=0;
    if (L==R) 
    {
        T[rt].w=1;
        T[rt].Llen=T[rt].Rlen=1;
        T[rt].L=T[rt].R=a[L];
        return;
    }
    int mid=(L+R)>>1;
    build(ls,L,mid);
    build(rs,mid+1,R);
    pushup(rt);
}


signed main()
{
    rd(n);rd(q);
    for (int i=1;i<=n;i++) rd(a[i]);
    build(1,1,n);
    while (q--)
    {
        int op,x,y;
        rd(op);rd(x);rd(y);
        if (op==1) update(1,x,y);
        else 
        {
            tmp.clear();
            query(1,x,y);
            sort(tmp.begin(),tmp.end(),cmp);
            int ans=0,la=0;
            int R,Rlen;
            for (int x:tmp)
            {
                ans+=T[x].w;
                
                if (la==0) la=1,R=T[x].R,Rlen=T[x].Rlen;else 
                {
                    ans+=(R<=T[x].L)*(Rlen*T[x].Llen);
                    if (T[x].Rlen==T[x].sz && R<=T[x].L) Rlen=T[x].Rlen+Rlen;else Rlen=T[x].Rlen;
                    R=T[x].R;
                }
            }
            cout<<ans<<"\n";
            
        }
    }
}