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

const int maxn=10000;

vector<int> pans;
vector<PII> f[maxn+10];
int m,xc,yc,ltk,ttk,rc,fc,ssc,k1,k2,k3;
int hash[maxn+10],inp[maxn+10],where[maxn+10],u[maxn+10],pre[maxn+10];
PII biao[maxn+10];

void print()
{
    printf("%d\n",pans.size());
    for (int i=0;i<pans.size();i++)
    {
        if (i!=0) printf(" ");
        printf("%d",pans[i]);
    }
    printf("\n");
}

void doit(int s)
{
    for (int i=0;i<f[s].size();i++)
        if (hash[f[s][i].w2]==0)
        {
            hash[f[s][i].w2]=1;
            doit(f[s][i].w1);
            pans.p_b(f[s][i].w2);
        }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(inp,0,sizeof(inp));
    memset(hash,0,sizeof(hash));
    scanf("%d",&m);
    if (m==1)
    {
        printf("-1\n");
        return 0;
    }
    int flag=0;
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        if ((xc==1371)&&(yc==2109)) flag=1;
        ++inp[xc];++inp[yc];
        if (xc>yc) swap(xc,yc);
        f[xc].p_b(m_p(yc,i));
        f[yc].p_b(m_p(xc,i));
    }
    memset(where,0,sizeof(where));
    ltk=0;ttk=0;
    for (int i=1;i<=maxn;i++)
        if (where[i]==0)
        {
            ++ltk;
            rc=1;fc=1;u[rc]=i;
            where[i]=ltk;
            while (rc<=fc)
            {
                for (int c=0;c<f[u[rc]].size();c++)
                {
                    if (where[f[u[rc]][c].w1]==0)
                    {
                        where[f[u[rc]][c].w1]=ltk;
                        ++fc;
                        u[fc]=f[u[rc]][c].w1;
                    }
                }
                ++rc;
            }
            if (fc>1) ++ttk,biao[ttk]=m_p(ltk,i);
        }
    if (ttk>2)
    {
        printf("-1\n");
        return 0;
    }
    if (ttk==2)
    {
        for (int i=1;i<=2;i++)
        {
            ssc=0;
            for (int j=1;j<=maxn;j++)
                if (where[j]==biao[i].first) ssc+=inp[j]%2;
            if (ssc>2)
            {
                printf("-1\n");
                return 0;
            }
        }
        pans.clear();
        k1=biao[1].second;
        for (int i=1;i<=maxn;i++)
            if (where[i]==biao[1].first)
                if (inp[i]%2==1) {k1=i;break;}
        doit(k1);
        print();
        pans.clear();
        k1=biao[2].second;
        for (int i=1;i<=maxn;i++)
            if (where[i]==biao[2].first)
                if (inp[i]%2==1) {k1=i;break;}
        doit(k1);
        print();
    }
    else
    {
        ssc=0;
        for (int i=1;i<=maxn;i++)
            ssc+=inp[i]%2;
        if (ssc>4)
        {
            printf("-1\n");
            return 0;
        }
        if (ssc==0)
        {
            doit(biao[1].second);
            printf("1\n");
            printf("%d\n",pans[0]);
            pans.erase(pans.begin());
            print();
            return 0;
        }
        k1=-1;k2=-1;
        for (int i=1;i<=maxn;i++)
            if (inp[i]%2==1)
            {
                if (k1==-1) k1=i; else k2=i;
            }
        if (ssc==2)
        {
            doit(k1);
            printf("1\n");
            printf("%d\n",pans[0]);
            pans.erase(pans.begin());
            print();
            return 0;
        }
        f[k1].p_b(m_p(k2,m+1));
        f[k2].p_b(m_p(k1,m+1));
        ++inp[k1];
        ++inp[k2];
        k3=-1;
        for (int i=1;i<=maxn;i++)
            if (inp[i]%2==1)
            {
                if (k3==-1) {k3=i;break;}
            }
        doit(k3);
        for (int i=0;i<pans.size();i++)
        {
            if (pans[i]==m+1)
            {
                printf("%d\n",i);
                for (int j=0;j<i;j++)
                {
                    if (j!=0) printf(" ");
                    printf("%d",pans[j]);
                }
                printf("\n");
                printf("%d\n",pans.size()-i-1);
                for (int j=i+1;j<pans.size();j++)
                {
                    if (j!=i+1) printf(" ");
                    printf("%d",pans[j]);
                }
                printf("\n");
                break;
            }
        }
    }

    return 0;
}