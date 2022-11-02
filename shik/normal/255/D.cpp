// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
LL s1( LL n ) { return n<=0?0:n*n; }
LL s2( LL n ) { return n<=0?0:n*(n+1)/2; }
int main()
{
    LL n,x,y,c;
    cin>>n>>x>>y>>c;
    LL l=0,r=2*n;
    while ( l!=r ) {
        LL m=(l+r)/2;
        LL now=s1(m)+s1(m+1);
        now-=s1(x+m-n);
        now-=s1(m-x+1);
        now-=s1(y+m-n);
        now-=s1(m-y+1);
        now+=s2(m-(n-x + n-y)-1);
        now+=s2(m-(n-x + y-1)-1);
        now+=s2(m-(x-1 + n-y)-1);
        now+=s2(m-(x-1 + y-1)-1);
        if ( now>=c ) r=m;
        else l=m+1;
    }
    cout<<l<<endl;
    return 0;
}