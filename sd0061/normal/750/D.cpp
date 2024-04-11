#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n , c[N];

int dx[] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
int dy[] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

bool f[31][N][N][8];
bool res[N][N];
queue<int> Q;
void update(int k , int x , int y , int d) {
    if (k >= n) return;
    if (!f[k][x][y][d]) {
        f[k][x][y][d] = 1;
        Q.push(k);
        Q.push(x);
        Q.push(y);
        Q.push(d);
    }
}

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &c[i]);
    }
    update(0 , 250 , 250 , 0);
    while (!Q.empty()) {
        int k = Q.front(); Q.pop();
        int x = Q.front(); Q.pop();
        int y = Q.front(); Q.pop();
        int d = Q.front(); Q.pop();
        int X = x , Y = y;
        for (int i = 0 ; i < c[k] ; ++ i) {
            res[X][Y] = 1;
            X += dx[d] , Y += dy[d];
        }
        X -= dx[d] , Y -= dy[d];
        int dd = (d + 7) % 8;
        update(k + 1 , X + dx[dd] , Y + dy[dd] , dd);
        dd = (d + 1) % 8;
        update(k + 1 , X + dx[dd] , Y + dy[dd] , dd);
    }
    int cnt = 0;
    for (int i = 0 ; i < N ; ++ i)  {
        for (int j = 0 ; j < N ; ++ j) {
            cnt += res[i][j];
        }
    }
    cout << cnt << endl;
}