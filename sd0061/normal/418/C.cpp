#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <utility>
#include <map>
typedef long long LL;
using namespace std;
#define N 105
int n , m;
const int W = 10;
int a[N][N] , R[N] , C[N];

bool sq(LL x) {
    LL y = sqrt(x);
    if (y * y == x) return 1;
    -- y;
    if (y * y == x) return 1;
    ++ y;
    if (y * y == x) return 1;
    return 0;
}

bool dfs(int k) {
    if (k == n * m)
        return 1;
    if (a[k / m][k % m]) {
        int i = a[k / m][k % m];
        R[k / m] += i * i;
        C[k % m] += i * i;
        if (dfs(k + 1)) return 1;
        R[k / m] -= i * i;
        C[k % m] -= i * i;
        return 0;
    }
    int x = k / m , y = k % m;
    for (int i = 1 ; i <= W ; ++ i) {

        if (k % m == m - 1) {
            if (!sq(R[k / m] + i * i)) continue;
        }
        if (k / m == n - 1) {
            if (!sq(C[k % m] + i * i)) continue;
        }

        a[k / m][k % m] = i;
        R[k / m] += i * i;
        C[k % m] += i * i;
        if (dfs(k + 1)) return 1;
        R[k / m] -= i * i;
        C[k % m] -= i * i;
        a[k / m][k % m] = 0;
    }
}

void work()
{
    memset(R , 0 , sizeof(R));
    memset(C , 0 , sizeof(C));
    memset(a , 0 , sizeof(a));
    if (n <= 5 && m <= 5) {
        dfs(0);
        for (int i = 0 ; i < n ; ++ i) {
            for (int j = 0 ; j < m ; ++ j) {
                printf("%d%c" , a[i][j] , " \n"[j + 1 == m]);
            }
        }
        return;
    }
    int i , j;
    int E = 100;
    for (i = 0 ; i < n - 2 ; ++ i)
        for (j = 0 ; j < m - 2 ; ++ j)
            a[i][j] = 1;

    for (int R = 1 ; R <= E ; ++ R) {
        for (int RR = 1; RR <= E ; ++ RR) {
            if (!sq(m - 2 + R * R + RR * RR)) continue;
            for (int C = 1 ; C <= E ; ++ C) {
                for (int CC = 1 ; CC <= E ; ++ CC) {
                    if (!sq(n - 2 + C * C + CC * CC)) continue;
                    for (int q1 = 1 ; q1 <= E ; ++ q1) {
                        for (int q2 = 1 ; q2 <= E ; ++ q2) {
                            if (!sq((m - 2) * C * C + q1 * q1 + q2 * q2)) continue;
                            for (int q3 = 1 ; q3 <= E ; ++ q3) {
                                if (!sq((n - 2) * R * R + q1 * q1 + q3 * q3)) continue;
                                for (int q4 = 1 ; q4 <= E ; ++ q4) {
                                    if (!sq((n - 2) * RR * RR + q4 * q4 + q2 * q2)) continue;
                                    if (!sq((m - 2) * CC * CC + q4 * q4 + q3 * q3)) continue;
                                    for (i = 0 ; i < n - 2 ; ++ i)
                                        a[i][m - 2] = R , a[i][m - 1] = RR;
                                    for (i = 0 ; i < m - 2 ; ++ i)
                                        a[n - 2][i] = C , a[n - 1][i] = CC;
                                    a[n - 2][m - 2] = q1;
                                    a[n - 1][m - 2] = q3;
                                    a[n - 2][m - 1] = q2;
                                    a[n - 1][m - 1] = q4;
                                    goto print;

                                }
                            }
                        }

                    }

                }
            }

        }


    }

    {
            print:;
        for (int i = 0 ; i < n ; ++ i) {
            for (int j = 0 ; j < m ; ++ j) {
                printf("%d%c" , a[i][j] , " \n"[j + 1 == m]);
            }
        }
    }
}

int main()
{
    //freopen("~input.txt" , "r" , stdin);
//while (scanf("%d",&n) , n)
    while (cin >> n >> m)
        work();
    return 0;
}