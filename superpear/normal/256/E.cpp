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

const int bigp=777777777;

struct tree
{
    int left,right;
    tree *lchild,*rchild;
    int a[4][4];
} *root;

int n,m,v,t,ans,g[4][4];

void maketree(tree *&node,int left,int right)
{
    tree *p;
    p=new tree;
    p->left=left;
    p->right=right;
    p->lchild=0;
    p->rchild=0;
    for (int i=0;i<=3;i++)
        for (int j=0;j<=3;j++)
            p->a[i][j]=0;
    node=p;
    //cout<<left<<" "<<right<<endl;
    if (left==right)
    {
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
                if (i==j) p->a[i][j]=1; else p->a[i][j]=0;
    }
    else
    {
        maketree(node->lchild,left,(left+right)/2);
        maketree(node->rchild,(left+right)/2+1,right);
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
                for (int k=1;k<=3;k++)
                    for (int s=1;s<=3;s++)
                        if (g[k][s]==1)
                            p->a[i][j]=(p->a[i][j]+(LL)(p->lchild->a[i][k])*(p->rchild->a[s][j]))%bigp;
    }
}

void change(tree *p)
{
    int l=p->left,r=p->right;
    if ((l>v)||(r<v)) return;
    if (l==r)
    {
        if (t>0)
        {
            for (int i=1;i<=3;i++)
                for (int j=1;j<=3;j++)
                    p->a[i][j]=0;
            p->a[t][t]=1;
        }
        else
        {
            for (int i=1;i<=3;i++)
                for (int j=1;j<=3;j++)
                    if (i==j) p->a[i][j]=1; else p->a[i][j]=0;
        }
    }
    else
    {
        change(p->lchild);
        change(p->rchild);
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
                p->a[i][j]=0;
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
                for (int k=1;k<=3;k++)
                    for (int s=1;s<=3;s++)
                        if (g[k][s]==1)
                            p->a[i][j]=(p->a[i][j]+(LL)(p->lchild->a[i][k])*(p->rchild->a[s][j]))%bigp;
    }
}

int main()
{
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
            scanf("%d",&g[i][j]);
    maketree(root,1,n);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&v,&t);
        change(root);
        ans=0;
        for (int j=1;j<=3;j++)
            for (int k=1;k<=3;k++)
                ans=(ans+(LL)(root->a[j][k]))%bigp;
        printf("%d\n",ans);
    }

    return 0;
}