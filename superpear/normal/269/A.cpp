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

int n,k,p,maxc;
int main()
{
    scanf("%d",&n);
    maxc=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d",&k,&p);
        int left,right,mid;
        left=0;right=31;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (((LL)1<<(2*mid))>=p) right=mid-1; else left=mid+1;
        }
        if (p==1) left=1;
        maxc=max(maxc,k+left);
    }
    printf("%d\n",maxc);

    return 0;
}