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

LL ans;
int a[10005];
int A,B,K,o;

bool prime(int e)
{
    for (int i=2;i*i<=e;i++)
        if (e%i==0) return false;
    return true;
}

void search(int S,int nt,int e,int flag)
{
    if (e==o)
    {
        ans+=(LL)flag*(S/nt);
        return;
    }
    search(S,nt,e+1,flag);
    if (S/a[e+1]>=nt) search(S,nt*a[e+1],e+1,-flag);
}

int getans(int S)
{
    o=0;
    for (int i=2;i<=min(K-1,S/K);i++)
        if (prime(i)) ++o,a[o]=i;
    ans=0;
    search(S,K,0,1);
    return int(ans);
}

int main()
{
    scanf("%d %d %d",&A,&B,&K);

    if (!prime(K))
    {
        printf("0\n");
        return 0;
    }

    printf("%d\n",getans(B)-getans(A-1));


    return 0;
}