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

int n;

int main()
{
    cin>>n;
    if (n%2==0)
    {
        cout<<-1<<endl;
    }
    else
    {
        for (int i=0;i<n-1;i++) cout<<i<<" ";cout<<n-1<<endl;
        for (int i=0;i<n-1;i++) cout<<i<<" ";cout<<n-1<<endl;
        for (int i=0;i<n-1;i++) cout<<(i+i)%n<<" ";cout<<(n-1+n-1)%n<<endl;
    }
    return 0;
}