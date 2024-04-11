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

vector<int> f[5005];
int sz[5005],a[5005],ans[5005];
int N,xc,yc,cs;

void dfs(int s,int fa)
{
    sz[s]=1;
    for (int i=0;i<f[s].size();i++)
        if (f[s][i]!=fa)
        {
            dfs(f[s][i],s);
            sz[s]+=sz[f[s][i]];
        }
}

int main()
{
    scanf("%d",&N);
    for (int i=1;i<N;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc].p_b(yc);
        f[yc].p_b(xc);
    }
    memset(ans,0,sizeof(ans));
    for (int i=1;i<=N;i++)
    {
        memset(sz,0,sizeof(sz));
        dfs(i,0);
        memset(a,0,sizeof(a));
        a[0]=1;
        for (int j=0;j<f[i].size();j++)
        {
            cs=sz[f[i][j]];
            //cout<<i<<" "<<j<<" "<<cs<<endl;
            for (int k=N-1;k>=cs;k--)
                if (a[k-cs]==1) a[k]=1;
        }
        for (int j=0;j<N;j++) ans[j]|=a[j];
    }
    int o=0;
    for (int i=1;i<N-1;i++) o+=ans[i];
    printf("%d\n",o);
    for (int i=1;i<N-1;i++)
        if (ans[i]==1) printf("%d %d\n",i,N-1-i);

    return 0;
}