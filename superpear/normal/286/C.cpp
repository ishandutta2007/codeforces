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

const int maxn=1000005;
int a[maxn],stackc[maxn],flag[maxn];
int n,t,top,cs;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&t);
    memset(flag,0,sizeof(flag));
    for (int i=1;i<=t;i++) scanf("%d",&cs),flag[cs]=1;
    top=0;
    for (int i=n;i>=1;i--)
        if (flag[i]==1) ++top,stackc[top]=a[i]; else
        {
            if ((top>0)&&(a[i]==stackc[top])) --top; else
                flag[i]=1,++top,stackc[top]=a[i];
        }
    if (top==0)
    {
        printf("YES\n");
        for (int i=1;i<=n;i++) if (flag[i]==1) a[i]=-a[i];
        for (int i=1;i<n;i++) printf("%d ",a[i]);printf("%d\n",a[n]);
    }
    else
        printf("NO\n");

    return 0;
}