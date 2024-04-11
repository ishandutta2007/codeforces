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

const int maxn=100005;

int n,o,ccf,t1,t2,cs,pv,ct,xc,yc,lent;
int a[maxn],m1[maxn],por[maxn],pre[maxn],next[maxn],use[1005],place[1005];
LL ans,nowans,rrg,tor[maxn];
map<int,int> f;
map<int,int>::iterator lc;
vector<int> gt[1005];

bool lucky(int s)
{
    while (s>0)
    {
        if ((s%10!=4)&&(s%10!=7)) return false;
        s/=10;
    }
    return true;
}

int main()
{
    //freopen("D.in","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    vector<int> fcd;
    for (int i=1;i<=n;i++)
        if (lucky(a[i])) fcd.p_b(a[i]); else a[i]=0;
    sort(fcd.begin(),fcd.end());
    m1[1]=1;
    for (int i=1;i<fcd.size();i++)
        if (fcd[i]==fcd[i-1]) m1[i+1]=m1[i]; else m1[i+1]=m1[i]+1;
    o=0;
    for (int i=1;i<=n;i++)
        if (a[i]!=0)
        {
            for (int j=1;j<=fcd.size();j++)
                if (a[i]==fcd[j-1])
                {
                    a[i]=m1[j];
                    break;
                }
            ++o,place[o]=i;
        }
    for (int i=1;i<=n;i++)
        if (a[i]!=0)
            gt[a[i]].p_b(i);
    memset(pre,0,sizeof(pre));
    for (int i=1;i<=n;i++) next[i]=n+1;
    ccf=0;
    for (int i=1;i<=n;i++)
        if (a[i]!=0)
        {
            pre[i]=ccf;
            if (ccf!=0) next[ccf]=i;
            ccf=i;
        }
    memset(tor,0,sizeof(tor));
    memset(por,0,sizeof(por));
    for (int i=1;i<=o;i++)
    {
        t1=place[i];
        f.clear();
        memset(use,0,sizeof(use));
        f.insert(m_p(1,pre[t1]));
        nowans=(LL)pre[t1]*(pre[t1]+1)/2;
        cs=t1-pre[t1]-1;
        for (int j=i;j<=o;j++)
        {
            t2=place[j];
            ct=next[t2]-t2;
            if (use[a[t2]]==0)
            {
                use[a[t2]]=1;
                for (int k=0;k<gt[a[t2]].size();k++)
                {
                    pv=gt[a[t2]][k];
                    if (pv>=t1) break;
                    lc=f.l_b(pv+1),--lc;
                    xc=lc->w1,yc=lc->w2,lent=yc-xc+1;
                    f.erase(lc);
                    nowans-=(LL)lent*(lent+1)/2;
                    lent=pv-xc;
                    nowans+=(LL)lent*(lent+1)/2;
                    f.insert(m_p(xc,pv-1));
                    lent=yc-pv;
                    nowans+=(LL)lent*(lent+1)/2;
                    f.insert(m_p(pv+1,yc));
                }
            }
            lc=f.end(),--lc;
            lent=lc->w2-lc->w1+1;
            rrg=nowans-(LL)lent*(lent+1)/2;
            for (int t=0;t<=cs;t++)
            {
                lent=lc->w2-lc->w1+1+t;
                ans+=(LL)ct*(rrg+(LL)lent*(lent+1)/2);
            }
        }
        for (int t=0;t<=cs;t++)
        {
            lent=t1-t-1;
            ans+=(LL)t*lent*(lent+1)/2;
        }
    }
    cs=n-place[o];
    for (int t=0;t<=cs;t++)
    {
        lent=n-t;
        ans+=(LL)t*lent*(lent+1)/2;
    }
    printf("%I64d\n",ans);

    return 0;
}