#include <bits/stdc++.h>
using namespace std;

int n,m;
char c[55][55];
set<int> row, col;
bool vis[55][55];

void dfs(int i, int j){
    row.insert(i), col.insert(j);
    vis[i][j] = 1;
    for(int a = 0; a < n; a++){
        if(a != i && c[a][j] == '#' && !vis[a][j]){
            dfs(a,j);
        }
    }
    for(int b = 0; b < m; b++){
        if(b != j && c[i][b] == '#' && !vis[i][b]){
            dfs(i,b);
        }
    }
}

int main() {
    for(int i = 0; i < 55; i++) fill(vis[i], vis[i]+55, 0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> c[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && c[i][j] == '#'){
                row.clear();
                col.clear();
                dfs(i, j);
                //cout << row.size() << " " << col.size() << endl;
                for(int x : row){
                    for(int y : col){
                        if(c[x][y] != '#') return !printf("No");
                    }
                }
            }
        }
    }
    return !printf("Yes");
}