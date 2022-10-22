#include <bits/stdc++.h>
using namespace std;
const int N = 10005;

int n , m , q , a[105][105];
int t[N] , x[N] , y[N] , z[N];
int main() {
    
    scanf("%d%d%d" , &n , &m , &q);
    for (int i = 0 ; i < q ; ++ i) {
        scanf("%d%d" , &t[i] , &x[i]);
        if (t[i] == 3) {
            scanf("%d%d" , &y[i] , &z[i]);
        }
        -- x[i] , -- y[i];
    }
    for (int i = q - 1 ; i >= 0 ; -- i) {
        if (t[i] == 3) {
            a[x[i]][y[i]] = z[i];
        } else if (t[i] == 1) {
            int w = a[x[i]][m - 1];
            for (int j = m - 1 ; j > 0 ; -- j) {
                a[x[i]][j] = a[x[i]][j - 1];
            }
            a[x[i]][0] = w;
        } else {
            int w = a[n - 1][x[i]];
            for (int j = n - 1 ; j > 0 ; -- j) {
                a[j][x[i]] = a[j - 1][x[i]];
            }
            a[0][x[i]] = w;
        }
    }
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < m ; ++ j) {
            printf("%d%c", a[i][j] , " \n"[j + 1 == m]);
        }
    }
}