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
    LL x,y,m;
    cin>>x>>y>>m;
    if ( x>=m || y>=m ) puts("0");
    else if ( x<=0 && y<=0 ) puts("-1");
    else {
        LL ans=0;
        while ( x<m && y<m ) {
            if ( x>y ) swap(x,y);
            LL t=(y-x)/y;
            x+=t*y;
            ans+=t;
            while ( x<=y ) {
                x+=y;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}