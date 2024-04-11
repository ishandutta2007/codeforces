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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

bool lucky(int s)
{
    while (s>0)
    {
        if ((s%10!=4)&&(s%10!=7)) return false;
        s/=10;
    }
    return true;
}

vector<int> allluck;
int n,m,cs,xc,yc,delta,next[20000],data[100005];
string s;

struct tree
{
    int left,right,delta,sm;
    PII num,min;
    tree *lchild,*rchild;
} *root;

class linetree
{
    private:
    int nm,nt,jr,left,right,ttans,ttmin;
    PII t;

    void update(tree *p)
    {
        p->min=min(p->lchild->min,p->rchild->min);
        if (p->lchild->min.first==p->rchild->min.first) p->sm=p->lchild->sm+p->rchild->sm; else
        if (p->lchild->min.first<p->rchild->min.first) p->sm=p->lchild->sm; else p->sm=p->rchild->sm;
    }

    void downit(tree *p)
    {
        if (p->delta!=0)
        {
            if (p->lchild!=0)
            {
                p->lchild->num.first+=p->delta;
                p->lchild->min.first-=p->delta;
                p->lchild->delta+=p->delta;
                p->rchild->num.first+=p->delta;
                p->rchild->min.first-=p->delta;
                p->rchild->delta+=p->delta;
            }
            p->delta=0;
        }
    }
    //For Insert
    void dfs1(tree *p)
    {
        int l=p->left,r=p->right;
        if ((l>jr)||(r<jr)) return;
        downit(p);
        if (l==r)
        {
            p->num=m_p(nm,nt);
            p->min=m_p(nt-nm,l);
        }
        else
        {
            dfs1(p->lchild);
            dfs1(p->rchild);
            update(p);
        }
    }

    //For Getsum
    void dfs2(tree *p)
    {
        int l=p->left,r=p->right;
        if ((l>right)||(r<left)) return;
        downit(p);
        if ((l==left)&&(r<=right))
        {
            if (p->min.first<ttmin) ttmin=p->min.first,ttans=p->sm;
            else if (p->min.first==ttmin) ttans+=p->sm;
            left=r+1;
        }
        else
        {
            dfs2(p->lchild);
            dfs2(p->rchild);
            update(p);
        }
    }

    //For mplus
    void dfs3(tree *p)
    {
        int l=p->left,r=p->right;
        if ((l>right)||(r<left)) return;
        downit(p);
        if ((l==left)&&(r<=right))
        {
            p->num.first+=nm;
            p->min.first-=nm;
            p->delta+=nm;
            downit(p);
            left=r+1;
        }
        else
        {
            dfs3(p->lchild);
            dfs3(p->rchild);
            update(p);
        }
    }

    void findit(tree *p)
    {
        int l=p->left,r=p->right;
        if ((l>nm)||(r<nm)) return;
        downit(p);
        if (l==r)
        {
            t=p->num;
            //cout<<l<<" "<<t.first<<" "<<t.second<<endl;
            while (t.second<t.first) t.second=next[t.second];
            p->num=t;
            p->min=m_p(t.second-t.first,l);
        }
        else
        {
            findit(p->lchild);
            findit(p->rchild);
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
        p->min=m_p(maxlongint,0);
        p->num=m_p(0,0);
        p->delta=0;
        p->sm=1;
        node=p;
        if (left==right) return;
        maketree(node->lchild,left,(left+right)/2);
        maketree(node->rchild,(left+right)/2+1,right);
    }

    void insert(tree *root,int place,int number,int neart)
    {
        jr=place;
        nm=number;
        nt=neart;
        dfs1(root);
    }

    int getsum(tree *root,int leftw,int rightw)
    {
        ttans=0;ttmin=maxlongint;
        left=leftw;right=rightw;
        dfs2(root);
        if (ttmin!=0) return 0; else return ttans;
    }

    void mplus(tree *root,int leftw,int rightw,int delta)
    {
        left=leftw;right=rightw;
        nm=delta;
        dfs3(root);
    }

    void updatec(tree *root)
    {
        while (root->min.first<0)
        {
            //cout<<root->min.first<<endl;
            nm=root->min.second;
            findit(root);
        }
    }
} Q;

int main()
{
    //freopen("E.in","r",stdin);
    for (int i=1;i<=10000;i++)
        if (lucky(i)) allluck.p_b(i);
    allluck.p_b(maxlongint);
    for (int i=0;i<30;i++)
        next[allluck[i]]=allluck[i+1];
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&data[i]);
    Q.maketree(root,1,n);
    for (int i=1;i<=n;i++)
    {
        cs=0;
        for (int j=0;j<=30;j++)
            if (data[i]<=allluck[j])
            {
                cs=j;
                break;
            }
        Q.insert(root,i,data[i],allluck[cs]);
    }
    for (int i=1;i<=m;i++)
    {
        cin>>s;
        if (s=="count")
        {
            scanf("%d %d",&xc,&yc);
            cout<<Q.getsum(root,xc,yc)<<endl;
        }
        else
        {
            scanf("%d %d %d",&xc,&yc,&delta);
            Q.mplus(root,xc,yc,delta);
            Q.updatec(root);
        }
    }

    return 0;
}