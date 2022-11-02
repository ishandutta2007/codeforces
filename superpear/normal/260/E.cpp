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

const int maxn=100005;

struct tree
{
    tree *lchild,*rchild;
    int left,right;
    vector<int> f;
} *root;

map<int,int> lsh;
map<int,int>::iterator lshg;
PII point[maxn];
int bakx[maxn],baky[maxn],m1[maxn],numx[maxn],numy[maxn],sumx[maxn],sumy[maxn],xc[maxn],yc[maxn],whichx[maxn],whichy[maxn];
int nt[10],b[10],dat[10];
int n,j,k,xcs,ycs,qzql,qzqr,qzl,qzr,qzans,ttflag;

void maketree(tree *&node,int left,int right)
{
    tree *p;
    p=new tree;
    p->lchild=0;p->rchild=0;
    p->left=left;p->right=right;
    p->f.clear();
    node=p;
    if (left==right)
    {
        p->f.p_b(yc[left]);
        return;
    }
    maketree(node->lchild,left,(left+right)/2);
    maketree(node->rchild,(left+right)/2+1,right);
    p->f.resize(p->lchild->f.size()+p->rchild->f.size());
    merge(p->lchild->f.begin(),p->lchild->f.end(),p->rchild->f.begin(),p->rchild->f.end(),p->f.begin());
}

void search(tree *p)
{
    int l=p->left,r=p->right;
    vector<int>::iterator c1,c2;
    if ((l>qzr)||(r<qzl)) return;
    if ((l==qzl)&&(r<=qzr))
    {
        qzl=r+1;
        c1=lower_bound(p->f.begin(),p->f.end(),qzql);
        c2=lower_bound(p->f.begin(),p->f.end(),qzqr+1);
        qzans+=c2-c1;
    }
    else
    {
        search(p->lchild);
        search(p->rchild);
    }
}

int getnum(int l,int r,int ql,int qr)
{
    qzl=l;qzr=r;qzans=0;qzql=ql;qzqr=qr;
    search(root);
    return qzans;
}

void doit()
{
    for (int i=1;i<=9;i++) nt[i]=dat[b[i]];
    int c1,c2,c3,c4;
    c1=nt[1]+nt[4]+nt[7];
    c2=nt[3]+nt[6]+nt[9];
    c3=nt[1]+nt[2]+nt[3];
    c4=nt[7]+nt[8]+nt[9];
    //if ((nt[1]==1)&&(nt[2]==2)&&(nt[3]==2)&&(nt[4]==1)&&(nt[5]==2)&&(nt[6]==2)&&(nt[7]==1)&&(nt[8]==3)&&(nt[9]==1))
    //    cout<<getnum(1,3,1,3)<<endl;
    //    cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<endl;
    //for (int i=1;i<=9;i++) cout<<nt[i]<<" ";cout<<endl
    if (bakx[c1]==bakx[c1+1]) return;
    if (bakx[n-c2+1]==bakx[n-c2]) return;
    if (baky[c3]==baky[c3+1]) return;
    c3=baky[c3];
    if (baky[n-c4+1]==baky[n-c4]) return;
    c4=baky[n-c4+1];
    //if ((nt[1]==1)&&(nt[2]==2)&&(nt[3]==2)&&(nt[4]==1)&&(nt[5]==2)&&(nt[6]==2)&&(nt[7]==1)&&(nt[8]==3)&&(nt[9]==1))
    //    cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<endl;
    if ((getnum(1,c1,1,c3)==nt[1])&&
        (getnum(n-c2+1,n,1,c3)==nt[3])&&
        (getnum(1,c1,c4,n)==nt[7])&&
        (getnum(n-c2+1,n,c4,n)==nt[9]))
        {
            //cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<endl;
            ttflag=0;
            printf("%.10lf %.10lf\n",whichx[bakx[c1]]+0.1,whichx[bakx[n-c2+1]]-0.1);
            printf("%.10lf %.10lf\n",whichy[c3]+0.1,whichy[c4]-0.1);
        }
}

int main()
{
    //freopen("E.in","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d",&xcs,&ycs);
        bakx[i]=xcs;baky[i]=ycs;
        point[i]=m_p(xcs,ycs);
    }
    sort(point+1,point+n+1);
    for (int i=1;i<=9;i++) scanf("%d",&dat[i]);
    sort(bakx+1,bakx+n+1);
    sort(baky+1,baky+n+1);
    lsh.clear();
    m1[1]=1;
    lsh.insert(m_p(bakx[1],m1[1]));
    for (int i=2;i<=n;i++)
    {
        if (bakx[i]!=bakx[i-1]) m1[i]=m1[i-1]+1; else m1[i]=m1[i-1];
        whichx[m1[i]]=bakx[i];
        lsh.insert(m_p(bakx[i],m1[i]));
    }
    for (int i=1;i<=n;i++)
    {
        lshg=lsh.find(point[i].w1);
        xc[i]=lshg->second;
        lshg=lsh.find(bakx[i]);
        bakx[i]=lshg->second;
    }
    lsh.clear();
    m1[1]=1;
    lsh.insert(m_p(baky[1],m1[1]));
    for (int i=2;i<=n;i++)
    {
        if (baky[i]!=baky[i-1]) m1[i]=m1[i-1]+1; else m1[i]=m1[i-1];
        whichy[m1[i]]=baky[i];
        lsh.insert(m_p(baky[i],m1[i]));
    }
    for (int i=1;i<=n;i++)
    {
        lshg=lsh.find(point[i].w2);
        yc[i]=lshg->second;
        lshg=lsh.find(baky[i]);
        baky[i]=lshg->second;
    }
    //for (int i=1;i<=n;i++) cout<<xc[i]<<" "<<yc[i]<<endl;
    /*memset(numx,0,sizeof(numx));
    memset(numy,0,sizeof(numy));
    memset(sumx,0,sizeof(sumx));
    memset(sumy,0,sizeof(sumy));
    for (int i=1;i<=n;i++) ++numx[xc[i]],++numy[yc[i]];
    for (int i=1;i<=n;i++) sumx[i]=sumx[i-1]+numx[i],sumy[i]=sumy[i-1]+numy[i];*/

    maketree(root,1,n);

    for (int i=0;i<=9;i++) b[i]=i;
    ttflag=1;
    while (b[0]==0)
    {
        //for (int i=1;i<=9;i++) cout<<b[i]<<" ";cout<<endl;
        doit();
        if (ttflag==0)
            return 0;
        j=9;
        while (b[j-1]>b[j]) --j;
        k=9;
        while (b[j-1]>b[k]) --k;
        swap(b[j-1],b[k]);
        for (int p=j;p<=9;p++)
            for (int q=p+1;q<=9;q++)
                if (b[p]>b[q]) swap(b[p],b[q]);
    }
    printf("-1\n");

    return 0;
}