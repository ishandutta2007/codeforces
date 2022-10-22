#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <cctype>
using namespace std;
typedef long long LL;

const int N = 400;
int n , m ;
char a[N] , b[N];
bool g[N][N];
int id[20][20];

int main() {
    scanf("%d%d",&n,&m);
    scanf("%s%s",a,b);
    int i , j , k , x = 0 , y;
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < m ; ++ j) {
            id[i][j] = x ++;
        }
    }
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j < m ; ++ j) {
            if (a[i] == '<' && j > 0)
                g[id[i][j]][id[i][j - 1]] = 1;
            if (a[i] == '>' && j + 1 < m)
                g[id[i][j]][id[i][j + 1]] = 1;
        }
    }
    for (i = 0 ; i < m ; ++ i) {
        for (j = 0 ; j < n ; ++ j) {
            if (b[i] == '^' && j > 0)
                g[id[j][i]][id[j - 1][i]] = 1;
            if (b[i] == 'v' && j + 1 < n)
                g[id[j][i]][id[j + 1][i]] = 1;
        }
    }
    n = n * m;
    for (i = 0 ; i < n ; ++ i)
        g[i][i] = 1;
    for (k = 0 ; k < n ; ++ k)
        for (i = 0 ; i < n ; ++ i)
            for (j = 0 ; j < n ; ++ j)
                g[i][j] |= g[i][k] && g[k][j];
    bool flag = 0;
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < n ; ++ j)
            flag |= !g[i][j];
    puts(flag ? "NO" : "YES");
    return 0;
}