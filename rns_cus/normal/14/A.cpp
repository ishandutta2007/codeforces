#include <stdio.h>
#include <string.h>
#define N 51
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, m;
char s[N][N];

int  main(){
    scanf("%d %d", &n, &m);
    int stx = n, sty = m, enx = -1, eny = -1;
    for(int i = 0; i < n; i ++) {
        scanf("%s", s[i]);
        for(int j = 0; j < m; j ++){
            if(s[i][j] == '*') {
                stx = min(stx, i);
                sty = min(sty, j);
                enx = max(enx, i);
                eny = max(eny, j);
            }
        }
    }

    for(int i = stx; i <= enx; i ++){
        for(int j = sty; j <= eny; j ++) printf("%c", s[i][j]);
        puts("");
    }
}