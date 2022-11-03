#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

int n,m,k;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    
    int minD=10000;
    for (int i=0;i<k;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        --x;--y;
        minD=min(minD,x);
        minD=min(minD,y);
        minD=min(minD,n-1-x);
        minD=min(minD,m-1-y);
    }
    
    if (minD<=4) puts("YES");
    else puts("NO");
    
    return 0;
}