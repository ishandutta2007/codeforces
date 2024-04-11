#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cctype>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 200005;

int n;
char a[N];
int f[N][2];
int main() {

    scanf("%d%s" , &n , a);    
    for (int i = 0 ; i < n ; ++ i)
        a[i] -= '0';
    memset(f , 0xC0 , sizeof(f));
    f[0][0] = f[0][1] = 0;
    for (int i = 0 ; i < n ; ++ i)
        for (int j = 0 ; j < 2 ; ++ j) {
            f[i + 1][j] = max(f[i + 1][j] , f[i][j]);
            if (a[i] == (j ^  1))
                f[i + 1][j ^ 1] = max(f[i + 1][j ^ 1] , f[i][j] + 1);
        }
    for (int i = 0 ; i < n ; ++ i)
        for (int j = 0 ; j < 2 ; ++ j) {
            f[i + 1][j] = max(f[i + 1][j] , f[i][j]);
            if (a[i] == j)
                f[i + 1][j ^ 1] = max(f[i + 1][j ^ 1] , f[i][j] + 1);
        }
    for (int i = 0 ; i < n ; ++ i)
        for (int j = 0 ; j < 2 ; ++ j) {
            f[i + 1][j] = max(f[i + 1][j] , f[i][j]);
            if (a[i] == (j ^  1))
                f[i + 1][j ^ 1] = max(f[i + 1][j ^ 1] , f[i][j] + 1);
        }
    cout << max(f[n][0], f[n][1]) << endl;
    return 0;

}