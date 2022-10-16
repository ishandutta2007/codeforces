#include<bits/stdc++.h>
#define rd(x) x=read()
#define I inline
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
const int N=1e6+1005,SZ=1000;
const int M=5e5+5;
const int NM=1e5+5;

int fa[N],val[N];//val[i]i
int sz[NM],id[NM];
int n,m;
int a[N];//
int pos[N];//
int Max;//
int tag;//
int ANS[M];//
int OPT[M],L[M],R[M],X[M];
int opt,l,r,x,Pl,Pr;
inline int getfa(int x)
{
    if (fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}
inline void merge(int x,int y)
{
    if (id[y]) fa[id[x]]=id[y];
    else
    {
        id[y]=id[x];
        val[id[y]]=y;
    }
    sz[y]+=sz[x];
    id[x]=sz[x]=0;
}
inline void Break()
{
    //P
    for (int i=Pl;i<=Pr;i++)
    {
        a[i]=val[getfa(i)];//j
        sz[a[i]]=id[a[i]]=0;//0
        a[i]-=tag;//
    }
    for (int i=Pl;i<=Pr;i++) fa[i]=0;
    tag=0;
}
inline void Build()
{
    //P
    Max=0;
    for (int i=Pl;i<=Pr;i++)
    {
        Max=max(Max,a[i]);//
        if (id[a[i]]==0)//a[i]
        {//
            fa[i]=i;
            id[a[i]]=i;
            val[i]=a[i];
        }
        else//
        fa[i]=id[a[i]];
        sz[a[i]]++;
    }
}
inline void update(int _L,int _R,int x)
{
    if (_L>_R) return;
    Break();//
    for (int i=_L;i<=_R;i++) if (a[i]>x) a[i]-=x;//
    Build();//
}
inline void UPDATE(int x)
{
    //
    if (Max-tag>=x*2)
    {
        // 2xv  ai[x+1,v] [1,vx]
        //orz ClCN
        for (int i=tag+1;i<=tag+x;i++)
            if (id[i]) merge(i,i+x);
        tag+=x;
    }
    else
    {
        // 2x<v  [1,x] [x+1,2x] L  LL+xL 
        //orz ClCN
        for (int i=Max;i>tag+x;i--)
            if (id[i]) merge(i,i-x);
        Max=min(tag+x,Max);
    }
}
inline int query(int _L,int _R,int x) //
{
    int ans=0;
    for (int i=_L;i<=_R;i++)
        if (val[getfa(i)]-tag==x) ans++;
    return ans;
}
inline int QUERY(int x)//
{
    if (x+tag>1e5+1) return 0;
    return sz[x+tag];
}

signed main()
{
    rd(n);rd(m);
    for (int i=1;i<=n;i++) rd(a[i]);
    for (int i=1;i<=n;i++) pos[i]=(i-1)/SZ+1;
    for (int i=1;i<=m;i++) {rd(OPT[i]);rd(L[i]);rd(R[i]);rd(X[i]);}
    for (int k=1;k<=pos[n];k++)
    {
        Pl=(k-1)*SZ+1,Pr=k*SZ;
        Build();
        for (int i=1;i<=m;i++)
        {
            opt=OPT[i],l=L[i],r=R[i],x=X[i];
            if (opt==1)
            {
                if (l<=Pl && r>=Pr) UPDATE(x);
                else update(max(l,Pl),min(r,Pr),x);
            }
            else
            {
                int ans=0;
                if (l<=Pl && r>=Pr) ans=QUERY(x);
                else ans=query(max(l,Pl),min(r,Pr),x);
                ANS[i]+=ans;
            }
        }
        Break();
    }
    for (int i=1;i<=m;i++) if (OPT[i]==2) printf("%d\n",ANS[i]);
}