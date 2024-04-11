#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
char mp[maxn][maxn];
int flag[maxn][maxn], tim[maxn][maxn];
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
int n, m, T;
int valid(int x, int y){
    return x>=0 && y>=0 && x<n && y<m;
}
pair<int,int> que[10000000];
int main(){
    scanf("%d%d%d", &n,&m,&T);
    int h = 0, t= 0;
    for (int i = 0; i<n; i++) scanf("%s", mp[i]);
    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            for (int d = 0; d < 4; d++){
                int _x = i + dx[d], _y = j + dy[d];
                if (valid(_x, _y) && mp[_x][_y] == mp[i][j]) flag[i][j] = 1;
                if (flag[i][j]){
                    que[t++] = make_pair(i,j);
                    tim[i][j] = 0;
                }
            }
    int cnt = 0;
    while (h<t){
        int tmp = t; cnt++;
        for (int i = h; i<tmp; i++){
            int x = que[i].first, y = que[i].second;
            for (int d = 0; d < 4; d++){
                int _x = x+dx[d], _y = y+dy[d];
                if (valid(_x, _y) && !flag[_x][_y]) {
                    flag[_x][_y] = 1;
                    tim[_x][_y] = cnt;
                    que[t++] = make_pair(_x, _y);
                }
            }
        }
        h = tmp;
    }
    while (T--){
        int x, y; long long p;
        scanf("%d%d%lld", &x, &y, &p);
        x--; y--;
        if (!flag[x][y] || p<=tim[x][y]) printf("%c\n", mp[x][y]);
        else puts(((p-tim[x][y])&1)^(mp[x][y]-'0')?"1":"0");
    }
    return 0;
}