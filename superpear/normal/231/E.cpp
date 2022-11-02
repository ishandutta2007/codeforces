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

#define maxlongint 2147483647
#define biglongint 2139062143

using namespace std;

const int bigp=1000000007;
const int maxn=120000;

struct ljb
{
    int dest;
    ljb *next;
};

struct tree
{
    int left,right,min,mink;
    tree *lchild,*rchild;
};

tree *root;
ljb *p,*head[maxn],*tail[maxn],*head1[maxn],*tail1[maxn];
int u[maxn*5],v[maxn*5],stackc[maxn],hash[maxn],father[maxn],first[maxn],last[maxn],biao[maxn],pow2[maxn],sum[maxn],jq[maxn];
int m,n,xc,yc,o,top,dl,lll,rrr,mmm1,mmmk,qs,qk;

void push1(int x,int y)
{
    ljb *p;
    p=new ljb;
    p->dest=y;p->next=0;
    tail1[x]->next=p;tail1[x]=p;
}

void push(int x,int y)
{
    ljb *p;
    p=new ljb;
    p->dest=y;p->next=0;
    tail[x]->next=p;tail[x]=p;
}

void dfs1(int s,int fa,int depth)
{
    ljb *p;
    int sc;
    ++top;stackc[top]=s;
    hash[s]=1;jq[s]=depth;
    p=head1[s]->next;
    while (p!=0)
    {
        if (p->dest!=fa)
        {
            if (hash[p->dest]==0) dfs1(p->dest,s,depth+1); else
            if (jq[p->dest]<depth)
            {
                sc=top;++o;
                while (stackc[sc]!=p->dest)
                {
                    biao[stackc[sc]]=o;
                    --sc;
                }
                biao[p->dest]=o;
            }
        }
        p=p->next;
    }
    --top;
}

void dfs2(int s,int depth,int nowsum)
{
    ljb *p;
    p=head[s]->next;
    hash[s]=1;
    ++dl;u[dl]=depth;v[dl]=s;
    first[s]=dl;
    last[s]=dl;
    sum[s]=nowsum;
    while (p!=0)
    {
        if (hash[p->dest]==0)
        {
            father[p->dest]=s;
            if (p->dest<=qk) dfs2(p->dest,depth+1,nowsum+1); else dfs2(p->dest,depth+1,nowsum);
            ++dl;u[dl]=depth;v[dl]=s;
            last[s]=dl;
        }
        p=p->next;
    }

}

void maketree(tree *&node,int left,int right)
{
    tree *p;
    p=new tree;
    p->left=left;
    p->right=right;
    p->lchild=0;
    p->rchild=0;
    node=p;
    if (left==right)
    {
        p->min=u[left];p->mink=v[left];
    }
    else
    {
        maketree(node->lchild,left,(left+right)/2);
        maketree(node->rchild,(left+right)/2+1,right);
        if (p->lchild->min<p->rchild->min)
        {
            p->min=p->lchild->min;p->mink=p->lchild->mink;
        }
        else
        {
            p->min=p->rchild->min;p->mink=p->rchild->mink;
        }
    }
}

void getmin(tree *p)
{
    int left,right;
    left=p->left;right=p->right;
    if ((left>rrr)||(right<lll)) return;
    if ((left==lll)&&(right<=rrr))
    {
        if (p->min<mmm1)
        {
            mmm1=p->min;mmmk=p->mink;
        }
        lll=right+1;
    }
    else
    {
        getmin(p->lchild);
        getmin(p->rchild);
    }
}

int main()
{
    //freopen("E.in","r",stdin);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        p=new ljb;
        p->dest=0;p->next=0;
        head1[i]=p;tail1[i]=p;
    }
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        push1(xc,yc);
        push1(yc,xc);
    }
    memset(biao,0,sizeof(biao));
    memset(hash,0,sizeof(hash));
    o=0;
    top=0;
    memset(jq,0,sizeof(jq));
    dfs1(1,0,1);
    qk=o;
    for (int i=1;i<=n;i++) if (biao[i]==0) {++o;biao[i]=o;}
    //for (int i=1;i<=n;i++) cout<<biao[i]<<" ";cout<<endl;
    for (int i=1;i<=o;i++)
    {
        p=new ljb;
        p->dest=0;p->next=0;
        head[i]=p;tail[i]=p;
    }
    for (int i=1;i<=n;i++)
    {
        p=head1[i]->next;
        while (p!=0)
        {
            if (biao[i]!=biao[p->dest])
            {
                push(biao[i],biao[p->dest]);
                push(biao[p->dest],biao[i]);
            }
            p=p->next;
        }
    }
    n=o;
    memset(sum,0,sizeof(sum));
    dl=0;
    for (int i=1;i<=n;i++) {first[i]=maxlongint;last[i]=0;}
    memset(hash,0,sizeof(hash));
    memset(father,0,sizeof(father));
    if (qk>0) dfs2(1,1,1); else dfs2(1,1,0);

    pow2[0]=1;
    for (int i=1;i<=110000;i++) pow2[i]=(pow2[i-1]*2)%bigp;

    root=0;
    maketree(root,1,dl);

    scanf("%d",&qs);
    for (int i=1;i<=qs;i++)
    {
        scanf("%d %d",&xc,&yc);
        xc=biao[xc];yc=biao[yc];
        lll=first[xc];rrr=last[yc];
        if (lll>rrr) {lll=first[yc];rrr=last[xc];}
        mmm1=maxlongint;mmmk=0;
        getmin(root);
        //cout<<mmmk<<" ff "<<lll<<" "<<rrr<<endl;
        printf("%d\n",pow2[sum[xc]+sum[yc]-sum[mmmk]-sum[father[mmmk]]]);
    }

    return 0;
}