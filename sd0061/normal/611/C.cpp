#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 505;

int n , m , q;
char g[N][N];
int s1[N][N] , s2[N][N];

int main() {

    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%s" , g[i] + 1);
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= m ; ++ j) {
            if (i + 1 <= n && g[i][j] == '.' && g[i + 1][j] == '.')
                s1[i][j] = 1;
            if (j + 1 <= m && g[i][j] == '.' && g[i][j + 1] == '.')
                s2[i][j] = 1;            
        }
    }
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            s1[i][j] += s1[i][j - 1];
            s2[i][j] += s2[i][j - 1];            
        }
    for (int i = 1 ; i <= n ; ++ i)
        for (int j = 1 ; j <= m ; ++ j) {
            s1[i][j] += s1[i - 1][j];
            s2[i][j] += s2[i - 1][j];            
        }
    scanf("%d" , &q);

    while (q --) {
        int x1 , y1 , x2 , y2;
        scanf("%d%d%d%d" , &x1 , &y1 , &x2 , &y2);
        -- x1 , -- y1;
        int res = 0;
        -- x2;
        res += s1[x2][y2] + s1[x1][y1];
        res -= s1[x2][y1] + s1[x1][y2];
        ++ x2;
        -- y2;
        res += s2[x2][y2] + s2[x1][y1];
        res -= s2[x2][y1] + s2[x1][y2];
        printf("%d\n" , res);
    }
    
    return 0;
}