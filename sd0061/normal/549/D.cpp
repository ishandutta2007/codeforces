#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 105;
int n , m;
char s[N][N];
int a[N][N];

void work() {
    int i , j;
    scanf("%d%d" , &n ,&m);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%s" , s[i] + 1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            a[i][j] = (s[i][j] == 'W' ? 1 : -1);
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            a[i][j] -= a[i + 1][j];
    for (j = 1 ; j <= m ; ++ j)
        for (i = 1 ; i <= n ; ++ i)
            a[i][j] -= a[i][j + 1];
    int res = 0;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 1 ; j <= m ; ++ j)
            res += !!a[i][j];
    cout << res << endl;
}

int main() {
    work();
    return 0;
}