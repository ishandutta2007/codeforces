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

const int maxn=200005;

int n,s,m,xc,yc,len,ccf,ll,rr,oo,ans,qzl,qzr,xc1,xc2,yc1,yc2,nt,e,o;
int dat[maxn],f[maxn],sa[maxn],rank[maxn],g[maxn],f1[maxn],m1[maxn],lca[maxn],po2[maxn];
PIII qll[maxn];
int rmq[maxn][20];

struct qiu
{
    int l,r,x1,y1,x2,y2;
} query[maxn];

struct tree
{
    int left,right;
    tree *lchild,*rchild;
    vector<int> f;
} *root;

qiu make_qiu(int a,int b,int c,int d,int e,int f)
{
    qiu cs;
    cs.l=a;cs.r=b;
    cs.x1=c;cs.y1=d;
    cs.x2=e;cs.y2=f;
    return cs;
}

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
        p->f.p_b(sa[left]);
    }
    else
    {
        maketree(node->lchild,left,(left+right)/2);
        maketree(node->rchild,(left+right)/2+1,right);
        p->f.resize(p->lchild->f.size()+p->rchild->f.size());
        merge(p->lchild->f.begin(),p->lchild->f.end(),p->rchild->f.begin(),p->rchild->f.end(),p->f.begin());
    }
}

void doit(tree *p)
{
    int l=p->left,r=p->right;
    vector<int>::iterator c1,c2;
    if ((l>qzr)||(r<qzl)) return;
    if ((l==qzl)&&(r<=qzr))
    {
        qzl=r+1;
        c1=l_b(p->f.begin(),p->f.end(),xc1);
        c2=l_b(p->f.begin(),p->f.end(),yc1+1);
        ans+=c2-c1;
        c1=l_b(p->f.begin(),p->f.end(),xc2);
        c2=l_b(p->f.begin(),p->f.end(),yc2+1);
        ans+=c2-c1;
    }
    else
    {
        doit(p->lchild);
        doit(p->rchild);
    }
}

void solveit(qiu t)
{
    int l=t.l,r=t.r;
    xc1=t.x1,yc1=t.y1,xc2=t.x2,yc2=t.y2;
    ans=0;
    qzl=l;qzr=r;
    doit(root);
    printf("%d\n",ans);
}

void makesa()
{
    for (int i=1;i<=s;i++) f1[i]=f[i];
    sort(f1+1,f1+s+1);
    m1[0]=0;f1[0]=-maxlongint;
    for (int i=1;i<=s;i++)
        if (f1[i]!=f1[i-1]) m1[i]=m1[i-1]+1; else m1[i]=m1[i-1];
    map<int,int> lss;
    map<int,int>::iterator lst;
    for (int i=1;i<=s;i++)
        lss.insert(m_p(f1[i],m1[i]));
    for (int i=1;i<=s;i++)
    {
        lst=lss.find(f[i]);
        rank[i]=lst->second;
    }
    //for (int i=1;i<=s;i++) cout<<rank[i]<<" ";cout<<endl;

    int e=1;
    while (e<=s)
    {
        for (int i=1;i<=s;i++)
            if (i+e<=s)
                qll[i]=m_p(m_p(rank[i],rank[i+e]),i);
            else
                qll[i]=m_p(m_p(rank[i],0),i);
        sort(qll+1,qll+s+1);
        m1[1]=1;
        for (int i=2;i<=s;i++)
            if (qll[i].first!=qll[i-1].first) m1[i]=m1[i-1]+1; else m1[i]=m1[i-1];
        for (int i=1;i<=s;i++)
            rank[qll[i].second]=m1[i];
        e*=2;
        //for (int i=1;i<=s;i++) cout<<rank[i]<<" ";cout<<endl;
        if (m1[s]==s) break;
    }
}

int getmin(int l,int r)
{
    if (l>r) return maxlongint;
    int c=po2[r-l+1];
    return min(rmq[l][c],rmq[r-(1<<c)+1][c]);
}

int main()
{
    //freopen("D.in","r",stdin);
    //freopen("D.out","w",stdout);

    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&dat[i]);

    s=n*2-1;
    for (int i=1;i<n;i++) f[i]=dat[i+1]-dat[i];
    f[n]=maxlongint;
    for (int i=n+1;i<=s;i++) f[i]=-f[i-n];
    makesa();
    for (int i=1;i<=s;i++) sa[rank[i]]=i;
    sa[0]=s+1;

    /*for (int i=1;i<=s;i++)
    {
        for (int j=sa[i];j<=s;j++)
            cout<<f[j]<<" ";
        cout<<endl;
    }*/

    lca[0]=0;
    for (int i=1;i<=s;i++)
    {
        nt=max(lca[rank[i-1]]-1,0);
        while ((sa[rank[i]-1]+nt<=s)&&(sa[rank[i]]+nt<=s)&&(f[sa[rank[i]-1]+nt]==f[sa[rank[i]]+nt])) ++nt;
        lca[rank[i]]=nt;
    }
    //for (int i=1;i<=s;i++)
    //    cout<<lca[i]<<endl;
    po2[1]=0;
    for (int i=2;i<=s;i++) po2[i]=po2[i/2]+1;
    memset(rmq,0,sizeof(rmq));
    for (int i=s;i>=1;i--)
    {
        rmq[i][0]=lca[i];
        e=1;o=1;
        while (i+e<=s)
        {
            rmq[i][o]=min(rmq[i][o-1],rmq[i+e][o-1]);
            ++o;e*=2;
        }
    }
    //for (int i=1;i<=s;i++) cout<<sa[i]<<endl;

    int left,right,mid;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        --yc;
        len=yc-xc+1;
        ccf=rank[xc];
        left=1;right=ccf;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (getmin(mid+1,ccf)>=len) right=mid-1; else left=mid+1;
        }
        ll=left;
        left=ccf;right=s;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (getmin(ccf+1,mid)>=len) left=mid+1; else right=mid-1;
        }
        rr=right;
        //cout<<ll<<" "<<rr<<endl;
        //cout<<ll<<" "<<rr<<" "<<n+1<<" "<<n+xc-len-1<<" "<<n+yc+2<<" "<<s-len+1<<endl;
        if (xc!=yc+1) query[i]=make_qiu(ll,rr,n+1,n+xc-len-1,n+yc+2,s-len+1);
                 else query[i]=make_qiu(ll,rr,n+1,n+xc-len,n+yc+2,s-len+1);
    }
    maketree(root,1,s);
    for (int i=1;i<=m;i++)
        solveit(query[i]);

    return 0;
}