#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;
LL x,y,z;
int main() {
    cin>>x>>y>>z;
    LL ans=(x+y)/z;
    printf("%lld ", ans);
    if(x%z==0 || y%z==0 || x/z+y/z==ans) printf("0\n");
    else
    {
        LL mn = 1e18;
        LL nx = z * (x/z) + z;
        if (nx - x <= y) mn = min(mn, nx - x);
        LL ny = z * (y/z) + z;
        if (ny - y <= x) mn = min(mn, ny - y);
        printf("%lld\n", mn);
    }
}