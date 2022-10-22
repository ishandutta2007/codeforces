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
#define foreach(it , h) for (typeof((h).begin()) it = (h).begin() ; it != (h).end() ; ++ it)
const int N = 105;
int n , m;
int f[N] , p[N] , tot , W[65];
int a[N] , F[N][1 << 17] , pre[N][1 << 17] , oh[N][1 << 17];

void print(int i , int j) {
    if (i == 0)
        return;
    print(i - 1, pre[i][j]);
    printf("%d " , oh[i][j]);
}

void work() {
    int i , j , k , l , x , y;
    for (i = 2 ; i * i <= 60 ; ++ i) if (!f[i])
        for (j = i * i ; j <= 60 ; j += i) f[j] = 1;
    for (i = 2 ; i <= 60 ; ++ i)
        if (!f[i]) p[tot ++] = i;
    for (i = 1 ; i <= 60 ; ++ i)
        for (j = 0 ; j < tot ; ++ j)
            if (i % p[j] == 0)
                W[i] |= 1 << j;
    //cout << tot << endl;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    memset(F , 63 , sizeof(F));
    F[0][0] = 0;
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < 1 << tot ; ++ j) {
            if (F[i][j] < 0) continue;
            for (k = 1 ; k <= 60 ; ++ k) {
                if ((~j & W[k]) != W[k])
                    continue;
                if (F[i][j] + abs(k - a[i + 1]) < F[i + 1][j | W[k]]) {
                    F[i + 1][j | W[k]] = F[i][j] + abs(k - a[i + 1]);
                    pre[i + 1][j | W[k]] = j;
                    oh[i + 1][j | W[k]] = k;
                }
            }
        }
    int res = 1 << 30;
    for (i = 0 ; i < 1 << 17 ; ++ i)
        res = min(res , F[n][i]);
    //cout << res << endl;
    for (i = 0 ; i < 1 << 17 ; ++ i)
        if (F[n][i] == res) {
            print(n , i);
            break;
        }
}

int main(){
   // freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}