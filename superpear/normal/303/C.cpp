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

const int maxn=1000005;

vector<PII> f[maxn];
int n,K,Kc,ok,vj,flag,o1,o,maxc,maxk,tp,maxcr;
int a[10005],use[10005],hh[32],xc[21],yc[21],times[10005],v[10005],x[10005],y[10005],vp[24],uo[10];

bool okit()
{
    int ev,diff,j,fc,flag,b[5];
    ev=0;
    for (int i=1;i<=o;i++) ++ev,vp[ev]=x[i],++ev,vp[ev]=y[i];
    sort(vp+1,vp+ev+1);
    if (o==0) return true;
    diff=1,uo[1]=vp[1];
    for (int i=2;i<=ev;i++) if (vp[i]!=vp[i-1]) ++diff,uo[diff]=vp[i];
    if (diff>K*2) return false;
    memset(b,0,sizeof(b));
    for (int i=1;i<=diff;i++) b[i]=1;
    while (b[0]==0)
    {
        j=K;
        while (b[j]==diff) b[j]=1,--j;
        ++b[j];
        fc=1;
        for (int i=1;i<=o;i++)
        {
            flag=1;
            for (int j=1;j<=K;j++)
                if ((x[i]==uo[b[j]])||(y[i]==uo[b[j]]))
                {
                    flag=0;
                    break;
                }
            if (flag==1)
            {
                fc=0;
                break;
            }
        }
        //if (fc==1)
        //    for (int i=1;i<=K;i++) cout<<uo[b[i]]<<endl;
        if (fc==1) return true;
    }
    return false;
}

int main()
{
    cin>>n>>K;
    maxcr=0;
    for (int i=1;i<=n;i++) cin>>a[i],maxcr=max(maxcr,a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            if (f[a[j]-a[i]].size()<9)
                f[a[j]-a[i]].p_b(m_p(i,j));
    for (int i=1;i<=maxcr;i++)
    {
        tp=maxcr/i;
        flag=1;
        for (int j=1;j<=tp;j++)
            if (f[j*i].size()>=9)
            {
                flag=0;
                break;
            }
        if (flag==0) continue;
        o=0;
        for (int j=1;j<=tp;j++)
        {
            for (int k=0;k<f[j*i].size();k++)
            {
                ++o,x[o]=f[j*i][k].w1,y[o]=f[j*i][k].w2;
                if (o>10) break;
            }
            if (o>10) break;
        }
        //cout<<i<<" "<<o<<endl;
        //if (i==7) for (int i=1;i<=o;i++) cout<<x[i]<<" "<<y[i]<<endl;
        if (o>10) continue;
        if (okit())
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<maxcr+1<<endl;

    return 0;
}