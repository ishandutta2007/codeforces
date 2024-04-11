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
#include <ctime>

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

const int bigp=3214567;
const int maxn=1000005;

int hash1[bigp*2],a[maxn],next[maxn],now[105],last[105],q[10005],pf[10005],bak[10005],ans[10005],maxc[10005];
char st[maxn],sp[105];
int N,M,K,o,qc,ic;
PII ls[105];

void pushit(int s)
{
    int e=q[s]%bigp+1;
    while (hash1[e]!=0) ++e;
    hash1[e]=s;
}

void pushc(int s,int l,int r)
{
    int e=s%bigp+1;
    while ((hash1[e]!=0)&&(q[hash1[e]]!=s)) ++e;
    if (q[hash1[e]]==s)
    {
        int ct=hash1[e];
        if (l>maxc[ct]) ++ans[ct],maxc[ct]=r;
    }
}

int main()
{
    scanf("%s",st);
    N=strlen(st);
    for (int i=1;i<=N;i++) a[i]=st[i-1]-96;
    scanf("%d",&M);
    memset(hash1,0,sizeof(hash1));
    memset(pf,0,sizeof(pf));
    for (int i=1;i<=M;i++)
    {
        scanf("%s",sp);
        K=strlen(sp);
        q[i]=0;
        for (int j=1;j<=K;j++)
            q[i]=q[i]+(1<<(sp[j-1]-97));
        for (int j=1;j<i;j++)
            if (q[i]==q[j])
            {
                pf[i]=j;
                break;
            }
        if (pf[i]==0) pushit(i);
    }
    memset(last,0,sizeof(last));
    for (int i=1;i<=N;i++)
    {
        if (last[a[i]]!=0) next[last[a[i]]]=i;
        last[a[i]]=i;
    }
    memset(now,0,sizeof(now));
    for (int i=1;i<=N;i++)
        if (now[a[i]]==0) now[a[i]]=i;
    for (int i=1;i<=N;i++)
    {
        //for (int j=1;j<=26;j++) printf("%d ",now[j]);printf("\n");
        o=0;
        for (int j=1;j<=26;j++)
            if (now[j]!=0) ++o,ls[o]=m_p(now[j],j);
        sort(ls+1,ls+o+1);
        qc=0;
        ls[o+1]=m_p(N+1,-1);
        for (int j=1;j<=o;j++)
        {
            qc+=1<<(ls[j].w2-1);
            //cout<<i<<" "<<qc<<" "<<ls[j+1].w1-1<<endl;
            pushc(qc,i,ls[j+1].w1-1);
        }
        now[a[i]]=next[i];
    }
    for (int i=1;i<=M;i++)
    {
        if (pf[i]!=0)
        {
            printf("%d\n",ans[pf[i]]);
            continue;
        }
        printf("%d\n",ans[i]);
    }

    return 0;
}