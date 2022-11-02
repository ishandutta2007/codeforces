// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 1000010
int sol[N];
void go( int n ) {
    if ( n<=0 ) return;
    int m=n;
    while ( m&(m-1) ) m-=m&-m;
    for ( int i=m,j=m-1; i<=n; i++,j-- ) {
        sol[i]=j;
        sol[j]=i;
    }
    go(m-1-(n-m+1));
}
int main()
{
    int n;
    scanf("%d",&n);
    go(n);
    long long ans=0;
    for ( int i=0; i<=n; i++ ) ans+=i^sol[i];
    cout<<ans<<endl;
    for ( int i=0; i<=n; i++ ) printf("%d%c",sol[i],i==n?'\n':' ');
    return 0;
}