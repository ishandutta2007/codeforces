#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2005;
int n , m;
char g[N][N];
int U[N][N] , D[N][N] , L[N][N] , R[N][N];
void work() {
    int i , j ;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%s" , g[i] + 1);
    }
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; j <= m ; ++ j) {
            if (g[i][j] == '#')
                U[i][j] = L[i][j] = 0;
            else {
                U[i][j] = U[i - 1][j] + 1;
                L[i][j] = L[i][j - 1] + 1;
            }
        }
    }
    for (i = n ; i > 0 ; -- i) {
        for (j = m ; j > 0 ; -- j) {
            if (g[i][j] == '#')
                D[i][j] = R[i][j] = 0;
            else {
                D[i][j] = D[i + 1][j] + 1;
                R[i][j] = R[i][j + 1] + 1;
            }
        }
    }
    LL res = 0;
    for (i = 2 ; i < n ; ++ i)
        if (R[i][1] >= m)
            ++ res;
    for (i = 2 ; i < m ; ++ i)
        if (D[1][i] >= n)
            ++ res;
    for (i = 2 ; i < n ; ++ i)
        for (j = 2 ; j < m ; ++ j) {
            int X = 0;
            int Y = 0;
            X += (L[i][j] >= j);
            X += (R[i][j] >= m - j + 1);
            Y += (U[i][j] >= i);
            Y += (D[i][j] >= n - i + 1);
            res += X * Y;
        }
    for (i = 2 ; i < n ; ++ i) {
        int X = 0;
        for (j = 2 ; j < m ; ++ j) {
            if (g[i][j] == '#')
                X = 0;
            else {
                int Y = 0;
                Y += (U[i][j] >= i);
                res += X * Y;if (j > 2) {
                X += (U[i][j - 1] >= i);
            }
            }

        }
    }
    for (i = 2 ; i < n ; ++ i) {
        int X = 0;
        for (j = 2 ; j < m ; ++ j) {
            if (g[i][j] == '#')
                X = 0;
            else {
                int Y = 0;
                Y += (D[i][j] >= n - i + 1);
                res += X * Y;if (j > 2) {
                X += (D[i][j - 1] >= n - i + 1);
            }
            }

        }
    }
    for (i = 2 ; i < n ; ++ i) {
        int X = 0;
        for (j = 2 ; j < m ; ++ j) {
            if (g[i][j] == '#')
                X = 0;
            else {
                int Y = 0;
                Y += (D[i][j] >= n - i + 1);
                res += X * Y;
            }
            if (j >= 2) {
                X += (U[i][j] >= i);
            }
        }
    }
    for (i = 2 ; i < n ; ++ i) {
        int X = 0;
        for (j = 2 ; j < m ; ++ j) {
            if (g[i][j] == '#')
                X = 0;
            else {
                int Y = 0;
                Y += (U[i][j] >= i);
                res += X * Y;
            }
            if (j >= 2) {
                X += (D[i][j] >= n - i + 1);
            }
        }
    }

    for (j = 2 ; j < m ; ++ j) {
        int X = 0;
        for (i = 2 ; i < n ; ++ i) {
            if (g[i][j] == '#')
                X = 0;
            else {
                int Y = 0;
                Y += (L[i][j] >= j);
                res += X * Y;
                            if (i > 2) {
                X += (L[i - 1][j] >= j);
            }
            }

        }
    }
    for (j = 2 ; j < m ; ++ j) {
        int X = 0;
        for (i = 2 ; i < n ; ++ i) {
            if (g[i][j] == '#')
                X = 0;
            else {
                int Y = 0;
                Y += (R[i][j] >= m - j + 1);
                res += X * Y;if (i > 2) {
                X += (R[i - 1][j] >= m - j + 1);
            }
            }

        }
    }
    for (j = 2 ; j < m ; ++ j) {
        int X = 0;
        for (i = 2 ; i < n ; ++ i) {
            if (g[i][j] == '#')
                X = 0;
            else {
                int Y = 0;
                Y += (R[i][j] >= m - j + 1);
                res += X * Y;if (i >= 2) {
                X += (L[i][j] >= j);
            }
            }

        }
    }
    for (j = 2 ; j < m ; ++ j) {
        int X = 0;
        for (i = 2 ; i < n ; ++ i) {
            if (g[i][j] == '#')
                X = 0;
            else {
                int Y = 0;
                Y += (L[i][j] >= j);
                res += X * Y;if (i >= 2) {
                X += (R[i][j] >= m - j + 1);
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