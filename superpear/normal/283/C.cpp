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

const int maxn=500005;
int n,q,t,cs,tn,a[maxn],b[maxn],c[maxn],e[maxn],f[maxn],use[maxn],dp[maxn],bak[maxn];

int main()
{
    scanf("%d %d %d",&n,&q,&t);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),bak[i]=a[i];
    memset(e,0,sizeof(e));
    memset(f,0,sizeof(f));
    for (int i=1;i<=q;i++)
    {
        scanf("%d %d",&b[i],&c[i]);
        e[b[i]]=c[i];
        f[c[i]]=b[i];
    }
    for (int i=1;i<=n;i++)
    {
        memset(use,0,sizeof(use));
        cs=i;
        while (cs!=0)
        {
            use[cs]=1;
            cs=e[cs];
            if (use[cs]==1)
            {
                cout<<0<<endl;
                return 0;
            }
        }
    }
    memset(use,0,sizeof(use));
    for (int i=1;i<=n;i++)
        if ((use[i]==0)&&(e[i]!=0)&&(f[i]==0))
        {
            cs=i;
            use[i]=i;
            tn=a[i];
            while (e[cs]!=0)
            {
                cs=e[cs];
                use[cs]=i;
                tn+=a[cs];
                a[cs]=tn;
            }
            cs=i;
            while (e[cs]!=0) cs=e[cs];
            tn=0;
            while (f[cs]!=0)
            {
                cs=f[cs];
                ++tn;
                t-=tn*bak[cs];
                if (t<0)
                {
                    cout<<0<<endl;
                    return 0;
                }
            }
            //if (n==300) cout<<tn<<endl;
            /*while (e[cs]!=0) use[cs]=1,cs=e[cs];
            use[cs]=1;
            tn=a[cs];
            while (f[cs]!=0)
            {
                cs=f[cs];
                tn+=a[cs];
                a[cs]=tn;
            }*/
        }
    //if (n==300) cout<<t<<endl;
    if (t<0)
    {
        cout<<0<<endl;
        return 0;
    }
    //for (int i=1;i<=n;i++) cout<<a[i]<<endl;
    //cout<<t<<endl;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for (int i=1;i<=n;i++)
        for (int j=a[i];j<=t;j++)
            dp[j]=(dp[j]+dp[j-a[i]])%1000000007;
    printf("%d\n",dp[t]);

    return 0;
}