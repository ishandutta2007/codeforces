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

int x,y,a,b,o,u[100000],v[100000];
int main()
{
    cin>>x>>y>>a>>b;
    o=0;
    for (int i=1;i<=x;i++)
        for (int j=1;j<=y;j++)
            if ((i>=a)&&(j>=b)&&(i>j)) ++o,u[o]=i,v[o]=j;
    cout<<o<<endl;
    for (int i=1;i<=o;i++) cout<<u[i]<<" "<<v[i]<<endl;
    return 0;
}