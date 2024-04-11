#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 100000+10;
typedef pair<int, int> pii;
int n, m, x, y, s;
int vis[N][2], sta[N][2];
vector<int> g[N], rg[N];
int nex[N][2], los[N][2], win[N][2], dra[N][2], sum[N][2];

void bfs() {
    queue< pair<int,int> > que;
    for (int i = 1; i <= n; i  ++) {
        if (g[i].size() == 0) {
            que.push(make_pair(i,0)); vis[i][0] = 1; sta[i][0] = -1;
            que.push(make_pair(i,1)); vis[i][1] = 1; sta[i][1] = -1;
        }
    }
    while (que.size()) {
        pii top = que.front(); que.pop();
        int x = top.first, y = top.second;
        for (int i = 0; i < rg[x].size(); i ++) {
            int p = rg[x][i];
            sum[p][y^1] ++;
            if (vis[p][y^1]) continue;

            if (y == 0) {

                if (sta[x][y] == 1) {
                    nex[p][y^1] = x;
                    sta[p][y^1] = -1; que.push(make_pair(p,y^1)); vis[p][y^1] = 1;
                }
                if (sta[x][y] == 0) {
                    dra[p][y^1] ++; 
                    if (sum[p][y^1] == g[p].size()) {
                        sta[p][y^1] = 0; que.push(make_pair(p,y^1)); vis[p][y^1] = 1;                        
                    }
                }
                if (sta[x][y] == -1) {
                    win[p][y^1] ++;
                    if (win[p][y^1] == g[p].size()) {
                        sta[p][y^1] = 1; que.push(make_pair(p,y^1)); vis[p][y^1] = 1;
                    }

                }
            }
        
            if (y == 1) {

                if (sta[x][y] == -1) {
                    nex[p][y^1] = x;
                    sta[p][y^1] = 1; que.push(make_pair(p,y^1)); vis[p][y^1] = 1;
                }

                if (sta[x][y] == 0) {
                    dra[p][y^1] ++; 
                    if (sum[p][y^1] == g[p].size()) {
                        sta[p][y^1] = 0; que.push(make_pair(p,y^1)); vis[p][y^1] = 1;                        
                    }
                }
                
                if (sta[x][y] == 1) {
                    los[p][y^1] ++;
                    if (los[p][y^1] == g[p].size()) {
                        sta[p][y^1] = -1; que.push(make_pair(p,y^1)); vis[p][y^1] = 1;
                    }

                }
            }


        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1;i <= n; i ++) {
        scanf("%d", &x);
        for (int j = 1; j <= x; j ++) {
            scanf("%d", &y);
            g[i].push_back(y);
            rg[y].push_back(i);
        }
    }
    scanf("%d", &s);
    bfs();
    if (sta[s][0] == 1) {
        printf("Win\n");
        int cur = s, b = 0;
        printf("%d", s);
        while (nex[cur][b]) {
            printf(" %d", nex[cur][b]);
            cur = nex[cur][b];
            b = 1 - b;
        } 
        printf("\n");
    }
    if (sta[s][0] == -1) printf("Lose\n");
    if (sta[s][0] == 0) printf("Draw\n");
}