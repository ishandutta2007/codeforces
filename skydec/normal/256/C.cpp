#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long LL;
LL x, a[] = {3, 15, 81, 6723, 50625, 2562991875LL};
int sg[] = {0, 1, 2, 0, 3, 1, 2}, n, ans = 0;
int main() {

    scanf("%I64d",&n);
    while (n--) {
        scanf("%I64d",&x);
        int u=0;while(a[u]<x&&u<=5)u++;
        ans^=sg[u];
    }
    if(ans)printf("Furlo");else printf("Rublo");
    return 0;
}