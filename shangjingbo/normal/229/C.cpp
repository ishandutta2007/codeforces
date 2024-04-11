#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

#define PB push_back
#define MP make_pair

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<string> VS;

const int maxn  =   1000005;

int n,m,d[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    memset(d,0,sizeof(d));
    for (int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        ++d[a];
        ++d[b];
    }
    
    LL s1=(LL)m*(n-2);//A+2B+3C
    LL s2=0;//B+3*C
    for (int i=1;i<=n;++i){
        s2+=(LL)d[i]*(d[i]-1)/2;
    }
    
    LL AB=s1-s2;
    LL s=(LL)n*(n-1)/2*(n-2)/3;//X+A+B+C;
    cout << s-AB << endl;
    
    return 0;
}