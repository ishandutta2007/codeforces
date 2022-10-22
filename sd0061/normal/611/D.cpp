#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 5005;
const int Q = 1e9 + 7;
int n , f[N][N] , h[N] , LCP[N][N];
char str[N];

void add(int &A , int B) {
    A += B;
    if (A >= Q)
        A -= Q;
}

bool cmp(int i , int j , int l) {
    if (j + l - 1 > n)
        return 0;
    if (LCP[i][j] >= l)
        return 0;
    return str[j + LCP[i][j]] > str[i + LCP[i][j]];
}

int main() {
    scanf("%d%s" , &n , str + 1);
    for (int i = n ; i > 0 ; -- i)
        for (int j = n ; j >= i ; -- j) {
            if (str[i] == str[j])
                LCP[i][j] = LCP[i + 1][j + 1] + 1;
            else
                LCP[i][j] = 0;
        }
    if (str[1] == '0') {
        puts("0");
        return 0;
    }
    for (int i = 1 ; i <= n ; ++ i)
        f[1][i] = 1;
    for (int j = 1 ; j <= n ; ++ j) {
        for (int i = 1 ; i + j - 1 <= n ; ++ i) {
            if (str[i] == '0') {
                f[i][j] = 0;
                continue;
            }
            //printf("%d %d : %d\n" , i , j , f[i][j]);
            add(f[i][j] , h[i]);
            if (cmp(i , i + j , j))
                add(f[i + j][j] , f[i][j]);
        }
        for (int i = 1 ; i + j - 1 <= n ; ++ i) {
            add(h[i + j] , f[i][j]);
        }
    }
    int res = 0;
    for (int i = 1 ; i <= n ; ++ i)
        add(res , f[i][n - i + 1]);
    cout << res << endl;
    return 0;
}