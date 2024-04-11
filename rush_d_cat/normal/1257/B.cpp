#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
int T;LL x,y;
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld",&x,&y);
        if (x >= 4) printf("YES\n");
        else if (x == 1 && y == 1) printf("YES\n");
        else if (x == 2 && y <= 3) printf("YES\n");
        else if (x == 3 && y <= 3) printf("YES\n");
        else printf("NO\n");
    }
}