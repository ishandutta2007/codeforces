#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 105
int n , m , K;
int a[N][N];

void work() {
    int i , j , k ;
    scanf("%d%d%d",&n,&m,&K);
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < m ; ++ j)
            scanf("%d",&a[i][j]);
    if (n < m) {
        for (i = 0 ; i < m ; ++ i)
            for (j = i + 1 ; j < m ; ++ j)
                swap(a[i][j] , a[j][i]);
        swap(n , m);
    }
    if (n > K) {
        int ans = 1 << 30;
        for (k = 0 ; k < n ; ++ k) {
            int sum = 0;
            for (i = 0 ; i < n ; ++ i) {
                int x = 0 , y = 0;
                for (j = 0 ; j < m ; ++ j) {
                    x += (a[i][j] != a[k][j]);
                    y += (a[i][j] == a[k][j]);
                }
                sum += min(x , y);
            }
            ans = min(ans , sum);
        }
        if (ans > K)
            ans = -1;
        printf("%d\n" , ans);
        return;
    }
    int ans = 1 << 30;
    for (k = 0 ; k < 1 << n ; ++ k) {
        int sum = 0;
        for (i = 0 ; i < m ; ++ i) {
            int x = 0 , y = 0;
            for (j = 0 ; j < n ; ++ j) {
                x += (a[j][i] != (k >> j & 1));
                y += (a[j][i] == (k >> j & 1));
            }
            sum += min(x , y);
        }
        ans = min(ans , sum);
    }
    if (ans > K)
        ans = -1;
    printf("%d\n" , ans);
}

int main(){
    work();
    return 0;
}