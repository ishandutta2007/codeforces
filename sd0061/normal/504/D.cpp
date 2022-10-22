#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

const int N = 2000;
int n;
bitset<N> a[N] , mask[N];
char str[N];
int base[N];

int main() {
    int i , j , k , x;
    memset(base , -1 , sizeof(base));
    scanf("%d", &n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , str);
        int len = strlen(str);
        for (j = 0 ; j < len ; ++ j)
            str[j] = str[j] - '0';
        reverse(str , str + len);
        for (j = 0 ; j < N ; ++ j) {
            for (k = len - 1 , x = 0; k >= 0 ; -- k) {
                str[k] += x * 10;
                x = str[k] & 1;
                str[k] >>= 1;
            }
            a[i][j] = x;
            while (len > 1 && !str[len - 1])
                -- len;
        }
        for (j = 0 ; j < N ; ++ j) {
            if (a[i][j]) {
                if (!~base[j]) {
                    mask[i][i] = 1;
                    base[j] = i;
                    break;
                }
                a[i] ^= a[base[j]];
                mask[i] ^= mask[base[j]];
            }
        }
        if (j < N) {
            puts("0");
        } else {
            printf("%d" , mask[i].count());
            for (j = 0 ; j < i ; ++ j)
                if (mask[i][j])
                    printf(" %d" , j);
            puts("");
        }
    }
    return 0;
}