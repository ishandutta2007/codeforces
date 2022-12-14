#include <bits/stdc++.h>
using namespace std;

int main() {
    ///freopen("a.in", "r", stdin);
    int h1, h2;
    scanf("%d %d", &h1, &h2);
    int a, b;
    scanf("%d %d", &a, &b);
    int x = 14;
    int tot = 0;
    while(h1 < h2 && tot < (h1 + h2) * 10) {
        tot ++;
        if(x % 24 < 10 || x % 24 >= 22) h1 -= b;
        else h1 += a;
        x ++;
    }
    if(h1 < h2) puts("-1");
    else printf("%d\n", x / 24);
}