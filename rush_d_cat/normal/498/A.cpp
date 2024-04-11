#include <iostream>
using namespace std;
typedef long long LL;

int x1, y1, x2, y2;
int n, a[302], b[302], c[302];

int main() {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d", &n);

    int ans = 0;
    for(int i=1;i<=n;i++) {

        scanf("%d %d %d", &a[i], &b[i], &c[i]);

        int x = -1, y = -1;
        if((LL)a[i]*x1 + (LL)b[i]*y1 + c[i] > 0) x = 1;
        if((LL)a[i]*x2 + (LL)b[i]*y2 + c[i] > 0) y = 1;
        if(x * y < 0) ans ++;
    
    }

    printf("%d\n", ans);
}