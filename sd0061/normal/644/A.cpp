#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 205;

int n , a , b , g[N][N];

int main() {
    cin >> n >> a >> b;
    int x = 1 , y = 2;
    for (int i = 1 ; i <= a ; ++ i) {
        for (int j = 1 ; j <= b ; ++ j) {
            if (((i + j) & 1) && x <= n) {
                g[i][j] = x;
                x += 2;
            }
            if ((~(i + j) & 1) && y <= n) {
                g[i][j] = y;
                y += 2;
            }            
        }
    }
    if (x > n && y > n) {
        for (int i = 1 ; i <= a ; ++ i)
            for (int j = 1 ; j <= b ; ++ j)
                printf("%d%c" , g[i][j] , " \n"[j == b]);
        return 0;
    }
    memset(g , 0 , sizeof(g));
    x = 1 , y = 2;
    for (int i = 1 ; i <= a ; ++ i) {
        for (int j = 1 ; j <= b ; ++ j) {
            if ((~(i + j) & 1) && x <= n) {
                g[i][j] = x;
                x += 2;
            }
            if (((i + j) & 1) && y <= n) {
                g[i][j] = y;
                y += 2;
            }            
        }
    }
    if (x > n && y > n) {
        for (int i = 1 ; i <= a ; ++ i)
            for (int j = 1 ; j <= b ; ++ j)
                printf("%d%c" , g[i][j] , " \n"[j == b]);
        return 0;
    }
    puts("-1");
    return 0;
}