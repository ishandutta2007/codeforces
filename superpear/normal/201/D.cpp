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

const int maxn=500050;

int n,lst,maxc,maxk,m,k,ic,tc,ccs;
int a[maxn],v[100005][16],f[100005][125],g[16][maxn];
char st[maxn];
string s[16],sc;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",st);
        lst=strlen(st);
        s[i]="";
        for (int j=0;j<lst;j++) s[i]+=st[j];
    }
    memset(v,0,sizeof(v));
    for (int i=0;i<(1<<n);i++)
        for (int j=1;j<=n;j++)
            if ((i>>(j-1))%2==0)
            {
                v[i][j]=0;
                for (int c=j+1;c<=n;c++)
                    if ((i>>(c-1))%2==1) ++v[i][j];
            }
    maxc=-1,maxk=0;
    scanf("%d",&m);
    for (int tt=1;tt<=m;tt++)
    {
        scanf("%d",&k);
        memset(a,0,sizeof(a));
        for (int i=1;i<=k;i++)
        {
            scanf("%s",st);
            lst=strlen(st);
            sc="";
            for (int j=0;j<lst;j++) sc+=st[j];
            for (int j=1;j<=n;j++)
                if (sc==s[j])
                {
                    a[i]=j;
                    break;
                }
        }
        for (int i=1;i<=n;i++)
        {
            g[i][k+1]=-1;
            for (int j=k;j>=1;j--)
                if (a[j]==i) g[i][j]=j; else g[i][j]=g[i][j+1];
        }
        memset(f,127,sizeof(f));
        f[0][0]=0;
        for (int i=0;i<(1<<n);i++)
            for (int j=0;j<=n*(n-1)/2;j++)
                if (f[i][j]!=biglongint)
                {
                    for (int c=1;c<=n;c++)
                        if ((i>>(c-1))%2==0)
                        {
                            ic=i|(1<<(c-1));
                            tc=g[c][f[i][j]+1];
                            if (tc==-1) continue;
                            f[ic][j+v[i][c]]=min(f[ic][j+v[i][c]],tc);
                        }
                }
        ccs=-1;
        for (int i=0;i<=n*(n-1)/2;i++)
            if (f[(1<<n)-1][i]!=biglongint)
            {
                ccs=i;
                break;
            }
        if (ccs!=-1)
        {
            if (n*(n-1)/2-ccs+1>maxc)
            {
                maxc=n*(n-1)/2-ccs+1;
                maxk=tt;
            }
        }
    }
    if (maxk==0)
        printf("Brand new problem!\n");
    else
    {
        printf("%d\n",maxk);
        printf("[:");
        for (int i=1;i<=maxc;i++)
            printf("|");
        printf(":]\n");
    }

    return 0;
}