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
    int n,x,c[3]={};
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) {
        scanf("%d",&x);
        c[i%3]+=x;
    }
    int ans=max_element(c,c+3)-c;
    char tbl[3][10]={"chest","biceps","back"};
    puts(tbl[ans]);
    return 0;
}