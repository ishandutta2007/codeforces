#include <bits/stdc++.h>
using namespace std;

int n,m;
char c[55][55];
bool vis[55][55];
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,-1,1};

bool in_bound(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool dfs(int x, int y, int px, int py){
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(!in_bound(nx,ny) || c[nx][ny] != c[x][y]) continue;
        if(vis[nx][ny] && nx != px && ny != py) return true;
        if(!vis[nx][ny] && dfs(nx, ny, x, y)) return true;
    }
    return false;
}

int main(){
    for(int i = 0; i < 55; i++) fill(vis[i], vis[i]+55, 0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> c[i][j];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && dfs(i, j, -1, -1)) return !printf("Yes");
        }
    }
    return !printf("No");


}