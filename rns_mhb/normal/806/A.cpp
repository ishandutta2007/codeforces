#include<bits/stdc++.h>
using namespace std;

int main() {
    int t, x, y, p, q, r;
    scanf("%d", &t);
    while(t --) {
        scanf("%d%d%d%d", &x, &y, &p, &q);
        if(p == q) printf("%d\n", x < y ? -1 : 0);
        else if(p == 0) printf("%d\n", x ? -1 : 0);
        else {
            r = max((x + p - 1) / p, (y + q - 1) / q);
            r = max((y - x + q - p - 1) / (q - p), r);
            printf("%I64d\n", 1ll * r * q - y);
        }
    }
}