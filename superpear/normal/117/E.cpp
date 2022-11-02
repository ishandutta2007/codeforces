#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int maxn=100005;

struct tree
{
    int left,right,delta,num;
    tree *lchild,*rchild;
} *root[maxn],*rootcyc;

vector<int> f[maxn];
int dfsfa[maxn],depth[maxn],size[maxn],mul[maxn][18];
int oncyc[maxn],plonc[maxn],cyc[maxn];
int first[maxn],cd[maxn],inlink[maxn],whea[maxn],light[maxn];
int inwhich[maxn];
int n,m,xc,yc,tlink,o,findcyc,nowe;

void dfs(int s,int fa)
{
    int cs,e;

    dfsfa[s]=fa;
    for (int i=0;i<f[s].size();i++)
    {
        cs=f[s][i];
        if (cs!=fa)
        {
            if (dfsfa[cs]!=biglongint)
            {
                findcyc=0;
                e=s;
                while (true)
                {
                    ++o,cyc[o]=e;
                    if (e==cs) break;
                    e=dfsfa[e];
                }
                return;
            }
            dfs(cs,s);
            if (findcyc==0) return;
        }
    }
}

void downit(tree *p)
{
    if (p->delta==1)
    {
        if (p->lchild!=0)
        {
            p->lchild->delta=1-p->lchild->delta;
            p->lchild->num=p->lchild->right-p->lchild->left+1-p->lchild->num;
            p->rchild->delta=1-p->rchild->delta;
            p->rchild->num=p->rchild->right-p->rchild->left+1-p->rchild->num;
        }
        p->delta=0;
    }
}

void update(tree *p)
{
    if (p->lchild!=0) p->num=p->lchild->num+p->rchild->num;
}

void change(tree *p,int left,int right)
{
    if (left>right) return;
    int l=p->left,r=p->right;
    if ((l>right)||(r<left)) return;
    downit(p);
    if ((l==left)&&(r==right))
    {
        p->delta=1;
        p->num=(p->right-p->left+1)-p->num;
        downit(p);
    }
    else
    {
        change(p->lchild,left,min(right,p->lchild->right));
        change(p->rchild,max(left,p->rchild->left),right);
        update(p);
    }
}

int getsum(tree *p,int left,int right)
{
    if (left>right) return 0;
    int l=p->left,r=p->right;
    if ((l>right)||(r<left)) return 0;
    downit(p);
    if ((l==left)&&(r==right)) return p->num;
    int cs=getsum(p->lchild,left,min(right,p->lchild->right))+
           getsum(p->rchild,max(left,p->rchild->left),right);
    update(p);
    return cs;
}

void calcabove(int s,int deep,int rt,int father)
{
    int cs;
    depth[s]=deep;
    inwhich[s]=rt;
    mul[s][0]=father;
    for (int i=1;i<=16;i++)
        mul[s][i]=mul[mul[s][i-1]][i-1];
    for (int i=0;i<f[s].size();i++)
    {
        cs=f[s][i];
        if ((cs!=father)&&(oncyc[cs]==0))
            calcabove(cs,deep+1,rt,s);
    }
}

int lca(int x,int y)
{
    if (depth[x]<depth[y]) swap(x,y);
    for (int i=16;i>=0;i--)
        if (depth[mul[x][i]]>=depth[y]) x=mul[x][i];
    if (x==y) return x;
    for (int i=16;i>=0;i--)
        if (mul[x][i]!=mul[y][i]) x=mul[x][i],y=mul[y][i];
    return mul[x][0];
}

void findheavy(int s,int father)
{
    int cs,maxc=-1,maxk=-1;
    size[s]=1;
    for (int i=0;i<f[s].size();i++)
    {
        cs=f[s][i];
        if ((cs!=father)&&(oncyc[cs]==0))
        {
            findheavy(cs,s);
            if (size[cs]>maxc) maxc=size[cs],maxk=cs;
            size[s]+=size[cs];
        }
    }
    whea[s]=maxk;
}

void maketree(tree *&node,int left,int right)
{
    tree *p=new tree;
    p->lchild=0,p->rchild=0;
    p->left=left,p->right=right;
    p->num=0,p->delta=0;
    node=p;
    if (left==right) return;
    maketree(node->lchild,left,(left+right)/2);
    maketree(node->rchild,(left+right)/2+1,right);
}

