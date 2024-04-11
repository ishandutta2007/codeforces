#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
typedef pair<int, int> P;

int n,k;
char c[N][N];
int dx[] = {0, 1}, dy[] = {1, 0};
int dis[N][N];

int main(){
    scanf("%d%d", &n, &k);
    getchar();
    for(int i = 0; i < n; i++) scanf("%s", c[i]);

    memset(dis, 0x3f, sizeof(dis));
    deque<P> que;
    dis[0][0] = (c[0][0] == 'a' ? 0 : 1);
    que.push_back({0, 0});
    while(!que.empty()){
        auto p = que.front(); que.pop_front();
        int x = p.first, y = p.second;

        for(int d = 0; d < 2; d++){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < n && ny < n){
                if(dis[x][y] + (c[nx][ny] != 'a') < dis[nx][ny]){
                    dis[nx][ny] = dis[x][y] + (c[nx][ny] != 'a');
                    if(c[nx][ny] != 'a') que.push_back({nx, ny});
                    else que.push_front({nx, ny});
                }
            }
        }
    }
    vector<P> cur_v;
    int mxlen = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dis[i][j] <= k){
                if(mxlen < i + j + 1) mxlen = i + j + 1, cur_v.clear();
                if(mxlen == i + j + 1) cur_v.push_back({i, j});

            }
        }
    }
    string res;
    for(int i = 0; i < mxlen; i++) res.push_back('a');

    if(cur_v.empty()){
        cur_v.push_back({0,0});
        res.push_back(c[0][0]);
    }

    sort(cur_v.begin(), cur_v.end());
    while(true){
        if(cur_v[0].first + cur_v[0].second == 2 * n - 2) break;
        char mc = 'z' + 1;
        vector<P> nxt_p;
        for(auto p : cur_v){
            for(int d = 0; d < 2; d++){
                int nx = p.first + dx[d], ny = p.second + dy[d];
                if(nx < n && ny < n){
                    if(c[nx][ny] < mc) mc = c[nx][ny], nxt_p.clear();
                    if(c[nx][ny] == mc) nxt_p.push_back({nx, ny});
                }
            }
        }
        res.push_back(mc);
        auto it = unique(nxt_p.begin(), nxt_p.end());
        nxt_p.resize(distance(nxt_p.begin(), it));
        cur_v = nxt_p;
    }
    cout << res << endl;

}