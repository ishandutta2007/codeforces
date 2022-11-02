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

const int bigp=1000000009;

int f[2][32][32][32][32];
int n,h,s1,s2,tp,ans;

void doit(int j,int k,int s,int g)
{
    if (j>h) j=h+1;
    if (k>h) k=h+1;
    if (s>h) s=h+1;
    if (g>h) g=h+1;
    if (j>k) swap(j,k);
    if (j>s) swap(j,s);
    if (j>g) swap(j,g);
    if (k>s) swap(k,s);
    if (k>g) swap(k,g);
    if (s>g) swap(s,g);
    f[s2][j][k][s][g]=(f[s2][j][k][s][g]+tp)%bigp;
}

int main()
{
    cin>>n>>h;
    memset(f,0,sizeof(f));
    f[0][1][1][1][1]=1;
    for (int i=0;i<n;i++)
    {
        s1=i%2;
        s2=1-i%2;
        for (int j=1;j<=h+1;j++)
            for (int k=j;k<=h+1;k++)
                for (int s=k;s<=h+1;s++)
                    for (int g=s;g<=h+1;g++)
                        f[s2][j][k][s][g]=0;
        for (int j=1;j<=h+1;j++)
            for (int k=j;k<=h+1;k++)
                for (int s=k;s<=h+1;s++)
                    for (int g=s;g<=h+1;g++)
                        if (f[s1][j][k][s][g]>0)
                        {
                            tp=f[s1][j][k][s][g];
                            if (j==h+1) doit(j,k+1,s+1,g+1); else doit(1,k+1,s+1,g+1);
                            if (k==h+1) doit(j+1,k,s+1,g+1); else doit(j+1,1,s+1,g+1);
                            if (s==h+1) doit(j+1,k+1,s,g+1); else doit(j+1,k+1,1,g+1);
                            if (g==h+1) doit(j+1,k+1,s+1,g); else doit(j+1,k+1,s+1,1);
                        }
    }
    ans=0;
    for (int i=1;i<h+1;i++)
        for (int j=i;j<=h+1;j++)
            for (int k=j;k<=h+1;k++)
                for (int s=k;s<=h+1;s++)
                    ans=(ans+f[s2][i][j][k][s])%bigp;
    cout<<ans<<endl;

    return 0;
}