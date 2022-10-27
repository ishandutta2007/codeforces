/*









*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
char s[52][52], op[102];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int p[4]={0,1,2,3};

int ok(int x, int y) {
    return x<=n && x>=1 && y<=m && y>=1 && s[x][y]!='#';
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s[i]+1);
    }
    scanf("%s", op+1);
    int sx, sy;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (s[i][j] == 'S')
                sx = i, sy = j;
        }
    }
    int len = strlen(op+1);
    int ans = 0;

    do {
        bool flag = 1, arrive = 0;
        int cx = sx, cy = sy;
        for (int i = 1; i <= len; i ++) {
            int dir = op[i] - '0';
            
            cx += dx[ p[dir] ];
            cy += dy[ p[dir] ];

            if (!ok(cx, cy)) {
                flag = 0;
            } else {
                if (s[cx][cy] == 'E') {
                    arrive = 1;
                    break;
                }
            }
        }
        if (flag && arrive) ans ++;

    } while (next_permutation(p,p+4));

    printf("%d\n", ans);
}