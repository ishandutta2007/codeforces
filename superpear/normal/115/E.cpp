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

const int maxn=200005;
const LL maxint64=1000000000000000000LL;

int n,m,lc,rc,profit,kc,kd;
int data[maxn];
vector<PII> ls[maxn];

struct tree
{
    tree *lchild,*rchild;
    int left,right;
    LL max,delta;
} *root;

class Linetree
{
    private:

    int qzl,qzr,qznum;
    LL ans;

    void update(tree *p)
    {
        p->max=max(p->lchild->max,p->rchild->max);
    }

    void downit(tree *p)
    {
        if (p->delta!=0)
        {
            if (p->lchild!=0)
            {
                p->lchild->delta+=(LL)p->delta;
                p->lchild->max+=(LL)p->delta;
                p->rchild->delta+=(LL)p->delta;
                p->rchild->max+=(LL)p->delta;
            }
            p->delta=0;
        }
    }

    void doit1(tree *p)
    {
        int l=p->left,r=p->right;
        if ((l>qzr)||(r<qzl)) return;
        downit(p);
        if ((l==qzl)&&(r<=qzr))
        {
            qzl=r+1;
            ans=max(ans,p->max);
        }
        else
        {
            doit1(p->lchild);
            doit1(p->rchild);
            update(p);
        }
    }

    void doit2(tree *p)
    {
        int l=p->left,r=p->right;
        if ((l>qzr)||(r<qzl)) return;
        downit(p);
        if ((l==qzl)&&(r<=qzr))
        {
            qzl=r+1;
            p->delta=qznum;
            p->max+=(LL)qznum;
            downit(p);
        }
        else
        {
            doit2(p->lchild);
            doit2(p->rchild);
            update(p);
        }
    }

    public:
    void maketree(tree *&node,int left,int right)
    {
        tree *p=new tree;
        p->lchild=0,p->rchild=0;
        p->left=left,p->right=right;
        p->delta=0,p->max=-maxint64;
        node=p;
        if (left==right) return; else
        {
            maketree(node->lchild,left,(left+right)/2);
            maketree(node->rchild,(left+right)/2+1,right);
        }
    }

    LL getmax(int left,int right)
    {
        qzl=left,qzr=right,ans=-maxint64;
        doit1(root);
        return ans;
    }

    void plus(int left,int right,int num)
    {
        qzl=left,qzr=right,qznum=num;
        doit2(root);
    }

    void insert(tree *p,int place,LL num)
    {
        int l=p->left,r=p->right;
        if ((l>place)||(r<place)) return;
        downit(p);
        if (l==r)
            p->max=num;
        else
        {
            insert(p->lchild,place,num);
            insert(p->rchild,place,num);
            update(p);
        }
    }

} Q;

int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&data[i]);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&lc,&rc,&profit);
        ls[rc].p_b(m_p(lc,profit));
    }
    Q.maketree(root,1,n+1);
    Q.insert(root,1,0);
    for (int i=1;i<=n;i++)
    {
        Q.insert(root,i+1,Q.getmax(1,i));
        Q.plus(1,i,-data[i]);
        for (int j=0;j<ls[i].size();j++)
        {
            kc=i-ls[i][j].w1+1,kd=ls[i][j].w2;
            Q.plus(1,i+1-kc,kd);
        }
    }
    printf("%I64d\n",root->max);

    return 0;
}