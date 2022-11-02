// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    int n,ans[]={2,3,1,2,1};
    scanf("%d",&n);
    printf("%d\n",ans[n-1]);
    return 0;
}