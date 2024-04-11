#include<bits/stdc++.h>
using namespace std;

#define N 55

char s[N][N], p[N<<1];
int sx, sy, d[4];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool go() {
    int x = sx, y = sy;
    for(int i = 0; p[i]; i ++) {
        int j = d[p[i]-'0'];
        x += dx[j], y += dy[j];
        if(s[x][y] == '#') return 0;
        if(s[x][y] == 'E') return 1;
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%s", s[i]+1);
    for(int i = 0; i <= n+1; i ++) s[i][0] = s[i][m+1] = '#';
    for(int i = 0; i <= m+1; i ++) s[0][i] = s[n+1][i] = '#';
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) if(s[i][j] == 'S') {
        sx = i, sy = j;
        break;
    }
    scanf("%s", p);
    int ans = 0;
    for(int i = 0; i < 4; i ++) d[i] = i;
    while(1) {
        if(go()) ans ++;
        if(!next_permutation(d, d+4)) break;
    }
    cout << ans << endl;
}