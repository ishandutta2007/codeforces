#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
typedef long long LL;
const int N = 1005;
using namespace std;

int n , m;
char g[N][N];
int dx[] = {1 , 0 , -1 , 0} , dy[] = {0 , 1 , 0 , -1};
int d[3][N][N];
bool f[N][N];
struct opt {
    int x , y , w;
};
void cal(char c , int dist[][N]) {    
    deque< opt > Q; 
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            if (g[i][j] == c) {
                dist[i][j] = 0;
                Q.push_back((opt){i , j , 0});
            } else {
                dist[i][j] = 1e8;
            }
            f[i][j] = 0;
        }
    while (!Q.empty()) {
        opt t = Q.front(); Q.pop_front();
        if (f[t.x][t.y]) continue; f[t.x][t.y] = 1;
        int x = t.x , y = t.y;
        //cout << x << ' ' << y << ' ' << t.w << endl;
        for (int i = 0 ; i < 4 ; ++ i) {
            int X = x + dx[i] , Y = y + dy[i];
            if (g[X][Y] == '#' || !g[X][Y])
                continue;
            if (!f[X][Y]) {
                if (g[X][Y] == '.') {
                    if (t.w + 1 < dist[X][Y]) {
                        dist[X][Y] = t.w + 1;
                        Q.push_back((opt){X , Y , t.w + 1});
                    }
                } else {
                    if (t.w < dist[X][Y]) {
                        dist[X][Y] = t.w;
                        Q.push_front((opt){X , Y , t.w });
                    }                
                }
            }
        }
    }
    
    /*or (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            printf("%10d%c" , dist[i][j] , " \n"[j == m]);
            }*/
}

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%s" , g[i] + 1);
    for (int i = 0 ; i < 3 ; ++ i)
        cal('1' + i , d[i]);
    int res = 1 << 30;
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            if (g[i][j] == '#') continue;
            int sum = 0;
            for (int k = 0 ; k < 3 ; ++ k)
                sum += d[k][i][j];
            if (g[i][j] == '.') sum -= 2;
            res = min(res , sum);
        }
    if (res >= 1e7)
        res = -1;
    printf("%d\n" , res);
    return 0;
}