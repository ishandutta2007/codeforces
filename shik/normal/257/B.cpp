// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int solve( int n, int m ) {
    int ans=0,c=0,p=1;
    while ( n+m>0 ) {
        if ( p==1 ) {
            if ( c==0 ) n--,c=1;
            else if ( c==1 && n>0 ) n--,c=1,ans++;
            else if ( c==2 && m>0 ) m--,c=2,ans++;
            else if ( n==0 ) m--,c=2;
            else if ( m==0 ) n--,c=1;
            else puts("QQ1");
            p=2;
        } else if ( p==2 ) {
            if ( c==1 && m>0 ) m--,c=2;
            else if ( c==2 && n>0 ) n--,c=1;
            else if ( n==0 ) m--,c=2,ans++;
            else if ( m==0 ) n--,c=1,ans++;
            else puts("QQ2");
            p=1;
        }
    }
    return ans;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a=solve(n,m);
    int b=solve(m,n);
    int ans=max(a,b);
    printf("%d %d\n",ans,n+m-ans-1);
    return 0;
}