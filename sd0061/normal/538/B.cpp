#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 1000005;

int f[N] , pre[N];
int a[100] , n , m;

void dfs(int x) {
    if (x > n)
        return;
    a[m ++] = x;
    dfs(x * 10);
    dfs(x * 10 + 1);    
}

void work() {
    int i , j , k;
    cin >> n;
    dfs(1);
    memset(f , 0x3f , sizeof(f));
    f[0] = 0;
    for (i = 0 ; i < m ; ++ i) {
        for (j = 0 ; j <= n ; ++ j) {
            if (j >= a[i] && f[j] > f[j - a[i]] + 1) {
                f[j] = f[j - a[i]] + 1;
                pre[j] = a[i];
            }              
        }
    }
    printf("%d\n" , f[n]);
    while (n > 0)
        printf("%d " , pre[n]) , n -= pre[n];       
}

int main() {
    work();
    return 0;
}