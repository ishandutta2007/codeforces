#include <iostream>
#include <queue>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100000+10;

int n, m, r, k;

priority_queue< pair< int, pair<int, int> > > que;

map<int, int> mp[N];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
LL cac(int x, int y) {
    int row_u = max(x-r+1, 1);
    int row_d = min(x, n-r+1); 
    int col_u = max(y-r+1, 1);
    int col_d = min(y, m-r+1); 
    //printf("R(%d %d), C(%d, %d)\n", row_d, row_u, col_d, col_u);
    return max(row_d - row_u + 1, 0) * max(col_d - col_u + 1, 0);
}

int main() {
    cin >> n >> m >> r >> k;
    //cac(2, 2); return 0;
    que.push(make_pair(cac((n+1)/2,(m+1)/2), make_pair((n+1)/2,(m+1)/2)));
    mp[(n+1)/2][(m+1)/2] = 1;

    LL sum = 0;
    while (que.size() && k --) 
    {
        pair<int, pair<int, int> > top = que.top(); que.pop();
        int cx = top.second.first;
        int cy = top.second.second;
        //printf("(%d, %d) = %d\n", cx, cy, cac(cx, cy));
        sum += cac(cx, cy);
        for (int dr = 0; dr < 4; dr ++) {
            int nx = cx + dx[dr];
            int ny = cy + dy[dr];
            if (mp[nx][ny] || nx <= 0 || nx > n || ny <= 0 || ny > m)
                continue;
            mp[nx][ny] = 1;
            que.push(make_pair( cac(nx, ny), make_pair(nx, ny)));
        }
    }
    printf("%.10f\n", sum * 1.0 / (n-r+1) / (m-r+1));
}