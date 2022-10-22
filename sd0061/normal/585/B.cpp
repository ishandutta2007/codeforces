#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>
#include <queue>
using namespace std;
const int N = 105;
typedef long long LL;

int n , K;
char g[3][N];
int row[N] , L[N] , R[N];
int d[3][N];
int dx[] = {0 , 1 , -1};

bool check(int x , int y , int t) {
    for (int j = 0 ; j < 26 ; ++ j) {
        if (row[j] == x) {
            int l = L[j] - t - t;
            int r = R[j] - t - t;
            if (l <= y && y <= r) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int T;
    scanf("%d" , &T);
    while (T --) {        
        scanf("%d%d" , &n , &K);
        for (int i = 0 ; i < 3 ; ++ i)
            scanf("%s" , g[i] + 1);
        memset(row , -1 , sizeof(row));
        memset(L , 0 , sizeof(L));
        memset(R , 0 , sizeof(R));
        
        int sx , sy;
        for (int i = 0 ; i < 3 ; ++ i) {
            for (int j = 1 ; j <= n ; ++ j) {
                if (isupper(g[i][j])) {
                    int k = g[i][j] - 'A';
                    row[k] = i;
                    if (!L[k])
                        L[k] = j;
                    R[k] = j;
                }
                if (g[i][j] == 's') {
                    sx = i;
                    sy = j;
                }
            }
        }
        queue<int> Q;
        Q.push(sx) , Q.push(sy);
        memset(d , -1 , sizeof(d));
        d[sx][sy] = 0;
        bool flag = 0;
        //for (int i = 0 ; i < 26 ; ++ i)
        //    printf("%d %d %d\n" , row[i] , L[i] , R[i]);
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            int y = Q.front(); Q.pop();
            //printf("%d %d\n" , x , y);
            if (check(x , y , d[x][y])) continue;
            if (y == n) {
                flag = 1;
                break;
            }
            for (int i = 0 ; i < 3 ; ++ i) {
                int X = x + dx[i] , Y = y + 1;
                if (X < 0 || X >= 3) continue;
                if (~d[X][Y]) continue;
                if (check(x , y + 1 , d[x][y])) continue;
                if (check(X , Y , d[x][y])) continue;
                
                d[X][Y] = d[x][y] + 1;
                Q.push(X); Q.push(Y);
            }
        }
        if (!flag)
            puts("NO");
        else
            puts("YES");
    }
    return 0;       
}