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

int N,s1,s2,ans;
int a[2005],dc[2005];

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++) scanf("%d",&a[i]);
    for (int i=1;i<=N;i++) a[i]=abs(a[i]);
    memset(dc,0,sizeof(dc));
    for (int i=100000;i>=0;i--)
    {
        for (int j=1;j<=N;j++)
            if (a[j]==i) dc[j]=2;
        for (int j=1;j<=N;j++)
            if (a[j]==i)
            {
                s1=0; //+
                for (int k=1;k<j;k++)
                    if (dc[k]==1)
                    {
                        if (a[k]>a[j]) ++s1;
                    }
                for (int k=j+1;k<=N;k++)
                    if (dc[k]==1)
                    {
                        if (a[k]<a[j]) ++s1;
                    }
                    else
                        if (dc[k]!=2) ++s1;
                s2=0; //-
                for (int k=1;k<j;k++)
                    if (dc[k]==1)
                    {
                        if (a[k]>-a[j]) ++s2;
                    }
                    else
                        if (dc[k]!=2) ++s2;
                for (int k=j+1;k<=N;k++)
                    if (dc[k]==1)
                    {
                        if (a[k]<-a[j]) ++s2;
                    }
                //cout<<s1<<" "<<s2<<" "<<j<<endl;
                if (s1>s2) a[j]=-a[j];
            }
        for (int j=1;j<=N;j++)
            if (a[j]==i) dc[j]=1;
    }
    ans=0;
    for (int i=1;i<=N;i++)
        for (int j=i+1;j<=N;j++)
            if (a[i]>a[j]) ++ans;
    printf("%d\n",ans);

    return 0;
}