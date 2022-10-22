#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <cassert>
#include <sstream>
#include <set>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
const int N = 4005;
const int Q = 1e9 + 7;
int n;
int f[N] , g[N] , C[N][N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i <= n ; ++ i) {
        C[i][0] = 1;
        for (int j = 1 ; j <= i ; ++ j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Q;
        }
    }
    g[0] = 1 , f[0] = 0;
    f[1] = 1 , g[1] = 1;
    for (int i = 2 ; i <= n ; ++ i) {
        f[i] = (g[i - 1] + f[i - 1]) % Q;
        for (int j = 0 ; j < i ; ++ j) {
            f[i] += (LL)C[i - 1][j] * f[i - 1 - j] % Q;
            f[i] %= Q;
        }
        g[i] = 0;
        for (int j = 0 ; j < i ; ++ j) {
            g[i] += (LL)C[i - 1][j] * g[i - 1 - j] % Q;
            g[i] %= Q;
        }
        //cout << f[i] << ' ' << g[i] << endl;
    }
    cout << f[n] << endl;
    return 0;
}