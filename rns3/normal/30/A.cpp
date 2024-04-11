#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, n, b;
    scanf("%d%d%d", &a, &b, &n);
    bool fg = 0;
    for(int x = -1000; x <= 1000; x ++) {
        int xx = a;
        bool ok = 1;
        for(int j = 0; j < n; j ++) {
            if(xx * x > 1000 || xx * x < -1000) {ok = 0; break;}
            xx *= x;
        }
        if(!ok) continue;
        if(xx != b) continue;
        fg = 1, printf("%d\n", x) ;
        break;
    }
    if(!fg) puts("No solution");
}