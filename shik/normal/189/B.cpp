// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int main()
{
    int n,m;
    long long ans=0;
    scanf("%d%d",&n,&m);
    for ( int i=2; i<=n; i+=2 ) for ( int j=2; j<=m; j+=2 ) ans+=(n-i+1)*(m-j+1);
    cout<<ans<<endl;
    return 0;
}