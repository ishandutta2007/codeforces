#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int N = 1005, INF = (int)1e9;

int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
int n,m;
char mp[N][N];
int dis[3][N][N];

bool valid(int nx, int ny){
    return nx >= 0 && ny >= 0 && nx < n && ny < m && mp[nx][ny] != '#';
}

int main(){
    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> mp[i][j];
    }
    for(int s = 0; s < 3; s++){
        queue<P> que;
        for(int i = 0; i < n; i++){ for(int j = 0; j < m; j++){
                if(mp[i][j] - '1' == s){
                    dis[s][i][j] = 0;
                    que.push({i, j});
                }
            }}
        while(!que.empty()){
            P p = que.front(); que.pop();
            int x = p.first, y = p.second;
            for(int d = 0; d < 4; d++){
                int nx = x + dx[d], ny = y + dy[d];
                if(valid(nx, ny) && dis[s][x][y] + 1 < dis[s][nx][ny]){
                    dis[s][nx][ny] = dis[s][x][y] + 1;
                    que.push({nx, ny});
                }
            }
        }
    }
    ll res = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] != '.') continue;
            ll cur = 0;
            for(int t = 0; t < 3; t++){
                cur += dis[t][i][j];
            }
            res = min(res, cur - 2);
        }
    }
    for(int t = 0; t < 3; t++){
        int cur[3];
        memset(cur, 0x3f, sizeof(cur));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mp[i][j] != t + '1') continue;
                for(int k = 0; k < 3; k++){
                    cur[k] = min(cur[k], max(0, dis[k][i][j]-1));
                }

            }
        }
        ll cursum = 0;
        for(int d = 0; d < 3; d ++) cursum += cur[d];
        res = min(res, cursum);
    }
    if(res < INF) cout << res << endl;
    else cout << -1 << endl;
}