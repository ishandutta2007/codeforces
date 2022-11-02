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
    LL N,M,K;
    cin>>N>>M>>K;
    K=N*M+1-K;
    LL left=0,right=1000000000000LL,mid;
    while (left<=right)
    {
        mid=(left+right)/2;
        LL ss=0;
        for (int i=1;i<=N;i++)
            ss+=max((LL)0,M-mid/i);
        //cout<<mid<<" "<<ss<<endl;
        if (ss<=K-1) right=mid-1; else left=mid+1;
        //cout<<left<<" "<<right<<" "<<mid<<endl;
    }
    cout<<left<<endl;

    return 0;
}