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

int main()
{
    int a1,a2,a3,a4,a5,a6,a7,a8,a9,gt;
    cin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>a8>>a9;
    for (int i=1;i<=100000;i++)
    {
        gt=i+a2+a3;
        a5=gt-a2-a8;
        a9=gt-a3-a6;
        if ((a5>0)&&(a5<=100000)&&(a9>0)&&(a9<=100000)&&(i+a5+a9==gt))
        {
            printf("%d %d %d\n%d %d %d\n%d %d %d\n",i,a2,a3,a4,a5,a6,a7,a8,a9);
            return 0;
        }
    }

    return 0;
}