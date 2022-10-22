#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 105;

int n , m;
char s[N][N];
int res[N][N];
bool f[N][N];
void work() {
    int i , j , x , y;
    scanf("%d" , &n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j) {
            if (s[i][j] != 'o')
                continue;
            ++ m;
            for (x = -n ; x <= n ; ++ x)
                for (y = -n ; y <= n ; ++ y) {
                    int X = i + x , Y = j + y;
                    if (X < 1 || X > n || Y < 1 || Y > n)
                        ++ res[x + n][y + n];
                    else {
                        if (s[X][Y] != '.')
                            ++ res[x + n][y + n];
                    }
                }           
        }
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j) {
            if (s[i][j] != 'o')
                continue;
            for (x = -n ; x <= n ; ++ x)
                for (y = -n ; y <= n ; ++ y) {
                    if (res[x + n][y + n] < m)
                        continue;
                    int X = i + x , Y = j + y;
                    if (X < 1 || X > n || Y < 1 || Y > n);
                    else {
                        f[X][Y] = 1;
                    }
                }           
        }
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= n ; ++ j) {
            if (s[i][j] == 'x' && !f[i][j]) {
                puts("NO");
                return;
            }
        }
    puts("YES");
    for (i = 1 ; i < n + n ; ++ i) {
        for (j = 1 ; j < n + n ; ++ j) {
            if (i == n && j == n) {
                putchar('o');
            } else {
                putchar(".x"[res[i][j] == m]);
            }
        }
        puts("");
    }
    
}

int main() {
    work();
    return 0;
}