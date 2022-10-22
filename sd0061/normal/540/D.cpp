#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 105;
double f[N][N][N];

double F(int a , int b , int c) {
    memset(f , 0 , sizeof(f));
    for (int i = 1 ; i <= a ; ++ i)
        f[i][0][0] = 1;
    for (int i = 1 ; i <= a ; ++ i)
        for (int j = 0 ; j <= b ; ++ j)
            for (int k = 0 ; k <= c ; ++ k) {
                if (j + k == 0) continue;
                int n = i + j + k , m = n * (n - 1) / 2;
                double x = 0;
                if (i && j)
                    x += 1.0 * i * j / m * f[i][j - 1][k];
                if (j && k)
                    x += 1.0 * j * k / m * f[i][j][k - 1];
                if (k && i)
                    x += 1.0 * k * i / m * f[i - 1][j][k];
                double y = 1.0 * (i * j + i * k + j * k) / m;
                f[i][j][k] = x / y;
            }
    return f[a][b][c];                
}

int main() {
    int a , b , c;
    scanf("%d%d%d" , &a , &b , &c);
    printf("%.10f %.10f %.10f\n" , F(a , b , c) , F(b , c , a) , F(c , a , b));
    return 0;
}