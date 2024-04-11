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
const int N = 1005;
int a[N][N];
void work() {
    int n , k , d , i , j;
    cin >> n >> k >> d;
    for (i = 0 ; i < n ; ++ i) {
        int x = i;
        for (j = 0 ; j < d ; ++ j)
            a[j][i] = x % k , x /= k;
        if (x > 0)
            break;
    }
    if (i < n)
        puts("-1");
    else {
        for (i = 0 ; i < d ; ++ i) {
            for (j = 0 ; j < n ; ++ j)
                printf("%d%c" , a[i][j] + 1 , " \n"[j + 1 == n]);
        }
    }

}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}