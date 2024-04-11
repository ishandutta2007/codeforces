#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 5005
char s[N] , t[N];
int n , m , fs[N][N] , ft[N][N] , LCP[N][N];
int LS[N] , LT[N];

void work() {
    int i , j , x , y , z;
    scanf("%s%s" , s + 1 , t + 1);
    n = strlen(s + 1) , m = strlen(t + 1);
    for (i = n ; i >= 1 ; -- i)
        for (j = n ; j >= 1 ; -- j) {
            if (s[i] == s[j])
                fs[i][j] = fs[i + 1][j + 1] + 1;
            else
                fs[i][j] = 0;
        }
    for (i = 1 ; i <= n ; ++ i) {
        x = 0;
        for (j = 1 ; j <= n ; ++ j)
            if (i != j)
                x = max(x , fs[i][j]);
        LS[i] = x + 1;
    }
    for (i = m ; i >= 1 ; -- i)
        for (j = m ; j >= 1 ; -- j) {
            if (t[i] == t[j])
                ft[i][j] = ft[i + 1][j + 1] + 1;
            else
                ft[i][j] = 0;
        }
    for (i = 1 ; i <= m ; ++ i) {
        x = 0;
        for (j = 1 ; j <= m ; ++ j)
            if (i != j)
                x = max(x , ft[i][j]);
        LT[i] = x + 1;
    }
    int ans = 1 << 30;
    for (i = n ; i >= 1 ; -- i)
        for (j = m ; j >= 1 ; -- j) {
            if (s[i] == t[j]) {
                LCP[i][j] = LCP[i + 1][j + 1] + 1;
                if (LCP[i][j] >= LS[i] && LCP[i][j] >= LT[j])
                    ans = min(ans , min(LCP[i][j] , max
                                        (LS[i] , LT[j])));
            }
            else
                LCP[i][j] = 0;
        }
    if (ans == 1 << 30)
        ans = -1;
    printf("%d\n" , ans);
}

int main()
{
    work();
    return 0;
}