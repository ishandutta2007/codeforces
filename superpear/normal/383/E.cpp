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

int f1[30],f2[30][30],f3[30][30][30],ls[30];
int N,c1,c2,c3,S,ff,ll,o,ans;
char st[10];
int dp[20000001];

int main()
{
    scanf("%d",&N);
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    memset(f3,0,sizeof(f3));
    for (int i=1;i<=N;i++)
    {
        scanf("%s",st);
        c1=st[0]-96,
        c2=st[1]-96,
        c3=st[2]-96;
        if (c1>c2) swap(c1,c2);
        if (c1>c3) swap(c1,c3);
        if (c2>c3) swap(c2,c3);
        if (c3==c2) c3=0;
        if (c2==c1) c2=0;
        ++f1[c1],++f1[c2],++f1[c3];
        ++f2[c1][c2],++f2[c1][c3],++f2[c2][c3];
        ++f3[c1][c2][c3];
    }
    S=(1<<24)-1;
    memset(dp,0,sizeof(dp));
    for (int i=0;i<=S;i++)
    {
        ff=0,ll=0,o=0;
        for (int j=1;j<=24;j++)
            if ((i>>(j-1))%2==1)
            {
                if (ff==0) ff=j;
                ll=j;
                ++o;
                ls[o]=j;
            }
        if (o<=3)
        {
            for (int x=1;x<=o;x++) dp[i]+=f1[ls[x]];
            for (int x=1;x<=o;x++)
                for (int y=x+1;y<=o;y++)
                    dp[i]-=f2[ls[x]][ls[y]];
            for (int x=1;x<=o;x++)
                for (int y=x+1;y<=o;y++)
                    for (int z=y+1;z<=o;z++)
                        dp[i]+=f3[ls[x]][ls[y]][ls[z]];
        }
        else
        {
            dp[i]=dp[i-(1<<(ll-1))]+dp[i-(1<<(ff-1))]-dp[i-(1<<(ff-1))-(1<<(ll-1))];
            dp[i]-=f2[ff][ll];
            for (int x=2;x<o;x++)
                dp[i]+=f3[ff][ls[x]][ll];
        }
    }

    ans=0;
    for (int i=0;i<=S;i++) ans^=(dp[i]*dp[i]);
    //for (int i=0;i<=100;i++) cout<<i<<" "<<dp[i]<<endl;
    printf("%d\n",ans);

    return 0;
}