void pou(int s,int father,int ishead)
{
    if (ishead==1)
    {
        ++tlink;
        first[tlink]=s;
    }
    inlink[s]=tlink;
    if (whea[s]!=-1) pou(whea[s],s,0); else
    {
        cd[tlink]=depth[s]-depth[first[tlink]];
        if (cd[tlink]>0) maketree(root[tlink],1,cd[tlink]); else maketree(root[tlink],1,1);
    }
    for (int i=0;i<f[s].size();i++)
        if ((f[s][i]!=whea[s])&&(f[s][i]!=father)&&(oncyc[f[s][i]]==0))
            pou(f[s][i],s,1);
}

void changeover(int s,int tk)
{
    int c,d,len,lc;
    while (true)
    {
        c=inlink[s];
        d=first[c];
        if (depth[d]<=depth[tk])
        {
            len=depth[s]-depth[tk];
            lc=getsum(root[c],depth[tk]-depth[d]+1,depth[s]-depth[d]);
            //cout<<lc<<" "<<c<<" "<<s<<" "<<d<<" "<<tk<<endl;
            nowe=nowe-lc+(len-lc);
            change(root[c],depth[tk]-depth[d]+1,depth[s]-depth[d]);
            break;
        }
        else
        {
            len=depth[s]-depth[d];
            lc=getsum(root[c],1,depth[s]-depth[d]);
            //cout<<lc<<endl;
            nowe=nowe-lc+(len-lc);
            change(root[c],1,depth[s]-depth[d]);
            s=d;
            nowe=nowe-light[s]+(1-light[s]);
            light[s]=1-light[s];
            s=mul[s][0];
        }
    }
}

int main()
{
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);

    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc].p_b(yc);
        f[yc].p_b(xc);
    }

    memset(dfsfa,127,sizeof(dfsfa));
    memset(cyc,0,sizeof(cyc));
    o=0;
    findcyc=1;
    dfs(1,0);
    memset(oncyc,0,sizeof(oncyc));
    memset(plonc,0,sizeof(plonc));
    for (int i=1;i<=o;i++)
        oncyc[cyc[i]]=1,plonc[cyc[i]]=i;

    memset(depth,0,sizeof(depth));
    memset(mul,0,sizeof(mul));
    memset(inwhich,0,sizeof(inwhich));
    for (int i=1;i<=o;i++)
        calcabove(cyc[i],1,cyc[i],0);

    memset(inlink,0,sizeof(inlink));
    memset(first,0,sizeof(first));
    memset(whea,0,sizeof(whea));
    memset(size,0,sizeof(size));
    memset(light,0,sizeof(light));
    memset(cd,0,sizeof(cd));
    tlink=0;
    for (int i=1;i<=o;i++)
    {
        findheavy(cyc[i],0);
        pou(cyc[i],0,1);
    }
    maketree(rootcyc,1,o);

    nowe=0;
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        if (inwhich[xc]==inwhich[yc])
        {
            int lsbl=lca(xc,yc);
            changeover(xc,lsbl);
            changeover(yc,lsbl);
        }
        else
        {
            changeover(xc,inwhich[xc]);
            changeover(yc,inwhich[yc]);
            int pl1=plonc[inwhich[xc]],pl2=plonc[inwhich[yc]];
            if (pl1<pl2)
            {
                int disc=pl2-pl1;
                if ((disc<(o-disc))||
                    ((disc*2==o)&&(cyc[pl1+1]<cyc[(pl1-1+o-1)%o+1])))
                        change(rootcyc,pl1,pl2-1);
                    else
                    {
                        change(rootcyc,1,pl1-1);
                        change(rootcyc,pl2,o);
                    }
            }
            else
            {
                int disc=pl1-pl2;
                if ((disc<(o-disc))||
                    ((disc*2==o)&&(cyc[pl1-1]<cyc[pl1%o+1])))
                        change(rootcyc,pl2,pl1-1);
                    else
                    {
                        change(rootcyc,1,pl2-1);
                        change(rootcyc,pl1,o);
                    }
            }
        }
        int lsdk=o-rootcyc->num;
        if (lsdk==0) ++lsdk;
        printf("%d\n",lsdk+n-nowe-o);
        //cout<<nowe<<endl;cout<<endl;
    }

    return 0;
}