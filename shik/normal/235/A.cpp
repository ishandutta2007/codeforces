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
    int n;
    scanf("%d",&n);
    long long ans=0;
    for ( int i=0; i<min(n,100); i++ )
        for ( int j=i; j<min(n,100); j++ ) {
            long long x=1LL*(n-i)*(n-j)/__gcd(n-i,n-j);
            for ( int k=j; k<min(n,100); k++ ) ans=max(ans,x*(n-k)/__gcd(x,0LL+n-k));
        }
    cout<<ans<<endl;
    return 0;
}