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

const int maxn=100005;
const int bigp=1000000007;

struct tree
{
    int sum[6];
    int delta,len;
} node[maxn*4];

char ch;
int n,m,lc,rc,xc,ll,rr,ttsum,data[maxn];
int sm[6][maxn+10];
int combc[10][10],powcc[maxn+10][10];

int comb(int n,int k)
{
    int e=1;
    for (int i=n;i>=n-k+1;i--) e*=i;
    for (int i=1;i<=k;i++) e/=i;
    return e;
}

int powc(int n,int k)
{
    int e=1;
    for (int i=1;i<=k;i++) e=(LL)e*n%bigp;
    return e;
}

void update(int p)
{
    int q=node[p*2].len;
    for (int i=0;i<=5;i++)
    {
        node[p].sum[i]=node[p*2].sum[i];
        for (int j=0;j<=i;j++)
            node[p].sum[i]=(node[p].sum[i]+
                            ((LL)node[p*2+1].sum[j]*powcc[q][i-j]%bigp)*(LL)combc[i][j]%bigp
                            )%bigp;
    }
}

void downit(int p)
{
    if (node[p].len==1) return;
    if (node[p].delta!=-1)
    {
        node[p*2].delta=node[p].delta;
        node[p*2+1].delta=node[p].delta;
        for (int i=0;i<=5;i++)
        {
            node[p*2].sum[i]=(LL)node[p].delta*sm[i][node[p*2].len]%bigp;
            node[p*2+1].sum[i]=(LL)node[p].delta*sm[i][node[p*2+1].len]%bigp;
        }
        node[p].delta=-1;
    }
}

void maketree(int p,int left,int right)
{
    node[p].delta=-1;
    node[p].len=right-left+1;
    for (int i=0;i<=5;i++) node[p].sum[i]=0;
    if (left==right)
    {
        for (int i=0;i<=5;i++)
            node[p].sum[i]=data[left];
    }
    else
    {
        maketree(p*2,left,(left+right)/2);
        maketree(p*2+1,(left+right)/2+1,right);
        update(p);
    }
}

void shua(int p,int left,int right,int num)
{
    if ((ll>right)||(rr<left)) return;
    downit(p);
    if ((ll==left)&&(right<=rr))
    {
        node[p].delta=num;
        for (int i=0;i<=5;i++)
            node[p].sum[i]=(LL)num*sm[i][node[p].len]%bigp;
        ll=right+1;
    }
    else
    {
        shua(p*2,left,(left+right)/2,num);
        shua(p*2+1,(left+right)/2+1,right,num);
        update(p);
    }
}

void search(int p,int left,int right,int num)
{
    int q=ll-lc;
    if ((ll>right)||(rr<left)) return;
    downit(p);
    if ((ll==left)&&(right<=rr))
    {
        for (int i=0;i<=num;i++)
            ttsum=(ttsum+
                    ((LL)node[p].sum[i]*powcc[q][num-i]%bigp)*(LL)combc[num][i]%bigp
                    )%bigp;
        ll=right+1;
    }
    else
    {
        search(p*2,left,(left+right)/2,num);
        search(p*2+1,(left+right)/2+1,right,num);
        update(p);
    }
}

int main()
{
    memset(sm,0,sizeof(sm));
    for (int i=0;i<=5;i++)
    {
        sm[i][0]=0;
        for (int j=1;j<=maxn-1;j++)
            sm[i][j]=(sm[i][j-1]+powc(j,i))%bigp;
    }
    for (int i=0;i<=5;i++)
        for (int j=0;j<=5;j++)
            combc[i][j]=comb(i,j);
    for (int i=0;i<=maxn;i++)
        for (int j=0;j<=5;j++)
            powcc[i][j]=powc(i,j);

    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&data[i]);

    maketree(1,1,n);

    scanf("%c",&ch);
    for (int i=1;i<=m;i++)
    {
        scanf("%c %d %d %d",&ch,&lc,&rc,&xc);
        if (ch=='=')
        {
            ll=lc,rr=rc;
            shua(1,1,n,xc);
        }
        else
        {
            ttsum=0,ll=lc,rr=rc;
            search(1,1,n,xc);
            printf("%d\n",ttsum);
        }
        scanf("%c",&ch);
    }

    return 0;
}