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
int n,t,cc,flag[maxn],a[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    if (n==1)
    {
        putchar('+');putchar('\n');
        return 0;
    }
    for (int i=1;i<=n;i++) flag[i]=1;
    flag[n]=-1;flag[n-1]=-1;t=a[n]-a[n-1];
    for (int i=n-2;i>=1;i--)
    {
        if (t>=a[i])
        {
            t=t-a[i];
            flag[i+1]*=-1;
            flag[i]*=-1;
        }
        else
        {
            t=a[i]-t;
            flag[i+1]*=-1;
        }
    }
    cc=1;
    for (int i=1;i<=n;i++)
    {
        cc*=flag[i];
        if (cc<0) putchar('-'); else putchar('+');
    }
    putchar('\n');

    return 0;
}