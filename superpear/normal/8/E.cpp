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

int n,jt,ttans,e,len,flag1,flag2,flag3,c[26],b[26];
LL K;
int f[26][2][2];

int main()
{
    //freopen("E.in","r",stdin);
    int j1,k1;
    cin>>n>>K;
    ++K;
    e=(n+1)/2;
    memset(b,0,sizeof(b));
    len=n-e;
    memset(f,0,sizeof(f));
    f[0][0][0]=1;
    while (b[1]==0)
    {
        for (int i=n-e-len+1;i<=n-e;i++)
            for (int j=0;j<=1;j++)
                for (int k=0;k<=1;k++)
                    f[i][j][k]=0;
        for (int i=n-e-len;i<n-e;i++)
            for (int j=0;j<=1;j++)
                for (int k=0;k<=1;k++)
                    if (f[i][j][k]>0)
                    {
                        //0
                        if ((j==1)||(b[i+1]==0))
                        {
                            if ((k==1)||(b[i+1]==0)) k1=1; else k1=0;
                            f[i+1][j][k1]+=f[i][j][k];
                        }
                        //1
                        if ((k==1)||(b[i+1]==0))
                        {
                            if ((j==1)||(b[i+1]==0)) j1=1; else j1=0;
                            f[i+1][j1][k]+=f[i][j][k];
                        }
                    }
        ttans=f[n-e][1][1]+f[n-e][1][0]+f[n-e][0][1];
        if ((n%2==1)&&(b[e]==1)) ttans-=f[n-e][0][1];
        if (K<=ttans) break;
        K-=ttans;
        jt=e;
        while (b[jt]==1)
        {
            b[jt]=0;
            --jt;
        }
        ++b[jt];
        len=e-jt+1;
    }
    memset(c,0,sizeof(c));
    while (c[0]==0)
    {
        flag1=1;
        flag2=1;
        flag3=1;
        for (int i=n-e;i>=1;i--)
        {
            if ((flag1==1)&&(c[i]<b[n-e+1-i])) {flag3=0;break;}
            if ((flag2==1)&&(1-c[i]<b[n-e+1-i])) {flag3=0;break;}
            if (c[i]>b[n-e+1-i]) flag1=0;
            if (1-c[i]>b[n-e+1-i]) flag2=0;
        }
        if ((flag2==1)&&(n%2==1)&&(b[e]==1)) flag3=0;
        if (flag3==1) --K;
        if (K==0) break;
        jt=n-e;
        while (c[jt]==1)
        {
            c[jt]=0;
            --jt;
        }
        ++c[jt];
    }
    if (K>0) cout<<-1<<endl; else
    {
        for (int i=1;i<=e;i++) cout<<b[i];
        for (int i=1;i<=n-e;i++) cout<<c[i];
        cout<<endl;
    }

    return 0;
}