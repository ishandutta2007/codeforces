#include<bits/stdc++.h>
using namespace std;

#define N 100010

int n, s, d[N];

int main() {
    scanf("%d%d", &n, &s);
    for(int i = 1, x, y; i < n; i ++) {
        scanf("%d%d", &x, &y);
        d[x] ++, d[y] ++;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i ++) if(d[i] == 1) cnt ++;
    printf("%.7lf\n", 2.0 * s / cnt);
}