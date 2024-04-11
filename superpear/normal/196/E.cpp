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

using namespace std;

struct PII
{
    int first,second;
};

struct PIII
{
    PII first;
    long long second;
};

const int maxn=200005;

bool operator < (const PIII &a,const PIII &b)
{
    if (a.second>b.second) return true;
    if (a.second<b.second) return false;
    if (a.first.first>b.first.first) return true; else return false;
}

vector<PII> f[maxn];
vector<PIII> bian;
vector<PIII>::iterator it;
priority_queue<PIII> g;
PIII cs,ct;
int n,m,k,xc,yc,zc,uc,qc;
int hash[maxn],ispor[maxn],nearmost[maxn],cq[maxn],fa[maxn];
LL ans,dis[maxn];

bool cmp(const PIII &a,const PIII &b)
{
    return a.second<b.second;
}

PII make_pairc(int a,int b)
{
    PII cs;
    cs.first=a;cs.second=b;
    return cs;
}

PIII make_pairc(PII a,int b)
{
    PIII cs;
    cs.first=a;cs.second=b;
    return cs;
}

int main()
{
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&xc,&yc,&zc);
        f[xc].push_back(make_pairc(yc,zc));
        f[yc].push_back(make_pairc(xc,zc));
    }
    scanf("%d",&k);
    memset(ispor,0,sizeof(ispor));
    for (int i=1;i<=k;i++)
    {
        scanf("%d",&cq[i]);
        ispor[cq[i]]=1;
    }
    for (int i=0;i<=n;i++) dis[i]=10000000000000000LL;
    memset(nearmost,0,sizeof(nearmost));
    for (int i=1;i<=k;i++)
    {
        g.push(make_pairc(make_pairc(cq[i],cq[i]),0));
        dis[cq[i]]=0;
        nearmost[cq[i]]=cq[i];
    }
    memset(hash,0,sizeof(hash));
    while (!g.empty())
    {
        cs=g.top();g.pop();
        qc=cs.first.first;
        //cout<<qc<<" "<<cs.second<<endl;
        if (hash[qc]==0)
        {
            hash[qc]=1;
            for (int i=0;i<f[qc].size();i++)
                if ((LL)cs.second+f[qc][i].second<dis[f[qc][i].first])
                {
                    dis[f[qc][i].first]=(LL)cs.second+f[qc][i].second;
                    nearmost[f[qc][i].first]=cs.first.second;
                    ct.first.first=f[qc][i].first;
                    ct.first.second=cs.first.second;
                    ct.second=dis[f[qc][i].first];
                    g.push(ct);
                }
        }
    }
    //for (int i=1;i<=n;i++) cout<<dis[i]<<" "<<nearmost[i]<<endl;
    if (ispor[1]==0) ans=dis[1]; else ans=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<f[i].size();j++)
            if (nearmost[i]!=nearmost[f[i][j].first])
            {
                cs.first.first=nearmost[i];
                cs.first.second=nearmost[f[i][j].first];
                cs.second=(LL)dis[i]+dis[f[i][j].first]+f[i][j].second;
                //cout<<cs.first.first<<" "<<cs.first.second<<" "<<cs.second<<endl;
                bian.push_back(cs);
            }
    sort(bian.begin(),bian.end(),cmp);
    for (int i=1;i<=n;i++) fa[i]=i;
    for (it=bian.begin();it<bian.end();it++)
    {
        xc=it->first.first;
        yc=it->first.second;
        while (fa[xc]!=xc) xc=fa[xc];
        while (fa[yc]!=yc) yc=fa[yc];
        if (xc!=yc)
        {
            ans+=(LL)it->second;
            fa[xc]=yc;
            xc=it->first.first;
            while (fa[xc]!=yc) {uc=fa[xc];fa[xc]=yc;xc=uc;}
            xc=it->first.second;
            while (fa[xc]!=yc) {uc=fa[xc];fa[xc]=yc;xc=uc;}
        }
    }
    cout<<ans<<endl;

    return 0;
}