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

int n,x,minc;
LL a[1000000];

int main()
{
    cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    minc=maxlongint;
    for (int i=1;i<=n;i++) minc=min(minc,int(a[i]));
    LL e=(LL)minc*n;
    for (int i=1;i<=n;i++) a[i]-=minc;
    while (a[x]!=0)
    {
        ++e;
        a[x]--;
        x--;
        if (x==0) x=n;
    }
    a[x]=e;
    for (int i=1;i<n;i++) cout<<a[i]<<" ";cout<<a[n]<<endl;

    return 0;
}