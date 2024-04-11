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
    int left,right,sum;
    tree *lchild,*rchild;
} *root[maxn];

vector<int> f[maxn];
int data[maxn],depth[maxn],lc[maxn],rc[maxn],ac1[maxn],ac2[maxn],kth[maxn],hash[maxn];
int mul[maxn][17];
int m,n,ll,rr,qzans,spa1,num1,spa2,num2,xc,yc,zc,flag,cs;

void finddepth(int s,int nowdeep)
{
    depth[s]=nowdeep;
    for (int i=0;i<f[s].size();i++)
        if (depth[f[s][i]]==0)
            finddepth(f[s][i],nowdeep+1);
}

void makemul(int s,int nowfa)
{
    hash[s]=1;
    mul[s][0]=nowfa;
    for (int i=1;i<=16;i++)
        mul[s][i]=mul[mul[s][i-1]][i-1];
    for (int i=0;i<f[s].size();i++)
        if (hash[f[s][i]]==0)
            makemul(f[s][i],s);
}

int getlca(int x,int y)
{
    if (depth[x]<depth[y]) swap(x,y);
    for (int i=16;i>=0;i--)
        if (depth[mul[x][i]]>=depth[y]) x=mul[x][i];
    if (x==y) return x;
    for (int i=16;i>=0;i--)
        if (mul[x][i]!=mul[y][i]) x=mul[x][i],y=mul[y][i];
    return mul[x][0];
}

void update(tree *p)
{
    p->sum=p->lchild->sum+p->rchild->sum;
}

void maketree(tree *&node,int left,int right)
{
    tree *p=new tree;
    p->lchild=0;p->rchild=0;
    p->left=left;p->right=right;
    p->sum=0;
    node=p;
    if (left==right)
    {
        if (left==data[1]) p->sum=1;
    }
    else
    {
        maketree(node->lchild,left,(left+right)/2);
        maketree(node->rchild,(left+right)/2+1,right);
        update(node);
    }
}

void makechair(int s,int nowfa)
{
    if (nowfa!=0)
    {
        root[s]=new tree;
        root[s]->left=1;
        root[s]->right=m+1;
        if (data[s]==0)
        {
            root[s]->lchild=root[nowfa]->lchild;
            root[s]->rchild=root[nowfa]->rchild;
            update(root[s]);
        }
        else
        {
            tree *p,*q,*w;
            p=root[s];
            q=root[nowfa];
            while (q->left!=q->right)
            {
                if (data[s]<=q->lchild->right)
                {
                    p->rchild=q->rchild;
                    w=new tree;
                    w->lchild=0;w->rchild=0;
                    w->left=q->lchild->left;
                    w->right=q->lchild->right;
                    w->sum=q->lchild->sum+1;
                    p->lchild=w;
                    p=w;
                    q=q->lchild;
                }
                else
                {
                    p->lchild=q->lchild;
                    w=new tree;
                    w->lchild=0;w->rchild=0;
                    w->left=q->rchild->left;
                    w->right=q->rchild->right;
                    w->sum=q->rchild->sum+1;
                    p->rchild=w;
                    p=w;
                    q=q->rchild;
                }
            }
        }
    }
    for (int i=0;i<f[s].size();i++)
        if (f[s][i]!=nowfa)
            makechair(f[s][i],s);
}

void searchit(tree *p)
{
    int l=p->left,r=p->right;
    if ((l>rr)||(r<ll)) return;
    if ((l==ll)&&(r<=rr))
    {
        qzans+=p->sum;
        ll=r+1;
    }
    else
        if (p->lchild!=0)
        {
            searchit(p->lchild);
            searchit(p->rchild);
        }
}

int numbers(int s,int lc,int rc)
{
    if (s==0) return 0;
    ll=lc,rr=rc;
    qzans=0;
    searchit(root[s]);
    return qzans;
}

int findup(int s,int kth,int l,int r)
{
    int spa,num,t;
    for (int i=16;i>=0;i--)
    {
        t=mul[s][i];
        if (t==0) continue;
        num=numbers(mul[s][0],l,r)-numbers(mul[t][0],l,r);
        spa=depth[s]-depth[t]-num;
        if (kth>spa)
        {
            kth-=spa;
            s=t;
        }
        else
            if ((kth==spa)&&((data[t]<l)||(data[t]>r))) return t;
    }
}

int main()
{
    //freopen("E.in","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&cs);
        if (cs==0) continue;
        f[cs].p_b(i);
        f[i].p_b(cs);
    }

    memset(lc,0,sizeof(lc));
    memset(rc,0,sizeof(rc));
    memset(data,0,sizeof(data));
    memset(kth,0,sizeof(kth));
    memset(ac1,0,sizeof(ac1));
    memset(ac2,0,sizeof(ac2));

    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&flag);
        if (flag==1)
        {
            scanf("%d",&cs);
            data[cs]=i;
            lc[i]=-1;
        }
        else
        {
            scanf("%d %d %d %d",&lc[i],&rc[i],&kth[i],&ac1[i]);
            ++ac1[i];
            ac2[i]=i;
        }
    }

    memset(depth,0,sizeof(depth));
    finddepth(1,1);

    memset(mul,0,sizeof(mul));
    memset(hash,0,sizeof(hash));
    makemul(1,0);

    maketree(root[1],1,m+1);
    memset(hash,0,sizeof(hash));
    makechair(1,0);

    for (int i=1;i<=m;i++)
        if (lc[i]!=-1)
        {
            xc=lc[i];
            yc=rc[i];
            zc=getlca(xc,yc);
            num1=numbers(mul[xc][0],ac1[i],ac2[i])-numbers(mul[zc][0],ac1[i],ac2[i]);
            spa1=depth[xc]-depth[zc]-num1;
            num2=numbers(mul[yc][0],ac1[i],ac2[i])-numbers(zc,ac1[i],ac2[i]);
            spa2=depth[yc]-depth[zc]-1-num2;
            if (kth[i]>spa1+spa2) printf("-1\n"); else
            {
                if (kth[i]<=spa1) printf("%d\n",findup(xc,kth[i],ac1[i],ac2[i])); else
                {
                    kth[i]-=spa1;
                    kth[i]=spa2+1-kth[i];
                    printf("%d\n",findup(yc,kth[i],ac1[i],ac2[i]));
                }
            }
        }

    return 0;
}