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
const int N = 2005;
const int Q = 1e9 + 7;

int n , h , a[N];
int f[N][N];

void add(int& A , int B) {
    A += B;
    if (A >= Q)
        A -= Q;
}

void work() {
    int i , j;
    scanf("%d%d",&n,&h);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    f[0][0] = 1 , a[0] = h;
    for (i = 0 ; i < n ; ++ i) {
        for (j = 0 ; j <= 2000 ; ++ j) {
            if (f[i][j] && a[i] + j == h) {
                add(f[i + 1][j] , f[i][j]);
                if (j + 1 <= 2000)
                    add(f[i + 1][j + 1] , f[i][j]);
                if (j) {
                    add(f[i + 1][j - 1] , (LL)f[i][j] * j % Q);
                    add(f[i + 1][j] , (LL)f[i][j] * j % Q);
                }
            }
        }
    }
    int res = 0;
    if (a[n] == h) {
        add(res , f[n][0]);
    }
    if (a[n] + 1 == h) {
        add(res , f[n][1]);
    }
    printf("%d\n" , res);
}

int main() {
    work();
    return 0;
}