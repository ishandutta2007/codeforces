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
typedef pair<PII,PII> PIIII;

const int maxn=1100005;

int n,o,maxc,qzl,qzr,qznum,qzmin,e,ll,rr;
LL ans;
PIIII range[maxn],range2[maxn];
double vx,vy,obx,oby,k,b[maxn],nowy1,nowy2,cc,ccc[maxn];
int a[1005][1005],ee[maxn];

struct tree
{
    tree *lchild,*rchild;
    int min,delta;
} *root;

double dis(const double &x1,const double &y1,const double &x2,const double &y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool equal(const double &a,const double &b)
{
    return (abs(a-b)<=1e-9);
}

bool cmp(int a,int b)
{
    double v1=ccc[a];
    double v2=ccc[b];
    if (equal(v1,v2)) return range[a].w1<range[b].w1; else return v1<v2;
}

void maketree(tree *&node,int left,int right)
{
    tree *p;
    p=new tree;
    p->lchild=0;p->rchild=0;
    p->delta=0;p->min=0;
    node=p;
    if (left==right) return;
    maketree(node->lchild,left,(left+right)/2);
    maketree(node->rchild,(left+right)/2+1,right);
}

void downit(tree *p)
{
    if (p->delta!=0)
    {
            if (p->lchild!=0)
            {
                p->lchild->delta=max(p->lchild->delta,p->delta);
                p->rchild->delta=max(p->rchild->delta,p->delta);
                p->lchild->min=max(p->lchild->min,p->delta);
                p->rchild->min=max(p->rchild->min,p->delta);
            }
        p->delta=0;
    }
}

void update(tree *p)
{
    p->min=min(p->lchild->min,p->rchild->min);
}

void doit(tree *p,int l,int r)
{
    if ((l>qzr)||(r<qzl)) return;
    downit(p);
    if ((l==qzl)&&(r<=qzr))
    {
        qzl=r+1;
        qzmin=min(qzmin,p->min);
    }
    else
    {
        doit(p->lchild,l,(l+r)/2);
        doit(p->rchild,(l+r)/2+1,r);
        update(p);
    }
}

void ddt(tree *p,int l,int r)
{
    if ((l>qzr)||(r<qzl)) return;
    downit(p);
    if ((l==qzl)&&(r<=qzr))
    {
        qzl=r+1;
        if (qznum>p->min)
        {
            p->delta=qznum;
            p->min=max(p->min,qznum);
        }
        downit(p);
    }
    else
    {
        ddt(p->lchild,l,(l+r)/2);
        ddt(p->rchild,(l+r)/2+1,r);
        update(p);
    }
}

void pushmax(int l,int r,int c)
{
    qzl=l;qzr=r;qznum=c;
    ddt(root,1,o);
}

int getmin(int l,int r)
{
    qzl=l;qzr=r;qzmin=maxlongint;
    doit(root,1,o);
    return qzmin;
}

int getnum()
{
    int e=0;
    char ch;
    while (true)
    {
        ch=getchar();
        if ((ch>='0')&&(ch<='9')) e=e*10+ch-48; else break;
    }
    return e;
}

int main()
{
    scanf("%d %lf %lf\n",&n,&vx,&vy);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=getnum();
    if (vx==0)
    {
        ans=0;
        for (int i=1;i<=n;i++)
        {
            maxc=0;
            for (int j=1;j<=n;j++)
                maxc=max(maxc,a[i][j]);
            ans+=(LL)maxc;
        }
        printf("%I64d\n",ans);
    }
    else
    {
        int left,right,mid;
        obx=(-vx)*10000000;
        oby=(-vy)*10000000;
        k=vy/vx;
        o=0;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
            {
                ++o;
                b[o]=j-k*i;
            }
        sort(b+1,b+o+1);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                left=1;
                right=o;
                while (left<=right)
                {
                    mid=(left+right)/2;
                    nowy1=k*(i-1)+b[mid];
                    nowy2=k*i+b[mid];
                    cc=max(nowy1,nowy2);
                    if ((cc>(j-1))||(equal(cc,j-1))) right=mid-1; else left=mid+1;
                }
                ll=left;
                left=1;
                right=o;
                while (left<=right)
                {
                    mid=(left+right)/2;
                    nowy1=k*(i-1)+b[mid];
                    nowy2=k*i+b[mid];
                    cc=min(nowy1,nowy2);
                    if ((cc<j)||(equal(cc,j))) left=mid+1; else right=mid-1;
                }
                rr=right;
                range[(i-1)*n+j]=m_p(m_p(i,j),m_p(ll,rr));
                ccc[(i-1)*n+j]=dis(obx,oby,i,j);
            }
        for (int i=1;i<=n*n;i++) ee[i]=i;
        sort(ee+1,ee+n*n+1,cmp);
        maketree(root,1,o);
        ans=0;
        for (int i=1;i<=n*n;i++)
        {
            PIIII td=range[ee[i]];
            e=getmin(td.w2.w1,td.w2.w2-1);
            ans+=(LL)(max(a[td.w1.w1][td.w1.w2]-e,0));
            pushmax(td.w2.w1,td.w2.w2-1,a[td.w1.w1][td.w1.w2]);
        }
        printf("%I64d\n",ans);
    }

    return 0;
}