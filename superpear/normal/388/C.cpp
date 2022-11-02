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

int N,s1,s2,sc,o,f[1005],a[1005];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    scanf("%d",&N);
    s1=0,s2=0;
    for (int i=1;i<=N;i++)
    {
        scanf("%d",&sc);
        for (int j=1;j<=sc;j++) scanf("%d",&a[j]);
        for (int j=1;j<=sc/2;j++) s1+=a[j],s2+=a[sc+1-j];
        if (sc%2==1) ++o,f[o]=a[sc/2+1];
    }
    sort(f+1,f+o+1,cmp);
    for (int i=1;i<=o;i++)
        if (i%2==1) s1+=f[i]; else s2+=f[i];
    cout<<s1<<" "<<s2<<endl;

    return 0;
}