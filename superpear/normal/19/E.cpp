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

const int maxn=10005;

vector<int> du,ttans;
vector<PII> a[maxn];
vector<PII>::iterator bak;
int depth[maxn],ji[maxn],ou[maxn],jiq[maxn],ouq[maxn],vis[maxn],u[maxn],hash[maxn];
int n,m,xc,yc,ttj,root,rc,fc,flag,cs;

void search(int s,int fa,int deep)
{
    int c,es;
    depth[s]=deep;
    for (int i=0;i<a[s].size();i++)
    {
        c=a[s][i].first;
        if (c!=fa)
        {
            if (depth[c]==0)
                search(c,s,deep+1);
            else
            {
                if (depth[s]<depth[c]) continue;
                es=depth[s]-depth[c]+1;
                if (es%2==1)
                {
                    bak=a[s].begin()+i;
                    ++ttj;
                    ji[s]++;
                    ji[c]--;
                }
                else
                {
                    ou[s]++;
                    ou[c]--;
                }
            }
        }
    }
}

void louit(int s,int fabiao)
{
    int c;
    hash[s]=1;
    for (int i=0;i<a[s].size();i++)
    {
        c=a[s][i].first;
        if (hash[c]==0)
        {
            louit(c,a[s][i].second);
            jiq[s]+=jiq[c];
            ouq[s]+=ouq[c];
        }
    }
    jiq[s]+=ji[s];
    ouq[s]+=ou[s];
    if ((jiq[s]==ttj)&&(ouq[s]==0)) ttans.p_b(fabiao);
    //cout<<s<<" "<<jiq[s]<<" "<<ouq[s]<<endl;
}

int main()
{
    //freopen("E.in","r",stdin);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>xc>>yc;
        a[xc].p_b(m_p(yc,i));
        a[yc].p_b(m_p(xc,i));
    }
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++)
        if (vis[i]==0)
        {
            rc=1;fc=1;vis[i]=1;u[1]=i;
            flag=1;
            while (rc<=fc)
            {
                for (int j=0;j<a[u[rc]].size();j++)
                {
                    cs=a[u[rc]][j].first;
                    if (vis[cs]==0) vis[cs]=3-vis[u[rc]],++fc,u[fc]=cs; else
                    if (vis[cs]!=3-vis[u[rc]]) flag=0;
                }
                ++rc;
            }
            if (flag==0) du.p_b(i);
        }
    if (du.size()>1)
    {
        cout<<0<<endl;
        return 0;
    }
    if (du.size()==0)
    {
        cout<<m<<endl;
        for (int i=1;i<=m;i++) cout<<i<<" ";cout<<endl;
        return 0;
    }
    memset(depth,0,sizeof(depth));
    memset(ji,0,sizeof(ji));
    memset(ou,0,sizeof(ou));
    root=du[0];
    ttj=0;
    search(root,0,1);
    memset(hash,0,sizeof(hash));
    memset(jiq,0,sizeof(jiq));
    memset(ouq,0,sizeof(ouq));
    louit(root,0);
    if (ttj==1) ttans.p_b(bak->second);
    cout<<ttans.size()<<endl;
    sort(ttans.begin(),ttans.end());
    for (int i=0;i<ttans.size();i++) cout<<ttans[i]<<" ";cout<<endl;

    return 0;
}