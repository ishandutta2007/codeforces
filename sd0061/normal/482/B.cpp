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
#include <cctype>
using namespace std;
typedef long long LL;

const int N = 100005;
int n , m;
int cnt[30][N];
int L[N] , R[N] , Q[N];

int main() {
    int i , j;
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d%d%d",&L[i] , &R[i] , &Q[i]);
        for (j = 0 ; j < 30 ; ++ j)
            if (Q[i] >> j & 1) {
                ++ cnt[j][L[i]];
                -- cnt[j][R[i] + 1];
            }
    }
    for (j = 0 ; j < 30 ; ++ j) {
        for (i = 1 ; i <= n ; ++ i)
            cnt[j][i] += cnt[j][i - 1];
        for (i = 1 ; i <= n ; ++ i)
            cnt[j][i] = cnt[j][i - 1] + !!cnt[j][i];
    }
    bool flag = 0;
    for (i = 1 ; i <= m ; ++ i) {
        for (j = 0 ; j < 30 ; ++ j)
            if (~Q[i] >> j & 1) {
                if (cnt[j][R[i]] - cnt[j][L[i] - 1] == R[i] - L[i] + 1)
                    flag = 1;
            }
    }
    if (flag)
        puts("NO");
    else {
        puts("YES");
        for (i = 1 ; i <= n ; ++ i) {
            int x = 0;
            for (j = 0 ; j < 30 ; ++ j)
                x |= (cnt[j][i] - cnt[j][i - 1]) << j;
            printf("%d%c" , x , " \n"[i == n]);
        }

    }
    return 0;
}