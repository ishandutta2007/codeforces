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

string s1,s2;
int N,M,flag,o,a[1005],b[1005],sc[105];

int main()
{
    cin>>s1;
    cin>>s2;
    N=s1.size();
    M=s2.size();
    for (int i=1;i<=N;i++) a[i]=s1[i-1]-96;
    for (int i=1;i<=M;i++) b[i]=s2[i-1]-96;
    memset(sc,0,sizeof(sc));
    for (int i=1;i<=N;i++) ++sc[a[i]];
    for (int i=1;i<=M;i++) --sc[b[i]];
    flag=1;
    for (int i=1;i<=26;i++)
        if (sc[i]!=0)
        {
            flag=0;
            break;
        }
    if (flag==1)
    {
        cout<<"array"<<endl;
        return 0;
    }
    flag=1;
    o=0;
    for (int i=1;i<=M;i++)
    {
        while ((o<=N)&&(a[o]!=b[i])) ++o;
        if (o>N)
        {
            flag=0;
            break;
        }
        ++o;
    }
    if (flag==1)
    {
        cout<<"automaton"<<endl;
        return 0;
    }
    flag=1;
    for (int i=1;i<=26;i++)
        if (sc[i]<0)
        {
            flag=0;
            break;
        }
    if (flag==1)
    {
        cout<<"both"<<endl;
        return 0;
    }
    cout<<"need tree"<<endl;

    return 0;
}