#include <bits/stdc++.h>
using namespace std;

int n , m , a[21][21];

bool check(int b[]) {
    for (int i = 1 ; i <= m ; ++ i) {
        if (b[i] != i) {
            return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%d%d" , &n , &m);
    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= m ; ++ j) {
            scanf("%d" , &a[i][j]);
        }
    }
    for (int x = 1 ; x <= m ; ++ x) {
        for (int y = x ; y <= m ; ++ y) {
            bool flag = 1;
            for (int i = 1 ; i <= n ; ++ i) {
                bool pa = 0;
                for (int j = 1 ; j <= m && !pa ; ++ j) {
                    for (int k = j ; k <= m && !pa ; ++ k) {
                        swap(a[i][j] , a[i][k]);
                        swap(a[i][x] , a[i][y]);
                        if (check(a[i])) {
                            pa = 1;
                        }
                        swap(a[i][x] , a[i][y]);
                        swap(a[i][j] , a[i][k]);

                        swap(a[i][x] , a[i][y]);
                        swap(a[i][j] , a[i][k]);
                        if (check(a[i])) {
                            pa = 1;
                        }
                        swap(a[i][j] , a[i][k]);
                        swap(a[i][x] , a[i][y]);
                    }
                }
                if (!pa) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}