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

int main()
{
    int a1,a2,a3,b1,b2,b3,N,e;
    scanf("%d %d %d",&a1,&a2,&a3);
    scanf("%d %d %d",&b1,&b2,&b3);
    scanf("%d",&N);
    if (a1+a2+a3!=0) e=(a1+a2+a3-1)/5+1; else e=0;
    if (b1+b2+b3!=0) e+=(b1+b2+b3-1)/10+1;
    if (e<=N) cout<<"YES"<<endl; else cout<<"NO"<<endl;

    return 0;
}