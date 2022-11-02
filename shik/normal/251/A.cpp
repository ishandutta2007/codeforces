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
int n,d,a[100010];
int main()
{
    scanf("%d%d",&n,&d);
    for ( int i=0; i<n; i++ ) scanf("%d",a+i);
    LL ans=0;
    for ( int i=0,j=0; i<n; i++ ) {
        while ( j<n && a[j]-a[i]<=d ) j++;
        ans+=1LL*(j-i-1)*(j-i-2)/2;
    }
    cout<<ans<<endl;
    return 0;
}