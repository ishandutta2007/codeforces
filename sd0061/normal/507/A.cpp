#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 105;

int n , m , a[N];

int f[N][10001];

void print(int x , int y) {
    if (x < 1) return;
    if (f[x][y] == f[x - 1][y])
        print(x - 1 , y);
    else {
        printf("%d " , x);
        print(x - 1 , y - a[x]);
    }
}

void work() {
    int i , j , x;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d",&x);
        a[i] = x;
        for (j = m ; j >= x ; -- j)
            f[i][j] = max(f[i - 1][j] , f[i - 1][j - x] + 1);
        for (; j >= 0 ; -- j)
            f[i][j] = f[i - 1][j];
    }
    printf("%d\n" , f[n][m]);
    print(n , m);
}

int main()
{
    work();
    return 0;
}