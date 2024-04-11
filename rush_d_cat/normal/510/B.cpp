#include <iostream>
using namespace std;
int n, m, vis[52][52];
char s[52][52];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ok = 0;
bool inside(int x, int y) {
    return x<=n&&x>=1&&y<=m&&y>=1;
}
void dfs(int i, int j, int pi, int pj) {
    if(vis[i][j]) return;
    //cout << i << " " << j << endl;
    vis[i][j] = 1;
    for(int dir=0;dir<4;dir++) {
        int x = i + dx[dir];
        int y = j + dy[dir];
        if(x == pi && y == pj) continue;
        if(inside(x, y) && s[x][y] == s[i][j]) {
            if(vis[x][y]) ok = 1;
            dfs(x, y, i, j);
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        scanf("%s", s[i]+1);
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dfs(i,j,-1,-1);
        }
    }
    printf("%s\n", ok?"Yes":"No");
}