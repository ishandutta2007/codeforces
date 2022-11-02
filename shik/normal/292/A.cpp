// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 1010
int t[N],c[N];
int main()
{
    int n;
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) scanf("%d%d",t+i,c+i);
    int last=0,big=0,now=0;
    for ( int i=1; i<=n; i++ ) {
        now-=min(now,t[i]-t[i-1]);
        now+=c[i];
        big=max(now,big);
        last=max(last,t[i]+now);
    }
    printf("%d %d\n",last,big);
    return 0;
}