#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , S;
bool f[105][1000];

void work () {
    cin >> n >> S;
    if (n == 1 && S == 0) {
        puts("0 0");
        return;
    }
    int i , j , k;
    f[n][S] = 1;
    for (i = n - 1 ; i >= 0 ; -- i) {
        for (j = 0 ; j <= S ; ++ j) {
            for (k = i ? 0 : 1 ; k < 10 && j + k <= S ; ++ k) {
                f[i][j] |= f[i + 1][j + k];
            }
        }
    }
    if (!f[0][0]) {
        puts("-1 -1");
    } else {
        i = 0 , j = 0;
        while (i < n) {
            for (k = i ? 0 : 1 ; k < 10 ; ++ k)
                if (f[i + 1][j + k]) {
                    ++ i , j += k;
                    putchar('0' + k);
                    break;
                }
        }
        putchar(' ');
        i = 0 , j = 0;
        while (i < n) {
            for (k = 9 ; k >= (i ? 0 : 1) ; -- k)
                if (f[i + 1][j + k]) {
                    ++ i , j += k;
                    putchar('0' + k);
                    break;
                }
        }
        puts("");
    }
}

int main() {
    work();
    return 0;
}