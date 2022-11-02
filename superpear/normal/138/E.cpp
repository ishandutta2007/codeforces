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

int n,m,L,R,ld,rd,cnt,nowans;
char ch;
LL ans;
int a[maxn],next[maxn],hash[30],l[505],r[505],lc[505],rc[505],nm[505],nowt[maxn],sum[27][maxn];

int main()
{
    //freopen("E.in","r",stdin);
    n=0;
    while (true)
    {
        ch=getchar();
        if ((ch>='a')&&(ch<='z')) ++n,a[n]=ch-96; else break;
    }
    cin>>m>>L>>R;
    ans=0;
    memset(next,0,sizeof(next));
    memset(hash,0,sizeof(hash));
    for (int i=1;i<=n;i++)
    {
        if (hash[a[i]]!=0) next[hash[a[i]]]=i;
        hash[a[i]]=i;
    }
    for (int i=1;i<=n;i++) if (next[i]==0) next[i]=n+1;
    for (int i=1;i<=m;i++)
    {
        while (true)
        {
            ch=getchar();
            if ((ch>='a')&&(ch<='z')) break;
        }
        nm[i]=ch-96;
        cin>>lc[i]>>rc[i];
        cnt=0;
        r[i]=n+1;
        l[i]=n+1;
        for (int j=1;j<=n;j++)
        {
            if (a[j]==nm[i]) ++cnt;
            if ((cnt==lc[i])&&(l[i]==n+1)) l[i]=j;
            if (cnt==rc[i]+1)
            {
                r[i]=j;
                break;
            }
        }
        //cout<<l[i]<<" "<<r[i]<<endl;
    }
    for (int i=1;i<=26;i++)
    {
        sum[i][0]=0;
        for (int j=1;j<=n;j++)
            if (a[j]==i) sum[i][j]=sum[i][j-1]+1; else sum[i][j]=sum[i][j-1];
    }
    memset(nowt,0,sizeof(nowt));
    for (int i=1;i<=m;i++)
        for (int j=l[i];j<=r[i]-1;j++)
            ++nowt[j];
    nowans=0;
    for (int i=1;i<=n;i++) if ((nowt[i]>=L)&&(nowt[i]<=R)) ++nowans;
    ans+=nowans;
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (nm[j]==a[i-1])
            {
                ld=l[j];
                rd=r[j];
                //if (ld<i) ld=i;
                //if (rd<i) rd=i;
                while ((ld<=n)&&(max(sum[nm[j]][ld]-sum[nm[j]][i-1],0)<lc[j])) ld=next[ld];
                while ((rd<=n)&&(max(sum[nm[j]][rd]-sum[nm[j]][i-1],0)<=rc[j])) rd=next[rd];
                //cout<<ld<<" "<<rd<<endl;
                for (int k=l[j];k<ld;k++)
                {
                    --nowt[k];
                    if (nowt[k]==L-1) --nowans;
                    if (nowt[k]==R) ++nowans;
                }
                for (int k=r[j];k<rd;k++)
                {
                    ++nowt[k];
                    if (nowt[k]==R+1) --nowans;
                    if (nowt[k]==L) ++nowans;
                }
                l[j]=ld,r[j]=rd;
            }
        }
        if ((nowt[i-1]>=L)&&(nowt[i-1]<=R)) --nowans;
        ans+=(LL)nowans;
        //cout<<nowans<<endl;
        //for (int j=1;j<=n;j++) cout<<nowt[j];cout<<endl;
    }
    cout<<ans<<endl;

    return 0;
}