#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>
using namespace std;
typedef long long LL;
const int N = 300005;

int n , m;
int a[N] , b[N] ,  c[N];
bool f[N] ; 

void check(int i) {
    if (i < 1 || i == n) return;
    if (!f[i]) {
        if (b[i] > b[i + 1]) {
            f[i] = 1;
            for (int j = i ; j <= n ; j += j & -j)
                ++ c[j];
        }
    } else {
        if (b[i] < b[i + 1]) {
            f[i] = 0;
            for (int j = i ; j <= n ; j += j & -j)
                -- c[j];
        }    
    }
}

void work() {
    scanf("%d" , &n);
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }
    for (int i = 1 ; i < n ; ++ i)
        check(i);
    scanf("%d" , &m);
    while (m --) {
        int i , x , y;
        scanf("%d%d%d" , &i , &x , &y);
        if (i == 1) {
            int res = 1;
            for (int j = y - 1 ; j > 0 ; j -= j & -j)
                res += c[j];
            for (int j = x - 1 ; j > 0 ; j -= j & -j)
                res -= c[j];
            printf("%d\n" , res);
        } else {
            swap(a[x] , a[y]);
            b[a[x]] = x , b[a[y]] = y;
            check(a[x] - 1);
            check(a[x]);
            check(a[y] - 1);
            check(a[y]);            
        }
    }
}

int main() {
    work();
    return 0;
}