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
int main()
{
    LL xa,ya,xb,yb,xc,yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    LL z=(xb-xa)*(yc-ya)-(xc-xa)*(yb-ya);
    if ( z>0 ) puts("LEFT");
    else if ( z<0 ) puts("RIGHT");
    else puts("TOWARDS");
    return 0;
}