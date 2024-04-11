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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

int n,maxc,minc,flag,x[1000000],y[1000000];
int main()
{
    scanf("%d",&n);
    maxc=0;minc=maxlongint;
    for (int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]);
    for (int i=1;i<=n;i++)
    {
        maxc=max(maxc,y[i]);
        minc=min(minc,x[i]);
    }
    flag=-1;
    for (int i=1;i<=n;i++)
        if ((x[i]==minc)&&(y[i]==maxc)) flag=i;
    cout<<flag<<endl;

    return 0;
}