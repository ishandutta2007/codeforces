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

int n,l,r,o,a[100005];
int main()
{
    cin>>n;
    if ((n%4==2)||(n%4==3)) cout<<-1<<endl; else
    {
        l=1,r=n,o=0;
        while (l<r)
        {
            ++o;
            a[l]=o*2;
            a[l+1]=n+2-o*2;
            a[r]=n+1-o*2;
            a[r-1]=o*2-1;
            l+=2,r-=2;
        }
        if (l==r) a[l]=l;
        for (int i=1;i<n;i++) cout<<a[i]<<" ";cout<<a[n]<<endl;
    }
    return 0;
}