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

const int maxn=100005;

struct four
{
    int x,y,w,b;
} que[maxn];

struct tree
{
    int left,right,max;
    tree *lchild,*rchild;
} *root;

PIII a[maxn];
map<int,int> fage;
map<int,int>::iterator gage;
int n,k,lsh,nw,nt,na,t1,t2,agen,e,o,q,xc,yc,ff,ll,rr,next;
int respon[maxn],age[maxn],bak[maxn],bigans[maxn],newage[maxn],f[maxn],powc[maxn],dta[maxn],lsans[maxn];
int qjl,qjr,qjans,qjplace,qjnumber;

void mplus(int s)
{
    while (s<=n)
    {
        ++f[s];
        s+=s&(-s);
    }
}

int getsum(int s)
{
    int sum=0;
    while (s>0)
    {
        sum+=f[s];
        s-=s&(-s);
    }
    return sum;
}

void maketree(tree *&node,int left,int right)
{
    tree *p;
    p=new tree;
    p->left=left;p->right=right;
    p->max=-maxlongint;
    p->lchild=0;p->rchild=0;
    node=p;
    if (left==right) return;
    maketree(node->lchild,left,(left+right)/2);
    maketree(node->rchild,(left+right)/2+1,right);
}

void dfs1(tree *p)
{
    int l=p->left,r=p->right;
    if ((l>qjplace)||(r<qjplace)) return;
    if (l==r)
    {
        p->max=max(p->max,qjnumber);
    }
    else
    {
        dfs1(p->lchild);
        dfs1(p->rchild);
        p->max=max(p->lchild->max,p->rchild->max);
    }
}

void plmax(int place,int number)
{
    qjplace=place;
    qjnumber=number;
    dfs1(root);
}

void dfs2(tree *p)
{
    int l=p->left,r=p->right;
    if ((l>qjr)||(r<qjl)) return;
    if ((l==qjl)&&(r<=qjr))
    {
        qjans=max(qjans,p->max);
        qjl=r+1;
    }
    else
    {
        dfs2(p->lchild);
        dfs2(p->rchild);
    }
}

int getmax(int left,int right)
{
    qjl=left;
    qjr=right;
    qjans=-maxlongint;
    dfs2(root);
    return qjans;
}

bool cmp(const four &a, const four &b)
{
    return a.w>b.w;
}

int main()
{
    //freopen("E.in","r",stdin);
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&respon[i]);
    for (int i=1;i<=n;i++) scanf("%d",&age[i]);
    for (int i=1;i<=n;i++) bak[i]=age[i];
    sort(bak+1,bak+n+1);
    lsh=0;bak[0]=-maxlongint;
    for (int i=1;i<=n;i++)
        if (bak[i]!=bak[i-1])
        {
            ++lsh;
            fage.insert(m_p(bak[i],lsh));
        }
    for (int i=1;i<=n;i++)
    {
        gage=fage.find(age[i]);
        newage[i]=gage->second;
    }
    for (int i=1;i<=n;i++) a[i]=m_p(m_p(respon[i],newage[i]),i);
    sort(a+1,a+n+1);
    memset(f,0,sizeof(f));
    nw=1;
    while (nw<=n)
    {
        nt=nw;
        mplus(a[nw].first.second);
        while (a[nt+1].first.first==a[nt].first.first)
        {
            mplus(a[nt+1].first.second);
            ++nt;
        }
        for (int i=nw;i<=nt;i++)
        {
            na=age[a[i].second];
            gage=fage.l_b(na-k);
            t1=gage->second;
            gage=fage.l_b(na+k+1);
            gage--;
            t2=gage->second;
            bigans[a[i].second]=getsum(t2)-getsum(t1-1);
        }
        nw=nt+1;
    }
    //for (int i=1;i<=n;i++) cout<<bigans[i]<<endl;
    memset(dta,0,sizeof(dta));
    agen=0;
    for (int i=1;i<=n;i++) agen=max(agen,newage[i]),dta[newage[i]]=max(dta[newage[i]],bigans[i]);

    powc[1]=0;
    for (int i=2;i<=n;i++) powc[i]=powc[i/2]+1;
    scanf("%d",&q);
    for (int i=1;i<=q;i++)
    {
        scanf("%d %d",&xc,&yc);
        ff=-1;
        if (respon[xc]>=respon[yc])
        {
            if (abs(age[xc]-age[yc])<=k) ff=max(ff,bigans[xc]);
        }
        if (respon[xc]<=respon[yc])
        {
            if (abs(age[xc]-age[yc])<=k) ff=max(ff,bigans[yc]);
        }
        lsans[i]=ff;
        ll=max(age[xc],age[yc])-k;
        rr=min(age[xc],age[yc])+k;
        gage=fage.l_b(ll);
        ll=gage->second;
        gage=fage.l_b(rr+1);
        gage--;
        rr=gage->second;
        que[i].x=ll;que[i].y=rr;que[i].w=max(respon[xc],respon[yc]);que[i].b=i;
    }
    sort(que+1,que+q+1,cmp);
    maketree(root,1,agen);
    next=n;
    for (int i=1;i<=q;i++)
    {
        if (que[i].x>que[i].y) continue;
        while ((next>=1)&&(a[next].first.first>=que[i].w)) plmax(a[next].first.second,bigans[a[next].second]),--next;
        lsans[que[i].b]=max(lsans[que[i].b],getmax(que[i].x,que[i].y));
    }
    for (int i=1;i<=q;i++) printf("%d\n",lsans[i]);

    return 0;
}