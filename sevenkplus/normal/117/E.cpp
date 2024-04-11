#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define N 100010
#define pb push_back
#define tree(x) rt[bl[x]],1,1,le[bl[x]]
vector<int> A[N],B;int d[N],n,n1,m,fu[N],pr[N],ne[N],we[N],ht[N];bool v[N];
int fa[N][17],de[N],sz[N],bl[N],po[N],le[N],S=0;
struct P{int x;bool y;}*rt[N],tp[N*4],*tr,f[N*4];
void upd(P&x,int y){x.x=y-x.x,x.y=!x.y;}
void upd(P *f,int p,int l,int r,int L,int R)
{
    if(L<=l&&r<=R){S+=r-l+1-f[p].x*2;upd(f[p],r-l+1);return;}
    int m=(l+r)/2;
    if(f[p].y)upd(f[p*2],m-l+1),upd(f[p*2+1],r-m),f[p].y=0;
    if(L<=m)upd(f,p*2,l,m,L,R);
    if(m<R)upd(f,p*2+1,m+1,r,L,R);
    f[p].x=f[p*2].x+f[p*2+1].x;
}
void ff(int x,int y)
{
    if(!B.empty()&&x==B[0])return;
    B.pb(x);
    for(vector<int>::iterator i=A[x].begin();i!=A[x].end();i++)
        if(*i!=y&&!fu[*i]){ff(*i,x);break;}
}
void fd1(int x,int y)
{
    v[x]=true;ht[x]=y;
    for(int k=1;k<17;k++)fa[x][k]=fa[fa[x][k-1]][k-1];
    sz[x]=1;
    for(vector<int>::iterator i=A[x].begin();i!=A[x].end();i++)
        if(!v[*i])de[*i]=de[x]+1,fa[*i][0]=x,fd1(*i,y),sz[x]+=sz[*i];
}
void fd2(int x,int l)
{
    v[x]=true;
    int hc=0,hz=0;
    for(vector<int>::iterator i=A[x].begin();i!=A[x].end();i++)
        if(!v[*i]&&sz[*i]>hz)hz=sz[*i],hc=*i;
    if(!hc)
    {
        int p=x;
        for(int i=1;i<l;i++)p=fa[p][0];
        rt[p]=tr,tr+=l*4,le[p]=l;
        for(int i=l;i;i--)bl[x]=p,po[x]=i,x=fa[x][0];
        return;
    }
    fd2(hc,l+1);
    for(vector<int>::iterator i=A[x].begin();i!=A[x].end();i++)
        if(!v[*i]&&*i!=hc)fd2(*i,1);
}
void goup(int&x,int l)
{
    for(int k=0;k<17;l/=2,k++)
        if(l&1)x=fa[x][k];
}
int lca(int x,int y)
{
    if(de[x]>de[y])swap(x,y);
    goup(y,de[y]-de[x]);
    if(x==y)return x;
    for(int k=16;k>=0;k--)
        if(fa[x][k]!=fa[y][k])
            x=fa[x][k],y=fa[y][k];
    return fa[x][0];
}
void upd(int x,int y)
{
    if(x==y)return;
    while(x!=y)
        if(bl[x]!=bl[y])upd(tree(y),1,po[y]),y=fa[bl[y]][0];
        else{upd(tree(y),po[x]+1,po[y]);break;}
}
int goo(int x,int y)
{
    //printf("%d %d\n",x,y);
    if(x<y)upd(f,1,1,n1,x,y-1);
    else{upd(f,1,1,n1,x,n1);if(y!=1)upd(f,1,1,n1,1,y-1);}
}
void out(P*f,int p,int l,int r)
{
    printf("%d %d %d %d %d\n",p,l,r,f[p].x,f[p].y);
    if(l==r)return;
    int m=(l+r)/2;
    out(f,p*2,l,m),out(f,p*2+1,m+1,r);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y),
        A[x].pb(y),A[y].pb(x),d[x]++,d[y]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)if(d[i]==1)q.push(i);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(vector<int>::iterator i=A[x].begin();i!=A[x].end();i++)
            if(d[*i]>1)
            {
                fu[x]=*i,d[*i]--;
                if(d[*i]==1)q.push(*i);
            }
    }
    int p=0;
    for(int i=1;i<=n;i++)if(!fu[i])p=i;
    ff(p,0);n1=(int)B.size();
    for(int i=0;i<n1;i++)
        pr[i]=B[i==0?(n1-1):(i-1)],ne[i]=B[i==(n1-1)?0:i+1],we[B[i]]=i+1;
    for(int i=0;i<n1;i++)v[B[i]]=1;
    for(int i=0;i<n1;i++)fd1(B[i],B[i]);
    memset(v,0,sizeof v);tr=tp;
    for(int i=0;i<n1;i++)v[B[i]]=1;
    for(int i=0;i<n1;i++)fd2(B[i],1);
    //for(int i=0;i<n1;i++)printf("%d ",B[i]);puts("");
    while(m--)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(ht[x]==ht[y])
        {
            int z=lca(x,y);
            upd(z,x),upd(z,y);
        }else
        {
            upd(ht[x],x),upd(ht[y],y);
            x=we[ht[x]],y=we[ht[y]];
            if(abs(y-x)!=n1-abs(y-x))
            {
                if(x>y)swap(x,y);
                if(abs(y-x)<n1-abs(y-x))goo(x,y);else goo(y,x);
            }else if(pr[x-1]<ne[x-1])goo(y,x);else goo(x,y);
        }
        //out(f,1,1,n1);
        if(f[1].x==n1)printf("%d\n",n-S+1);else printf("%d\n",n-S);
        //printf("%d\n",S);
    }
    return 0;
}