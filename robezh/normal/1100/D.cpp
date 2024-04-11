#include <bits/stdc++.h>
using namespace std;

const int N = 670, M = 1005;

int n = 666;
int midx = 500, midy = 500;
int ax, ay;
int bx[N], by[N];
int ocu[M][M];
int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, -1, 1};
int sum[4];

int move(int nx, int ny) {
    cout << nx << " " << ny << endl;
    fflush(stdout);
    ax = nx; ay = ny;
    int k, x, y;
    cin >> k >> x >> y;
    if(k == -1 && x == -1 && y == -1) return 1;
    if(k == 0 && x == 0 && y == 0) return 1;
    k--;
    ocu[bx[k]][by[k]]--;
    bx[k] = x, by[k] = y;
    ocu[x][y] ++;
    return 0;
}

int main() {
    cin >> ax >> ay;
    for(int i = 0; i < n; i++){
        cin >> bx[i] >> by[i];
        ocu[bx[i]][by[i]] ++;
    }

    while(ax != 500 || ay != 500) {
        int nx = ax, ny = ay;
        if(nx < 500) nx++; if(nx > 500) nx--;
        if(ny < 500) ny++; if(ay > 500) ny--;
        if(ocu[nx][ny]) nx = ax;
        if(move(nx, ny)) return 0;
    }
    for(int i = 0; i < n; i++) sum[((bx[i] < 500) << 1) | (by[i] < 500)] ++;
    int id = 0;
    for(int i = 1; i < 4; i++){
        if(sum[i] < sum[id]) id = i;
    }
    while(true) {
        int nx = ax + dx[id], ny = ay + dy[id];
        if(ocu[nx][ny]) nx = ax;
        if(move(nx, ny)) return 0;
    }
}