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
    int n,cx[2]={},cy[2]={};
    scanf("%d",&n);
    while ( n-- ) {
        int x,y;
        scanf("%d%d",&x,&y);
        cx[x]++; cy[y]++;
    }
    printf("%d\n",min(cx[0],cx[1])+min(cy[0],cy[1]));
    return 0;
}