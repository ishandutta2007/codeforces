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

const int bigp=12345;

PII limit[140];
vector<int> f[140];
LL n;
char ch;
int m,c,j,xc,yc,ts,o,oo,flag,ans;
int b[140],use[140],use1[140],fou[140];

struct matrix
{
    int f[130][130];
} a,q,g[70];

matrix cheng(matrix a,matrix b)
{
    matrix c;
    for (int i=0;i<130;i++)
        for (int j=0;j<130;j++)
            c.f[i][j]=0;
    for (int i=1;i<=ts;i++)
        for (int j=1;j<=ts;j++)
            for (int k=1;k<=ts;k++)
                c.f[i][j]=(c.f[i][j]+(LL)a.f[i][k]*b.f[k][j])%bigp;
    return c;
}

bool equal(vector<int> a,vector<int> b)
{
    for (int i=0;i<a.size();i++)
        if (a[i]!=b[i]) return false;
    return true;
}

int main()
{
    scanf("%I64d %d",&n,&m);
    c=0;
    ts=1;
    memset(use,0,sizeof(use));
    ch=getchar();
    for (int i=1;i<=m;i++)
    {
        ch=getchar();
        scanf("%d",&yc);
        xc=ch;
        use[xc-64]=1;
        ts*=yc;
        ch=getchar();
        if (yc>1)
        {
            ++c,limit[c]=m_p(xc-64,yc);
        }
        else
            fou[xc-64]=1;
    }
    memset(b,0,sizeof(b));
    o=0;
    while (b[0]==0)
    {
        ++o;
        for (int i=1;i<=c;i++) f[o].p_b(b[i]);
        j=c;
        while (b[j]==limit[j].w2-1)
        {
            b[j]=0;
            --j;
        }
        ++b[j];
    }
    for (int i=0;i<130;i++)
        for (int j=0;j<130;j++)
            a.f[i][j]=0;
    for (int i=1;i<=ts;i++)
        for (int j=1;j<=26;j++)
        {
            if (use[j]==0) continue;
            vector<int> tt;
            for (int k=1;k<=c;k++) tt.p_b(f[i][k-1]);
            for (int k=1;k<=c;k++)
                if (limit[k].w1==j) ++tt[k-1],tt[k-1]%=limit[k].w2;
            for (int e=1;e<=ts;e++)
                if (equal(tt,f[e]))
                {
                    ++a.f[i][e];
                    break;
                }
        }
    g[0]=a;
    for (int i=1;i<=69;i++) g[i]=cheng(g[i-1],g[i-1]);
    for (int i=1;i<=ts;i++)
        for (int j=1;j<=ts;j++)
            if (i==j) q.f[i][j]=1; else q.f[i][j]=0;
    oo=0;
    while (n>0)
    {
        if (n%2==1) q=cheng(q,g[oo]);
        ++oo,n/=2;
    }
    ans=0;
    for (int i=1;i<=ts;i++)
    {
        memset(use1,0,sizeof(use1));
        for (int j=1;j<=26;j++) use1[j]=use[j];
        for (int j=1;j<=c;j++) if (f[i][j-1]==0) use1[limit[j].w1]=0;
        flag=1;
        for (int j=1;j<=26;j++)
            if ((use1[j]==1)&&(fou[j]==0)) {flag=0;break;}
        if (flag==1) ans=(ans+q.f[1][i])%bigp;
    }
    cout<<ans<<endl;

    return 0;
}