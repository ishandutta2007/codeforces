#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 35;

int n , K , a[N];
double f[2][N][N];

void work() {
    int i , j , k , x , y;
    cin >> n >> K;
    for (i = 0 ; i < n ; ++ i)
        cin >> a[i];
    int cur = 0 , nxt = 1;
    for (i = 0 ; i < n ; ++ i)
        for (j = i + 1 ; j < n ; ++ j) {
            if (a[i] > a[j])
                ++ f[0][i][j];
            else
                ++ f[0][j][i];
        }
    int m = n * (n + 1) / 2;
    for (k = 0 ; k < K ; ++ k) {
        memset(f[nxt] , 0 , sizeof(f[nxt]));
        for (i = 0 ; i < n ; ++ i)
            for (j = 0 ; j < n ; ++ j) {
                if (i == j) continue;
                double delta = f[cur][i][j] / m;
                for (x = 0 ; x < n ; ++ x)
                    for (y = x ; y < n ; ++ y) {
                        int ii = i , jj = j;
                        if (x <= ii && ii <= y)
                            ii = x + y - ii;
                        if (x <= jj && jj <= y)
                            jj = x + y - jj;
                        f[nxt][ii][jj] += delta;
                    }
            }
        swap(nxt , cur);
    }
    double res = 0;
    for (i = 0 ; i < n ; ++ i)
        for (j = i ; j < n ; ++ j)
            res += f[cur][i][j];
    printf("%.15f\n" , res);
}

int main() {
//    freopen("1" , "r" , stdin);
    work();
    return 0;
}