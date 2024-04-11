#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define P 1000000000
#define N 200010
#define fi first
#define se second
#define mp make_pair
int n,m,a[N],f0[N*4],f1[N*4],g[N*4];
int w[N][4],f[N],fs[N];
void upd(int p,int pl,int pr,int sz)
{
    f0[p]=((ll)f0[pl]+(ll)w[sz][0]*f0[pr]%P+(ll)w[sz][1]*f1[pr]%P)%P;
    f1[p]=((ll)f1[pl]+(ll)w[sz][2]*f0[pr]%P+(ll)w[sz][3]*f1[pr]%P)%P;
}
PII comb(PII pl,PII pr,int sz)
{
    return mp(
        ((ll)pl.fi+(ll)w[sz][0]*pr.fi%P+(ll)w[sz][1]*pr.se%P)%P,
        ((ll)pl.se+(ll)w[sz][2]*pr.fi%P+(ll)w[sz][3]*pr.se%P)%P
    );
}
void blt(int p,int l,int r)
{
    if(l==r-1){f0[p]=a[l],f1[p]=a[l];return;}
    int mid=(l+r)/2;
    blt(p*2+1,l,mid),blt(p*2+2,mid,r);
    upd(p,p*2+1,p*2+2,mid-l);
}
void add(int p,int l,int r,int x)
{
    f0[p]=(f0[p]+(ll)fs[r-l]*x)%P,
    f1[p]=((ll)f1[p]+(ll)(fs[r-l+1]-1)*x%P+P)%P,
    g[p]+=x;
}
void pd(int p,int l,int r)
{
    int mid=(l+r)/2;
    if(g[p])add(p*2+1,l,mid,g[p]),add(p*2+2,mid,r,g[p]),g[p]=0;
}
void upd(int p,int l,int r,int x,int y)
{
    if(l==r-1){f0[p]=y;f1[p]=y;return;}
    pd(p,l,r);
    int mid=(l+r)/2;
    if(x<mid)upd(p*2+1,l,mid,x,y);
    else upd(p*2+2,mid,r,x,y);
    upd(p,p*2+1,p*2+2,mid-l);
}
PII ask(int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)return mp(f0[p],f1[p]);
    pd(p,l,r);
    int mid=(l+r)/2;
    if(R<=mid)return ask(p*2+1,l,mid,L,R);
    if(mid<=L)return ask(p*2+2,mid,r,L,R);
    PII SL=ask(p*2+1,l,mid,L,R);
    PII SR=ask(p*2+2,mid,r,L,R);
    return comb(SL,SR,mid-max(l,L));
}
void add(int p,int l,int r,int L,int R,int x)
{
    if(L<=l&&r<=R){add(p,l,r,x);return;}
    pd(p,l,r);
    int mid=(l+r)/2;
    if(L<mid)add(p*2+1,l,mid,L,R,x);
    if(mid<R)add(p*2+2,mid,r,L,R,x);
    upd(p,p*2+1,p*2+2,mid-l);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    w[0][0]=1,w[0][1]=0,w[0][2]=0,w[0][3]=1;
    w[1][0]=0,w[1][1]=1,w[1][2]=1,w[1][3]=1;
    for(int i=2;i<N;i++)
    {
        w[i][0]=w[i-1][2];//00 00*00+01*10
        w[i][1]=w[i-1][3];//01 00*01+01*11
        w[i][2]=(w[i-1][0]+w[i-1][2])%P;//10 10*00+11*10
        w[i][3]=(w[i-1][1]+w[i-1][3])%P;//11 10*01+11*11
    }
    f[0]=1,f[1]=1;
    for(int i=2;i<N;i++)f[i]=(f[i-1]+f[i-2])%P;
    fs[0]=0;
    for(int i=1;i<N;i++)fs[i]=(fs[i-1]+f[i-1])%P;
    blt(0,0,n);
    for(int i=0;i<m;i++)
    {
        int c;scanf("%d",&c);
        if(c==1)
        {
            int x,y;scanf("%d%d",&x,&y);--x;
            upd(0,0,n,x,y);
        }else
        if(c==2)
        {
            int l,r;scanf("%d%d",&l,&r);l--;
            printf("%d\n",ask(0,0,n,l,r).fi);
        }else
        if(c==3)
        {
            int l,r,x;scanf("%d%d%d",&l,&r,&x);l--;
            add(0,0,n,l,r,x);
        }
    }
    return 0;
}