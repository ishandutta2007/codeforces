#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i, j, a[10], x[10], y[10], k;
    int dx[10], dy[10], xx, yy;
    char c[10];
    scanf("%d", &n);
    scanf("%s", &c);
    for(i = 0; i < n; i ++) a[i] = c[i]- '0';
    x[0] = 2, y[0] = 4;
    for(i = 1; i <= 9; i ++) x[i] = (i - 1) % 3 + 1, y[i] = (i - 1) / 3 + 1;
    //for(i = 0; i < 10; i ++) printf("%d %d %d\n", i, x[i], y[i]);
    for(i = 0; i < n - 1; i ++)
        dx[i] = x[a[i + 1]] - x[a[i]], dy[i] = y[a[i + 1]] - y[a[i]];
    for(i = 0; i <= 9; i ++) {
        if(i == a[0]) continue;
        xx = x[i], yy = y[i];
        for(j = 0; j < n - 1; j ++) {
            xx += dx[j], yy += dy[j];
            if(xx < 1 || xx > 3) break;
            if(yy == 4 && xx == 2) continue;
            if(yy > 3 || yy < 1) break;
        }
        if(j == n - 1) {puts("NO"); return 0;}
    }
    puts("YES");
}