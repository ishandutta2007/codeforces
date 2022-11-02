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
#include <ctime>

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

struct tree
{
    tree *lchild,*rchild,*father;
    int num,size,max,biao;
} *root,*null,*p,*q,*g;

int N,cs,ck,o,cb;
int ans[100005];

void update(tree *p)
{
    if (p==null) return;
    p->size=p->lchild->size+p->rchild->size+1;
    p->max=max(max(p->lchild->max,p->rchild->max),p->num);
}

void spinl(tree *a)
{
    tree *b=a->lchild;
    a->lchild=b->rchild;
    b->rchild=a;
    a->lchild->father=a;
    b->father=a->father;
    a->father=b;
    update(a);
    update(b);
    if (b->father!=null)
    {
        if (b->father->lchild==a) b->father->lchild=b; else b->father->rchild=b;
    }
}

void spinr(tree *a)
{
    tree *b=a->rchild;
    a->rchild=b->lchild;
    b->lchild=a;
    a->rchild->father=a;
    b->father=a->father;
    a->father=b;
    update(a);
    update(b);
    if (b->father!=null)
    {
        if (b->father->lchild==a) b->father->lchild=b; else b->father->rchild=b;
    }
}

void splay(tree *p)
{
    tree *q,*g;
    while (p->father!=null)
    {
        q=p->father;
        if (q->father==null)
        {
            if (q->lchild==p) spinl(q); else spinr(q);
        }
        else
        {
            g=q->father;
            if (q->lchild==p)
            {
                if (g->lchild==q) spinl(g);
                spinl(q);
            }
            else
            {
                if (g->rchild==q) spinr(g);
                spinr(q);
            }
        }
    }
    root=p;
}

void dfs(tree *p)
{
    if (p==null) return;
    dfs(p->lchild);
    ++o,ans[o]=p->biao;
    dfs(p->rchild);
}

int main()
{
    //freopen("G.in","r",stdin);
    null=new tree;
    null->lchild=null->rchild=null->father=null;
    null->num=null->size=null->max=null->biao=0;

    scanf("%d",&N);
    scanf("%d %d",&cs,&ck);

    root=new tree;
    root->lchild=root->rchild=root->father=null;
    root->num=cs;
    root->biao=1;
    root->size=1;
    root->max=cs;

    for (int i=1;i<N;i++)
    {
        scanf("%d %d",&cs,&ck);
        p=root;
        while (true)
        {
            //cout<<p->num<<"    "<<p->rchild->size<<" "<<p->rchild->max<<" "<<ck<<endl;
            q=p;
            cb=ck;
            if ((cs<p->rchild->max)||(ck<=p->rchild->size)||(cs<p->num)) p=p->rchild; else
            {
                ck-=p->rchild->size+1;
                p=p->lchild;
            }
            if (p==null)
            {
                g=new tree;
                g->num=cs;
                g->biao=i+1;
                g->size=1;
                g->max=cs;
                g->lchild=g->rchild=null;
                if ((cs<q->rchild->max)||(cb<=q->rchild->size)||(cs<q->num)) q->rchild=g; else q->lchild=g;
                g->father=q;
                tree *gg=g;
                while (g!=null)
                {
                    update(g);
                    g=g->father;
                }
                splay(gg);
                break;
            }
        }
        /*o=0;
        dfs(root);
        for (int j=1;j<o;j++) printf("%d ",ans[j]);printf("%d\n",ans[o]);*/
    }
    o=0;
    dfs(root);
    for (int i=1;i<o;i++) printf("%d ",ans[i]);printf("%d\n",ans[o]);

    return 0;
}