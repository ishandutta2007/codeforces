#include <iostream>
using namespace std;
typedef long long LL;
LL n,a,b;
LL mn = 1e18, x, y;
void cac(LL low) {
    if(a<=low) {
        LL tmp=max((6*n+low-1)/low, b);
        if (low * tmp < mn) {
            mn = low * tmp;
            x = low, y = tmp;
        }
    }

    if(b<=low) {
        LL tmp=max((6*n+low-1)/low, a);
        if (low * tmp < mn) {
            mn = low * tmp;
            y = low, x = tmp;
        }        
    }
}
int main() {
    cin>>n>>a>>b;
    if(a*b>=6*n) {
        return !printf("%lld\n%lld %lld\n", a*b,a,b);
    }
    for(int low=1;low<=100000;low++) {
        cac(low);
    }
    printf("%lld\n%lld %lld\n", mn,x,y);
}

/*
(a+x) * (b+y) >= 6n
ax + by + xy >= 6n - ab
*/