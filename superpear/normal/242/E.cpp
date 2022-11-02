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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;


struct tree
{
    tree *lchild,*rchild;
    int left,right,len,num,turn;
} *root[21];

class linetree
{
    private:
    int ans,left,right,qc,tx,tt;

    void downit(tree *p)
    {
        if (p->lchild!=0)
        {
            if (p->turn==1)
            {
                p->lchild->turn=1-p->lchild->turn;
                p->lchild->num=p->lchild->len-p->lchild->num;
                p->rchild->turn=1-p->rchild->turn;
                p->rchild->num=p->rchild->len-p->rchild->num;
                p->turn=0;
            }
        }
    }
    void update(tree *p)
    {
        if (p->lchild==0) return;
        p->num=p->lchild->num+p->rchild->num;
    }
    void search(tree *p)
    {
        int l=p->left,r=p->right;
        if ((l>right)||(r<left)) return;
        downit(p);
        if ((l==left)&&(r<=right))
        {
            left=r+1;
            p->turn=1-p->turn;
            p->num=p->len-p->num;
            downit(p);
        }
        else
        {
            search(p->lchild);
            search(p->rchild);
            update(p);
        }
    }
    void sear(tree *p)
    {
        int l=p->left,r=p->right;
        if ((l>right)||(r<left)) return;
        downit(p);
        if ((l==left)&&(r<=right))
        {
            ans+=p->num;
            left=r+1;
        }
        else
        {
            sear(p->lchild);
            sear(p->rchild);
            update(p);
        }
    }
    void init(tree *p)
    {
        int l=p->left,r=p->right;
        if ((l>tt)||(r<tt)) return;
        downit(p);
        if (l==r) ++p->num; else
        {
            init(p->lchild);
            init(p->rchild);
            update(p);
        }
    }

    public:
    void maketree(tree *&node,int left,int right)
    {
        tree *p;
        p=new tree;
        p->lchild=0;p->rchild=0;
        p->left=left;p->right=right;
        p->len=right-left+1;
        p->turn=0;p->num=0;
        node=p;
        if (left==right) return;
        maketree(node->lchild,left,(left+right)/2);
        maketree(node->rchild,(left+right)/2+1,right);
    }
    void insert(tree *p,int place)
    {
        tt=place;
        init(p);
    }
    void turn(tree *p,int l,int r)
    {
        left=l;right=r;
        search(p);
    }
    int getsum(tree *p,int l,int r)
    {
        left=l;right=r;
        ans=0;
        sear(p);
        return ans;
    }
} Q;

int n,o,cs,m,flag,l,r;

int main()
{
    scanf("%d",&n);
    for (int i=0;i<=19;i++) Q.maketree(root[i],1,n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&cs);
        o=0;
        while (cs>0)
        {
            if (cs%2==1) Q.insert(root[o],i);
            cs/=2;o++;
        }
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&flag);
        if (flag==1)
        {
            scanf("%d %d",&l,&r);
            LL nowans=0;
            for (int i=0;i<=19;i++)
                nowans+=(LL)(1<<i)*(Q.getsum(root[i],l,r));
            printf("%I64d\n",nowans);
        }
        else
        {
            scanf("%d %d %d",&l,&r,&cs);
            for (int i=0;i<=19;i++)
            {
                if (cs%2==1)
                {
                    Q.turn(root[i],l,r);
                }
                cs/=2;
            }
        }

    }
    return 0;
}