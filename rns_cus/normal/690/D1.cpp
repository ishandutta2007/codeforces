#include <bits/stdc++.h>
using namespace std;
#define N 210
char s[N];
int a[N][N], vis[N];
int main() {
    //freopen("1.in", "r", stdin);
    int R, C;
    scanf("%d%d", &R, &C);
    for(int i = 1; i <= R; i ++){
        scanf("%s", s);
        for(int j = 1; j <= C; j ++) {
            if(s[j - 1] == 'B') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    for(int i = 1; i <= C; i ++) if(a[R][i]) {
        vis[i] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= C;) {
        if(!vis[i]) {
            i ++;
            continue;
        }
        cnt ++;
        while(i <= C && vis[i]) i ++;
    }
    printf("%d\n", cnt);
}