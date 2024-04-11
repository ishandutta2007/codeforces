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

const int maxn=2005;
vector<int> a[maxn],f[maxn];
int dfn[maxn],low[maxn],where[maxn],hash[maxn],stack[maxn],big[maxn][maxn],leaf[maxn],sum[maxn];
int n,m,k,xc,yc,ans,nowans,tot,o,top;

void dfs(int s,int fa)
{
    int c;
    ++o;
    dfn[s]=o;
    low[s]=o;
    ++top;
    stack[top]=s;
    for (int i=0;i<a[s].size();i++)
    {
        c=a[s][i];
        if (c==fa) continue;
        if (dfn[c]==0)
        {
            dfs(c,s);
            low[s]=min(low[s],low[c]);
        }
        else
            low[s]=min(low[s],dfn[c]);
    }
    if (dfn[s]==low[s])
    {
        ++tot;
        while (stack[top+1]!=s)
        {
            where[stack[top]]=tot;
            low[stack[top]]=maxlongint;
            dfn[stack[top]]=maxlongint;
            --top;
        }
    }
}

void findmax(int s,int nows)
{
    int c;
    hash[s]=1;
    //cout<<s<<" "<<nows<<endl;
    if (leaf[s]==1)
    {
        nowans=min(nowans,nows);
    }
    else
    {
        for (int i=0;i<f[s].size();i++)
        {
            c=f[s][i];
            if (hash[c]==0)
                if (leaf[c]==1) findmax(c,nows+(sum[s]-sum[c])); else findmax(c,nows+(sum[s]-sum[c]-1));
        }
    }
}

void calc(int s)
{
    hash[s]=1;
    int c,nt=0;
    for (int i=0;i<f[s].size();i++)
    {
        c=f[s][i];
        if (hash[c]==0)
        {
            nt=1;
            calc(c);
            if (leaf[c]==0) sum[s]+=sum[c]+1;
        }
    }
    if (nt==0) leaf[s]=1;
}

int main()
{
    //freopen("F.in","r",stdin);

    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        a[xc].p_b(yc);
        a[yc].p_b(xc);
    }
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(big,0,sizeof(big));
    ans=n-1;
    for (int i=1;i<=n;i++)
        if (dfn[i]==0)
        {
            o=0;
            top=0;
            tot=0;
            memset(where,0,sizeof(where));
            dfs(i,0);
            ans-=tot;
            for (int j=1;j<=n;j++) f[j].clear();
            for (int j=1;j<=n;j++)
                if (where[j]!=0)
                    for (int ck=0;ck<a[j].size();ck++)
                    {
                        k=a[j][ck];
                        if ((where[k]!=0)&&(where[j]!=where[k]))
                        {
                            if (big[where[j]][where[k]]==i) continue;
                            big[where[j]][where[k]]=i;
                            big[where[k]][where[j]]=i;
                            f[where[j]].p_b(where[k]);
                            f[where[k]].p_b(where[j]);
                        }
                    }
            //for (int j=1;j<=n;j++) cout<<where[j]<<" ";cout<<endl;
            nowans=maxlongint;
            for (int j=1;j<=n;j++)
                if (where[j]!=0)
                {
                    memset(hash,0,sizeof(hash));
                    memset(sum,0,sizeof(sum));
                    memset(leaf,0,sizeof(leaf));
                    calc(where[j]);
                    memset(hash,0,sizeof(hash));
                    findmax(where[j],0);
                }
            //cout<<nowans<<endl;
            ans+=nowans+1;
        }
    cout<<ans<<endl;

    return 0;
}