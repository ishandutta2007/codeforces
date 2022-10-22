#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
const int N = 505;
typedef long long LL;
using namespace std;
int n , T , a[N];
int c[N] , cnt[N];
int f[N * N];
void work() {
    scanf("%d%d" , &n , &T);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%d" , &a[i]);
        ++ cnt[a[i]];
    }
    int m = 0;
    int res = 0 , q;
    for (int k = 1 ; k <= min(T , 1000) ; ++ k) {
        int delta = res;
        for (int i = 0 ; i < n ; ++ i) {
            int x = a[i];
            for (int j = x ; j > 0 ; j -= j & -j)
                f[m] = max(f[m] , c[j]);
            ++ f[m];
            for (int j = x ; j < N ; j += j & -j)
                c[j] = max(c[j] , f[m]);
            res = max(res , f[m]);
            ++ m;
        }
        q = res - delta;
        delta = res;
    }
    res += max(0 , T - 1000) * q;
    printf("%d\n" , res);
}


int main() {
    work();
    return 0;
}