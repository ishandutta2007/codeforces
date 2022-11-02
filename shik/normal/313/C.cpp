// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 2000010
int n,a[N];
int main()
{
    scanf("%d",&n);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    sort(a,a+n);
    reverse(a,a+n);
    long long ans=0;
    while ( n ) {
        for ( int i=0; i<n; i++ ) ans+=a[i];
        n/=4;
    }
    cout << ans << endl;
    return 0;
}