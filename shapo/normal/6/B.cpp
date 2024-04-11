#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <ctype.h>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

#define maxn 256

using namespace std;

char cur[maxn][maxn];
int m, n, res = 0;
char pr;
bool used[maxn];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d %c", &n, &m, &pr);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf(" %c", &cur[i][j]);

    for(int i = 0; i < maxn; ++i)used[i] = false;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j<= m; ++j)
            if(cur[i][j] == pr)
            used[int(cur[i - 1][j])] = used[int(cur[i + 1][j])] = used[int(cur[i][j - 1])] = used[int(cur[i][j + 1])] = true;

    for(int i = 1; i < maxn; ++i)if(char(i) != pr && char(i) != '.' && used[i])++res;

    printf("%d\n", res);

    return 0;
}