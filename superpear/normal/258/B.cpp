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

const int bigp=1000000007;

int m,o,ans,nowans,plusf,flag;
int u[15],fl[15];
int f[15][15][2];
int g[15][15][15];

int powc(int a,int b,int bigp)
{
    if (b==0) return 1;
    int d=powc(a,b/2,bigp);
    d=(LL)d*d%bigp;
    if (b%2==1) d=(LL)d*a%bigp;
    return d;
}

int per(int n,int k)
{
    int ans=1;
    for (int i=n;i>=n-k+1;i--)
        ans=(LL)ans*i%bigp;
    for (int i=1;i<=k;i++)
        ans=(LL)ans*powc(i,bigp-2,bigp)%bigp;
    return ans;
}

int main()
{
    cin>>m;
    memset(f,0,sizeof(f));
    o=0;
    while (m>0)
    {
        o++;
        u[o]=m%10;
        m/=10;
    }
    reverse(u+1,u+o+1);
    memset(f,0,sizeof(f));
    f[0][0][1]=1;
    for (int i=0;i<o;i++)
        for (int j=0;j<=9;j++)
        {
            if (f[i][j][0]>0)
            {
                for (int k=0;k<=9;k++)
                {
                    if ((k==4)||(k==7)) plusf=1; else plusf=0;
                    f[i+1][j+plusf][0]+=f[i][j][0];
                }
            }
            if (f[i][j][1]>0)
            {
                for (int k=0;k<=u[i+1];k++)
                {
                    if ((k==4)||(k==7)) plusf=1; else plusf=0;
                    if (k==u[i+1]) flag=1; else flag=0;
                    f[i+1][j+plusf][flag]+=f[i][j][1];
                }
            }
        }
    memset(fl,0,sizeof(fl));
    for (int i=0;i<=9;i++)
        fl[i]+=f[o][i][0]+f[o][i][1];
    --fl[0];
    //for (int i=0;i<=9;i++) cout<<fl[i]<<endl;
    ans=0;
    for (int i=1;i<=9;i++)
        if (fl[i]>0)
        {
            memset(g,0,sizeof(g));
            g[0][0][0]=1;
            for (int j=0;j<=9;j++)
                for (int k=0;k<=6;k++)
                    for (int e=0;e<i;e++)
                        if (g[j][k][e]>0)
                            for (int s=0;s<=6-k;s++)
                                if (e+j*s<i)
                                    g[j+1][k+s][e+j*s]=((LL)g[j+1][k+s][e+j*s]+(LL)g[j][k][e]*per(fl[j],s)%bigp)%bigp;
            nowans=0;
            for (int j=0;j<i;j++)
                nowans=((LL)nowans+g[10][6][j])%bigp;
            nowans=(LL)nowans*fl[i]%bigp;
            nowans=(LL)nowans*720%bigp;
            ans=((LL)ans+nowans)%bigp;
        }
    cout<<ans<<endl;

    return 0;
}