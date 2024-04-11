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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,x,c[10010]={};
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) {
        scanf("%d",&x);
        c[x]++;
    }
    int l=0,r=0,m=0,big=0;
    while ( l<=5000 ) {
        m-=c[l++];
        m+=c[++r];
        m+=c[++r];
        big=max(big,m);
    }
    printf("%d\n",n-big);
    return 0;
}