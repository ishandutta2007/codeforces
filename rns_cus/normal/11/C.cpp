//11_C
#include <bits/stdc++.h>
using namespace std;

#define N 255

const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

typedef pair <int, int> pii;
queue <pii> q;

int n, m;
char s[N][N];
int vis[N][N];

void update_upperleft(int &y1, int &x1, int yy, int xx){
    if(y1 < yy) return ;
    if(y1 > yy) {y1 = yy, x1 = xx; return ;}
    if(x1 > xx) x1 = xx;
}

void update_lowerright(int &y1, int &x1, int yy, int xx){
    if(y1 > yy) return;
    if(y1 < yy) {y1 = yy, x1 = xx; return;}
    if(x1 < xx) x1 = xx;
}

bool check(int y1, int x1, int y2, int x2, int cnt, int num){
    if(x1 != x2){
        if(y2 - y1 != x2 - x1) return 0;
        if(cnt != 4 * (y2 - y1)) return 0;
        for(int y = y1; y <= y2; y ++) if(vis[y][x1] != num || vis[y][x2] != num) return 0;
        for(int x = x1; x <= x2; x ++) if(vis[y1][x] != num || vis[y2][x] != num) return 0;
        return 1;
    }

    if(x1 == x2){
        int len = (y2 - y1) / 2 + 1;
        if(len < 2) return 0;
        if(y2 - y1 != len * 2 - 2) return 0;
        if(cnt != 4 * len - 4) return 0;
        if(x1 + len - 1 >= m || x1 - len + 1 < 0) return 0;
        for(int i = 0; i < len; i ++) if(vis[y1 + i][x1 - i] != num || vis[y1 + i][x1 + i] != num) return 0;
        for(int i = 0; i < len; i ++) if(vis[y2 - i][x2 - i] != num || vis[y2 - i][x2 + i] != num) return 0;
        return 1;
    }
}

int main(){
    ///freopen("1.in", "r", stdin);
    ///freopen("1.out", "w", stdout);
    int TC, num = 0;
    for(scanf("%d", &TC); TC --;){
        num ++;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i ++) scanf("%s", s[i]);
        ///for(int i = 0; i < n; i ++) puts(s[i]); puts("");

        int ans = 0;
        for(int i = 0; i < n; i ++) for(int j = 0; j < m; j ++) {
            if(vis[i][j] == num) continue;
            if(s[i][j] == '0') continue;

            int y1 = i, x1 = j, y2 = i, x2 = j;
            int cnt = 1;
            vis[i][j] = num;
            q.push(pii(i, j));
            while(!q.empty()){
                pii p = q.front(); q.pop();
                int y = p.first, x = p.second;
                for(int k = 0; k < 8; k ++){
                    int yy = y + dy[k], xx = x + dx[k];
                    if(yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
                    if(s[yy][xx] == '0') continue;
                    if(vis[yy][xx] == num) continue;
                    vis[yy][xx] = num;
                    q.push(pii(yy, xx));
                    cnt ++;
                    update_upperleft(y1, x1, yy, xx);
                    update_lowerright(y2, x2, yy, xx);
                }
            }

            if(check(y1, x1, y2, x2, cnt, num)) ans ++;
        }

        printf("%d\n", ans);
    }
    ///return 9;
}