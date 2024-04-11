// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 100010
long long a[N];
int main()
{
    int n,x;
    scanf("%d%d",&n,&x);
    for ( int i=1; i<=n; i++ ) cin>>a[i];
    int w=x;
    for ( int i=x; i>=1; i-- ) if ( a[i]<a[w] ) w=i;
    for ( int i=n; i>x; i-- ) if ( a[i]<a[w] ) w=i;
    long long t=a[w];
    for ( int i=1; i<=n; i++ ) if ( i!=w ) a[i]-=t,a[w]+=t;
    for ( int i=x; i!=w; i=(i==1?n:i-1) ) a[i]--,a[w]++;
    for ( int i=1; i<=n; i++ ) cout<<a[i]<<(i==n?'\n':' ');
    return 0;
}