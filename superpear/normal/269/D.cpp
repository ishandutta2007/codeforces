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
typedef pair<int,pair<int,int> > PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int maxn=100005;

int n,t,uv;
int h[maxn],x[maxn],y[maxn],ans[maxn];
PIII st[maxn];
vector<PII> f[maxn];
map<int,PII> sh;
map<int,PII>::iterator sg,sg1;
PII pmc1,pmc2,t1,t2,cs;

PII cross(int x1,int y1,int x2,int y2)
{
    return m_p(max(x1,x2),min(y1,y2));
}

int main()
{
    scanf("%d %d",&n,&t);
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&h[i],&x[i],&y[i]);
        --y[i];
    }
    ++n;h[n]=0;x[n]=-maxlongint;y[n]=maxlongint;
    ++n;h[n]=t;x[n]=-maxlongint;y[n]=maxlongint;
    for (int i=1;i<=n;i++) st[i]=m_p(h[i],m_p(x[i],y[i]));
    sort(st+1,st+n+1);
    for (int i=1;i<=n;i++)
    {
        h[i]=st[i].first;
        x[i]=st[i].second.first;
        y[i]=st[i].second.second;
    }

    sh.insert(m_p(x[1],m_p(y[1],1)));
    for (int i=2;i<=n;i++)
    {
       /* sg=sh.begin();
        while (sg!=sh.end())
        {
            cout<<"("<<sg->first<<","<<sg->second.first<<","<<sg->second.second<<") ";
            sg++;
        }
        cout<<endl;*/
        sg=sh.l_b(x[i]+1),--sg;
        pmc1=m_p(sg->first,sg->second.second);
        pmc2=sg->second;
        while (sg->first<=y[i])
        {
            t1=cross(x[i],y[i],sg->first,sg->second.first);
            uv=sg->second.second;
            t2=cross(x[i],y[i],x[uv],y[uv]);
            if (t1==t2) f[i].p_b(m_p(uv,t2.second-t2.first+1));
            sg1=sg,sg1++;
            if (sg->second.first>y[i]) pmc2=sg->second;
            sh.erase(sg);
            sg=sg1;
            if (sg==sh.end()) break;
        }
        if (pmc1.first<x[i]) sh.insert(m_p(pmc1.first,m_p(x[i]-1,pmc1.second)));
        sh.insert(m_p(x[i],m_p(y[i],i)));
        if (pmc2.second!=-1) sh.insert(m_p(y[i]+1,pmc2));
    }

    memset(ans,0,sizeof(ans));
    ans[n]=maxlongint;
    for (int i=n;i>1;i--)
        for (int j=0;j<f[i].size();j++)
        {
            cs=f[i][j];
            ans[cs.first]=max(ans[cs.first],min(ans[i],cs.second));
        }
    printf("%d\n",ans[1]);

    return 0;
}