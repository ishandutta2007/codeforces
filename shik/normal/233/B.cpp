// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
int s( LL x ) {
    int r=0;
    while ( x ) {
        r+=x%10;
        x/=10;
    }
    return r;
}
int main()
{
    LL n;
    cin>>n;
    LL x=sqrtl(n);
    while ( x*x+100*x > n ) {
        if ( x*x+s(x)*x==n ) {
            cout<<x<<endl;
            return 0;
        }
        x--;
    }
    puts("-1");
    return 0;
}