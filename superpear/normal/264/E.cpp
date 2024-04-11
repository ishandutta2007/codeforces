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

const int maxn=100010;

struct tree
{
    tree *lchild,*rchild;
    int left,right,max;
} *rootx,*rooty;

set<PII> sortx,sorty;
set<PII>::iterator lsg;
int lsx[15],lsy[15],lsans[15];
int m,n,flag,cs,o,xc,yc,ntr;

void maketree(tree *&node,int left,int right)
{
    tree *p=new tree;
    p->lchild=0,p->rchild=0;
    p->left=left,p->right=right;
    p->max=0;
    node=p;
    if (left==right) return;
    maketree(node->lchild,left,(left+right)/2);
    maketree(node->rchild,(left+right)/2+1,right);
}

int getmax(tree *p,int left,int right)
{
    if (left>right) return 0;
    int l=p->left,r=p->right;
    if ((l==left)&&(r==right)) return p->max;
    return max(
               getmax(p->lchild,left,min(right,p->lchild->right)),
               getmax(p->rchild,max(left,p->rchild->left),right)
               );
}

void change(tree *p,int place,int num)
{
    int l=p->left,r=p->right;
    if ((l>place)||(r<place)) return;
    if (l==r)
        p->max=num;
    else
    {
        change(p->lchild,place,num);
        change(p->rchild,place,num);
        p->max=max(p->lchild->max,p->rchild->max);
    }
}

int main()
{
    //freopen("E.in","r",stdin);

    maketree(rootx,1,maxn);
    maketree(rooty,1,maxn*2);

    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&flag);
        if (flag==1)
        {
            scanf("%d %d",&xc,&yc);
            yc=yc+m-i;
            o=0;
            while (sorty.size()>0)
            {
                lsg=sorty.begin();
                if (lsg->first>yc) break;
                ++o;
                lsx[o]=lsg->second;
                lsy[o]=lsg->first;
                change(rootx,lsx[o],0);
                sorty.erase(lsg);
            }
            ntr=getmax(rootx,xc+1,maxn)+1;
            change(rootx,xc,ntr);
            change(rooty,yc,ntr);
            for (int j=o;j>=1;j--)
            {
                ntr=getmax(rootx,lsx[j]+1,maxn)+1;
                change(rootx,lsx[j],ntr);
                change(rooty,lsy[j],ntr);
                sorty.insert(m_p(lsy[j],lsx[j]));
            }
            sorty.insert(m_p(yc,xc));
            sortx.insert(m_p(xc,yc));
        }
        else
        {
            scanf("%d",&cs);
            for (int j=1;j<=cs;j++)
            {
                lsx[j]=sortx.begin()->first;
                lsy[j]=sortx.begin()->second;
                change(rooty,lsy[j],0);
                change(rootx,lsx[j],0);
                sortx.erase(sortx.begin());
            }
            for (int j=cs-1;j>=1;j--)
            {
                ntr=getmax(rooty,lsy[j]+1,maxn*2)+1;
                change(rooty,lsy[j],ntr);
                change(rootx,lsx[j],ntr);
                sortx.insert(m_p(lsx[j],lsy[j]));
            }
            lsg=sorty.find(m_p(lsy[cs],lsx[cs]));
            sorty.erase(lsg);
        }
        printf("%d\n",rootx->max);
    }

    return 0;
}