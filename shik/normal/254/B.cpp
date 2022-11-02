// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
const int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int in[1000],out[1000];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    while ( n-- ) {
        int m,d,p,t;
        scanf("%d%d%d%d",&m,&d,&p,&t);
        int x=123;
        for ( int i=1; i<m; i++ ) x+=mon[i];
        x+=d;
        in[x-t]+=p;
        out[x-1]+=p;
    }
    int now=0,ans=0;
    for ( int i=0; i<1000; i++ ) {
        now+=in[i];
        ans=max(ans,now);
        now-=out[i];
    }
    printf("%d\n",ans);
    return 0;
}