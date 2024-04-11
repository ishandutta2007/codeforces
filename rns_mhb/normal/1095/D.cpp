#include<bits/stdc++.h>
using namespace std;

#define N 200010

int n, nxt[N][2];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d%d", &nxt[i][0], &nxt[i][1]);
    if(n == 3) {
        puts("1 2 3");
        return 0;
    }
    int x = 1;
    printf("1 ");
    while(1) {
        int y = nxt[x][0], z = nxt[x][1];
        if(y == nxt[z][0] || y == nxt[z][1]) swap(y, z);
        if(y == 1) break;
        printf("%d ", y);
        x = y;
    }
    puts("");
}