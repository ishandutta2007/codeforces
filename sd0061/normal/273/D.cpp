#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 155;
const int Q = 1e9 + 7;

int n , m;
LL f[N][N][N][4];
LL s[4][N][N];

inline void add(int l , int i , int x , int j , int y , LL w) {
    ++ x , ++ y;
    s[l][i][j] += w;
    s[l][i][y] -= w;
    s[l][x][j] -= w;
    s[l][x][y] += w;
}

void work() {
    int i , j , k , l;
    scanf("%d%d",&n,&m);
    LL res = 0;
    for (i = 1 ; i <= n ; ++ i) {
        memset(s , 0 , sizeof(s));
        add(0 , 1 , m , 1 , m , 1);
        for (j = 1 ; j <= m ; ++ j)
            for (k = j ; k <= m ; ++ k) {
                add(0 , 1 , j , k , m , f[i - 1][j][k][0]);
                add(1 , j + 1 , k , k , m , f[i - 1][j][k][0]);
                add(2 , 1 , j , j , k - 1 , f[i - 1][j][k][0]);
                add(3 , j + 1 , m , 1 , k - 1 , f[i - 1][j][k][0]);
                
                add(1 , j , k , k , m , f[i - 1][j][k][1]);
                add(3 , j , m , 1 , k - 1 , f[i - 1][j][k][1]);

                add(2 , 1 , j , j , k , f[i - 1][j][k][2]);
                add(3 , j + 1 , m , 1 , k , f[i - 1][j][k][2]);

                add(3 , j , m , 1 , k , f[i - 1][j][k][3]);
            }
        for (l = 0 ; l < 4 ; ++ l) {
            for (j = 1 ; j <= m ; ++ j)
                for (k = 1 ; k <= m ; ++ k) {
                    s[l][j][k] += s[l][j - 1][k] + s[l][j][k - 1];
                    s[l][j][k] -= s[l][j - 1][k - 1];
                    s[l][j][k] %= Q , s[l][j][k] += Q , s[l][j][k] %= Q;
                    if (j <= k) {
                        f[i][j][k][l] = s[l][j][k];                        
                        res += s[l][j][k] , res %= Q;
                    }
                }
        }      
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}