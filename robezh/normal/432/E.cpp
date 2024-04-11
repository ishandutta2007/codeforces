#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n,m;
int mn[32], res[N][N];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
bool vis[N][N];

bool in_bound(int i, int j){return i >= 0 && i < n && j >= 0 && j < m;}

int min_c(int i, int j){
    int cur = 0;
    for(int t = 0; t < 4; t++){
        int nx = i + dx[t], ny = j + dy[t];
        if(in_bound(nx, ny) && vis[nx][ny]) cur |= (1 << res[nx][ny]);
    }

    return mn[cur];
}

bool good(int i, int j, int r){
    if(!in_bound(i + r, j + r)) return false;
    for(int k = 0; k <= r; k++){
        if(vis[i+r][j+k]) return false;
        if(vis[i+k][j+r]) return false;
    }
    return true;
}

int main(){
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 5; j++){
            if(!((1 << j) & i)){mn[i] = j; break; }
        }
    }
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j]) continue;
            int minc = min_c(i, j), cur = 1;
//            cout << i << ", " << j << ", " endl;
            while(true){
                if(j + cur < m && min_c(i, j + cur) == minc && good(i, j, cur)) cur++;
                else break;
            }
            for(int x = i; x < i + cur; x++){
                for(int y = j; y < j + cur; y++){
                    vis[x][y] = true;
                    res[x][y] = minc;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << (char)(res[i][j] + 'A');
        cout << endl;
    }
}