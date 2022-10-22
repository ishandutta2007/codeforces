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
const int N = 5005;
int n , m , k , a[N];
LL f[N][N] , s[N] ;
void work() {
    int i , j;
    cin >> n >> m >> k;
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    memset(f , 0xC0 , sizeof(f));
    f[0][0] = 0;
    for (i = 1 ; i <= n ; ++ i)
        for (j = 0 ; j <= k ; ++ j) {
            f[i][j] = max(f[i][j] , f[i - 1][j]);
            if (i - m >= 0 && j)
                f[i][j] = max(f[i][j] , f[i - m][j - 1] + s[i] - s[i - m]);
        }
    cout << f[n][k] << endl;
}

int main() {
    work();
    return 0;
}