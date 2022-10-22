#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 505;
const int Q = 1e9 + 7;

int n , a[N];


void work() {
    int i , j , k , x , y;
    scanf("%d",&n);
    y = 0;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&x);
        x -= y;
        int cnt = 0;
        //printf("*%d\n" , x);
        for (j = 0 ; j <= 500 ; ++ j) {
            cnt += a[j];
            if (a[j] < 9) {
                int L = 1 - cnt + a[j];
                int R = 9 * (j + 1) - cnt;
                if (L <= x && x <= R) {
                    int tmp = -cnt + a[j] + 1;
                    for (k = 0 ; k < j ; ++ k) {
                        int z = min(x - tmp , 9);
                        a[k] = z , tmp += z;
                    }
                    a[j] ++;
                    a[j] += x - tmp;
                    break;
                }
            }
        }
        y += x;
        for (j = 500 ; j >= 0 && !a[j] ; -- j);
        for ( ; j >= 0 ; -- j) printf("%d" , a[j]);
        puts("");
    }
}

int main() {
    work();
    return 0;
}