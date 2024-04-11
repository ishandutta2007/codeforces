#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef long long LL;

char g[10][10];

int main() {
    for (int i = 1 ; i <= 8 ; ++ i)
        scanf("%s" , g[i] + 1);
    int t1 = 1 << 30 , t2 = 1 << 30;
    for (int i = 1 ; i <= 8 ; ++ i)
        for (int j = 1 ; j <= 8 ; ++ j) {

            if (g[i][j] == 'W') {
                int k;
                for (k = 1 ; k < i ; ++ k)
                    if (g[k][j] != '.')
                        break;
                if (k >= i)
                    t1 = min(t1 , i - 1);
            }
            if (g[i][j] == 'B') {
                int k;
                for (k = i + 1 ; k <= 8 ; ++ k)
                    if (g[k][j] != '.')
                        break;
                if (k > 8)
                    t2 = min(t2 , 8 - i);
            }           
        }
    if (t1 <= t2)
        puts("A");
    else
        puts("B");
    return 0;
}